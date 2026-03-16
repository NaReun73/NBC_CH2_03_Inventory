#pragma once
#include <iostream>
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
		std::cout << "인벤토리 총 크기 : " << capacity_ << std::endl;
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
		std::cout << "인베토리 사용량 : " << size_ << std::endl;
		return size_;
	}

	int GetCapacity() const
	{
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
};

