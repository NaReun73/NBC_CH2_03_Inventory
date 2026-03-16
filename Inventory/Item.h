#pragma once
#include <string>

class Item
{
private:
	std::string name_;
	int price_;

public:
	Item();
	Item(const std::string& name, int price);
	const std::string& GetName() const;
	int GetPrice() const;
	void Clear();
	void PrintInfo() const;
};

bool CompareItemsByPrice(const Item& a, const Item& b);