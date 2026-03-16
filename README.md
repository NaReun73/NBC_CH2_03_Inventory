# NBC_CH2_03_Inventory

<aside>

### 필수 구현 기능    

---

1. **데이터 보관함: Inventory<T> 클래스 설계**
    - [x]  **템플릿 클래스 선언**
        - 아이템, 무기, 포션 등 어떤 타입이든 담을 수 있게 만듭니다.
        - **클래스 이름**: `Inventory`
        - **템플릿**: `template <typename T>`를 사용하여 어떤 타입(`T`)의 데이터든 처리할 수 있도록 합니다.
    - [x]  **내부 멤버 변수 구성 (Private)**
        - `T* pItems_`: 아이템 객체들을 저장할 **동적 배열을 가리키는 포인터**입니다.
            - `new T[]`를 통해 메모리를 할당받습니다.
        - `int capacity_`: 인벤토리가 최대로 저장할 수 있는 공간의 크기입니다.
        - `int size_`: 현재 인벤토리에 저장된 아이템의 실제 개수입니다.

---

1. **탄생과 소멸: 생성자와 소멸자**
    - [x]  **생성자 구현 : `Inventory(int capacity = 10)`**
        - 인벤토리 객체가 생성될 때 호출됩니다.
        - 매개변수로 용량(`capacity`)을 받습니다.
        (입력하지 않을 경우 기본 10으로 설정)
            - **예외처리 :** 유저가 용량을 0 이하로 입력하면, 최소 용량이 1은 되도록 자동으로 보정합니다.
        - `new T[capacity_]`를 통해 아이템을 저장할 메모리 공간을 힙(Heap) 메모리에 할당합니다.
    - [x]  **소멸자 관리 : `~Inventory()`**
        - 인벤토리 객체가 소멸될 때 (예: `main` 함수 종료 시) 자동으로 호출됩니다.
        - **메모리 누수 방지** : 객체가 사라질 때 `delete[] pItems_`를 실행하여 할당받은 메모리를 반납합니다.
        - 해제 후 포인터를 `nullptr`로 초기화하여 안전성을 높입니다.
        - 안전한 코드를 위해, 메모리 해제 후 포인터를 `nullptr`로 초기화합니다.

---

1. **인벤토리 조작 기능**
    - [x]  **아이템 추가 (`void AddItem(const T& item)`)**
        - 새로운 아이템을 인벤토리에 추가합니다.
        - 인벤토리에 여유 공간이 있을 때만 아이템을 저장하고 `size_`를 1 늘립니다.
        - 공간이 꽉 찼다면 "인벤토리가 꽉 찼습니다!"라는 경고를 띄웁니다.
    - [x]  **마지막 아이템 제거 (`void RemoveLastItem()`)**
        - 인벤토리의 가장 마지막에 추가된 아이템을 제거합니다.
        - 실제로 메모리를 지우는 것이 아니라, 아이템의 개수를 나타내는 `size_`를 1 감소시켜 마지막 아이템에 접근할 수 없도록 만듭니다.
        - 비어있을 때 제거를 시도하면 "인벤토리가 비어있습니다."라고 안내합니다.
    - [x]  **정보 조회 함수**
        - **`int GetSize() const`**: 현재 인벤토리의 크기(몇 개가 들었는지) 반환합니다.
        - **`int GetCapacity() const`**: 현재 인벤토리에 최대 용량을 반환합니다.

---

1. **목록 출력 기능**
    - [x]  **전체 출력 (`PrintAllItems`)**
        - 반복문(`for`)을 사용하여 0번부터 `size_ - 1`번까지의 모든 아이템 정보를 보여줍니다.
        - 각 아이템 객체의 `PrintInfo()` 멤버 함수를 호출합니다.
            
            ```cpp
            // 정보를 출력하는 멤버 함수
            void PrintInfo() const {
                cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
            }
            ```
            
        - 비어있다면 "비어있음"을 출력합니다.
</aside>

<aside>

### 도전 구현 기능

---

