#include "Item.h"
#include <iostream>

Item::Item()
	: name_("")
	, price_(0)
{

}

Item::Item(const std::string& name, int price)
	: name_(name)
	, price_(price)
{
	std::cout << "아이템 " << name_ << "을 획득했습니다." << std::endl;
}

const std::string& Item::GetName() const
{
	return name_;
}

int Item::GetPrice() const
{
	return price_;
}

void Item::Clear()
{
	name_ = "";
	price_ = 0;
}

void Item::PrintInfo() const
{
	std::cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << std::endl;
}

bool CompareItemsByPrice(const Item& a, const Item& b)
{
	return a.GetPrice() < b.GetPrice();
}