#include "Item.h"
#include "Inventory.h"

int main(void)
{
	Inventory<Item*> itemInventory(5);

	itemInventory.AddItem(new Item("검", 1000));
	itemInventory.GetSize();
	itemInventory.PrintAllItems();

	itemInventory.AddItem(new Item("목검", 100));
	itemInventory.AddItem(new Item("목검", 100));
	itemInventory.AddItem(new Item("목검", 100));
	itemInventory.AddItem(new Item("목검", 100));
	itemInventory.AddItem(new Item("목검", 100));
	itemInventory.GetSize();
	itemInventory.PrintAllItems();
				 
	itemInventory.RemoveLastItem();
	itemInventory.GetSize();
	itemInventory.PrintAllItems();

	/*
	Inventory<Item>* itemInventory2 = new Inventory<Item>(15);

	itemInventory2->AddItem(Item("검", 1000));
	itemInventory2->GetSize();
	itemInventory2->PrintAllItems();

	itemInventory2->AddItem(Item("목검", 100));
	itemInventory2->AddItem(Item("목검", 100));
	itemInventory2->AddItem(Item("목검", 100));
	itemInventory2->GetSize();
	itemInventory2->PrintAllItems();

	itemInventory2->RemoveLastItem();
	itemInventory2->GetSize();
	itemInventory2->PrintAllItems();

	delete itemInventory2;
	*/
	return 0;
}