1. **데이터 안전하게 복사하기**
    - [x]  **복사 생성자 구현 (**`Inventory(const Inventory<T>& other);`**)**
        - 새로운 객체가 만들어지거나 초기화 될 때, 다른 객체의 데이터를 그대로 복사해옵니다.
        - 단순히 주소만 복사하는 것이 아니라, `new T[capacity_]`를 통해 **새로운 메모리 공간**을 만들고 내용을 하나씩 옮겨 담아야 합니다. (깊은 복사)
        
        ```cpp
        // 복사 생성자
        Inventory(const Inventory<T>& other) {
            capacity_ = other.capacity_;
            size_ = other.size_;
            pItems_ = new T[capacity_];
            for (int i = 0; i < size_; ++i) {
                pItems_[i] = other.pItems_[i];
            }
            cout << "인벤토리 복사 완료" << endl;
        }
        ```
        
    - [x]  **Assign(대입) 함수 구현 (**`void Assign(const Inventory<T>& other);`**)**
        - 이미 만들어진 객체에 다른 객체의 내용을 덮어씁니다.
        - 기존에 가지고 있던 메모리는 `delete[]`로 먼저 비워준 뒤, 새로운 공간을 만들어 복사해야 메모리 누수가 생기지 않습니다.

---

1. **인벤토리 자동 확장 (Resize)**
    - [x]  **Resize 멤버 함수 구현**
        - 새로운 크기(`newCapacity`)만큼의 새로운 메모리 공간을 할당합니다.
        - 기존에 들어있던 아이템들을 새 공간으로 모두 이사시킨 뒤, 낡은 메모리는 해제합니다.
    - [x]  **AddItem 기능 업그레이드**
        - 아이템을 넣으려는데 인벤토리가 꽉 찼다면?
        - 프로그램을 멈추지 말고 `Resize`를 호출하여 **기존 용량의 2배**로 공간을 늘린 후 아이템을 추가합니다.

---

1. **아이템 정렬 기능 (Sort)**
    - [x]  **비교 함수(`compareItemsByPrice`) 작성**
        - 클래스 외부에 두 아이템의 가격을 비교하는 함수를 만듭니다. (왼쪽 아이템 가격이 더 작으면 `true` 반환)
    - [x]  **SortItems 함수 구현**
        - 배열의 시작 주소(`pItems_`), 끝 지점(`pItems_ + size_`), 그리고 위에서 만든 비교 함수를 전달하여 **가격순(오름차순)**으로 정렬합니다.
        - C++ 표준 라이브러리인 `std::sort`를 활용합니다.
        - 정렬 기준 정의 : 클래스 외부에 별도로 작성된 비교 함수(`compareItemsByPrice`)를 `std::sort`에 전달합니다.
            
            ```cpp
            //두 Item 객체를 받아 가격을 기준으로 어떤 것이 먼저 와야 하는지 판단
            bool compareItemsByPrice(const Item& a, const Item& b) {
                return a.GetPrice() < b.GetPrice();
            }
            ```
            
</aside>





## 구현 중 발생한 문제점과 해결, 궁금한 점

<aside>

### 복사 생성자

---

**처음으로 복사 생성자를 호출할 때**

```cpp
Inventory<Item>* otheritemInventory(itemInventory);
//객체를 복사한 것이 아니라, 포인터(주소값)만 복사한 것
```

위 코드를 사용했을 때 복사 생성자가 실행되지 않았습니다.

포인터 변수끼리 주소값을 주고받는 것은 C++ 기본 자료형(int, float 등)의 복사와 같아서 클래스 내부의 복사 생성자를 건드리지 않습니다.

**수정 후**

```cpp
Inventory<Item>* otheritemInventory = new Inventory<Item>(*itemInventory);
// 실제 객체를 복사하여 새로운 힙메모리에 만듭니다.
```

`*itemInventory` 를 통해서 실제 객체에 접근합니다.

`new` 가 실행되면서 새로운 메모리 공간을 확보합니다.

인자로 객체가 넘어왔으므로, 복사 생성자가 실행됩니다.

</aside>

<aside>

### Assign() 함수 (대입 함수)

---

기존 인벤토리를 쓰기 때문에 delete[] 를 사용하여 공간을 비워주고 새로운 공간을 만들어줘야 합니다.

여기서 기존 인벤토리의 `capacity_` 와 `size_` 는 그대로 남아있기 때문에 

대입하는 인벤토리의 `capacity_` 와 `size_`를 따로 대입해줍니다. 

그 다음 기존 인벤토리에 다른 인벤토리의 정보를 대입합니다.

- **Assign() 코드**
    
    ```cpp
    // 이미 만들어진 객체에 다른 객체의 내용을 덮어쓰기
    void Assign(const Inventory<T>& other)
    {
    	if (this == &other)
    	{
    		std::cout << "같은 인벤토리 입니다." << std::endl;
    		return;
    	}
    
    	std::cout << "기존 인벤토리를 비웁니다." << std::endl;
    	delete[] pItems_;
    
    	std::cout << "대입 할 인벤토리의 정보를 가져옵니다." << std::endl;
    	pItems_ = new T[other.capacity_];
    	capacity_ = other.capacity_;
    	size_ = other.size_;
    
    	for (int i = 0; i < size_; ++i)
    	{
    		pItems_[i] = other.pItems_[i];
    	}
    
    	std::cout << "인베토리를 덮어 씌웠습니다." << std::endl;
    }
    ```
    
