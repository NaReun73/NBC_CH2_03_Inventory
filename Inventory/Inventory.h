#pragma once
#include <iostream>
#include <algorithm>
#include "Item.h"

template <typename T>
class Inventory
{
private:
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity = 10)
		: capacity_(capacity)
		, size_(0)
	{
		if (capacity <= 0)
		{
			capacity_ = 1;
		}

		//포인터를 담을 수 있는 배열 공간 할당(힙 메모리)
		pItems_ = new T[capacity_];
		std::cout << "인벤토리 크기 : " << capacity_ << std::endl;
	}

	Inventory(const Inventory<T>& other)
	{
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i)
		{
			pItems_[i] = other.pItems_[i];
		}

		std::cout << "인벤토리 복사 완료" << std::endl;
	}

	~Inventory()
	{
		delete[] pItems_;
		pItems_ = nullptr;
	}

	int GetSize() const
	{
		std::cout << "인벤토리 사용량 : " << size_ << std::endl;
		return size_;
	}

	int GetCapacity() const
	{
		std::cout << "인벤토리 크기 : " << capacity_ << std::endl;
		return capacity_;
	}

	// 인베토리에 아이템 넣기
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

	// 마지막 아이템 버리기
	void RemoveLastItem()
	{
		if (size_ > 0)
		{
			std::cout << "마지막 아이템을 버립니다." << std::endl;
			size_--;
			pItems_[size_].Clear();
			//pItems_[size_]->Clear();
		}
		else
		{
			std::cout << "인벤토리가 비어있습니다." << std::endl;
		}
	}

	void PrintAllItems()
	{
		if (size_ <= 0)
		{
			std::cout << "비어있음" << std::endl;
			return;
		}

		for (int i = 0; i < size_; ++i)
		{
			pItems_[i].PrintInfo();
			//pItems_[i]->PrintInfo();
		}
		
	}

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

		std::cout << "인벤토리를 덮어 씌웠습니다." << std::endl;
	}

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

	void SortItems()
	{
		std::sort(pItems_, pItems_ + size_, CompareItemsByPrice);
	}
};