</aside>

<aside>

### Resize() 함수 (크기 재설정 함수)

---

<aside>

**기존 인벤토리의 `capacity_` 의 크기를 늘립니다.**

- 새로운 크기(`newCapacity`)만큼의 새로운 메모리 공간을 할당합니다.
    - 새로운 크기가 같으면 함수를 끝냅니다.
    - 새로운 크기가 현재 사용량보다 작으면 경고문을 출력하여 진행할지 취소할지 정합니다.
    - 진행할 시 `size_ = newcapacity` 를 해서 나머지는 버려집니다.
- **코드**
    
    ```cpp
    // 인벤토리 크기 재설정
    void Resize(int newcapacity)
    {
    	if (newcapacity == capacity_)
    	{
    		std::cout << "현재 크기랑 같습니다." << std::endl;
    		return;
    	}
    
    	T* newpItems_ = new T[newcapacity];
    
    	if (newcapacity < size_)
    	{
    		std::cout << "설정한 크기값이 현재 사용량보다 작아서 일부 아이템이 사라질수도 있습니다." << std::endl;
    		std::cout << "진행하겠습니까? 1.확인 2.취소" << std::endl;
    		
    		int num = 0;
    		std::cin >> num;
    		
    		if (num == 1)
    		{
    			size_ = newcapacity;
    		}
    		else
    		{
    			return;
    		}
    	}
    
    	for (int i = 0; i < size_; ++i)
    	{
    		newpItems_[i] = pItems_[i];
    	}
    
    	delete[] pItems_;
    
    	pItems_ = newpItems_;
    	capacity_ = newcapacity;
    }
    ```
    
</aside>

<aside>

**`AddItem()` 기능 업그레이드**

아이템을 넣을 공간이 없을 때 프로그램을 멈추지 않고 `Resize()` 함수를 호출하여 기존 크기를 2배로 늘리고 아이템을 다시 넣습니다.

- **AddItem() 코드**
    
    ```cpp
    // 인벤토리에 아이템 추가
    void AddItem(const T& item)
    {
    	if (size_ < capacity_)
    	{
    		pItems_[size_] = item;
    		size_++;
    	}
    	else
    	{
    		std::cout << "인벤토리가 꽉 찼습니다!" << std::endl;
    		std::cout << "인벤토리를 2배 늘립니다!" << std::endl;
    		Resize(capacity_ * 2);
    		pItems_[size_] = item;
    		size_++;
    	}
    }
    ```
    
</aside>

</aside>

<aside>

### std::sort()

---

<aside>

`#include <algorithm>` 을 적어주어야 합니다.

sort(start, end) 를 사용하여 범위 안에 있는 인자를 오름차순으로 정렬해줍니다.

- `sort(pItems_, pItems_ + size_);`
- `sort(v.begin(), v.end());`
- `sort(v.begin(), v.end(), compare);`    // 사용자 정의 함수
- `sort(v.begin(), v.end(), greater<자료형>());` // 내름차순(Descending order)
- `sort(v.begin(), v.end(), less<자료형>());`    // 오름차순(default = Ascending order)
</aside>

<aside>

`sort(v.begin(), v.end(), compare);` **에서** **compare 부분에 인자를 안 넣어줘도 되는 이유**

`std::sort`가 내부에서 `CompareItemsByPrice(pItems_[0], pItems_[1])`을 **스스로 호출**합니다.
만약 `CompareItemsByPrice(a, b)`라고 적어버리면, 그 함수를 **지금 당장 실행해서 나온 `true/false` 결과값**을 던져주는 꼴이 되어버려 정렬을 할 수 없게 됩니다.

</aside>

- **SortItems() 코드**
    
    ```cpp
    // Item.h
    // 클래스 외부에 선언
    bool CompareItemsByPrice(const Item& a, const Item& b);
    
    // Item.cpp
    bool CompareItemsByPrice(const Item& a, const Item& b)
    {
    	return a.GetPrice() < b.GetPrice();
    }
    
    // Inventory.h
    void SortItems()
    {
    	std::sort(pItems_, pItems_ + size_, CompareItemsByPrice);
    }
    ```
    
</aside>