#include "Item.h"
#include "Inventory.h"

int main(void)
{
	Inventory<Item>* itemInventory = new Inventory<Item>(5);

	itemInventory->AddItem(Item("검", 1000));
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	itemInventory->RemoveLastItem();
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	Inventory<Item>* otheritemInventory = new Inventory<Item>(*itemInventory);

	otheritemInventory->GetCapacity();
	otheritemInventory->GetSize();
	otheritemInventory->PrintAllItems();

	Inventory<Item>* itemInventory3 = new Inventory<Item>;
	itemInventory3->GetCapacity();
	itemInventory3->GetSize();
	itemInventory3->PrintAllItems();

	itemInventory3->Assign(*otheritemInventory);

	itemInventory3->GetCapacity();
	itemInventory3->GetSize();
	itemInventory3->PrintAllItems();

	delete itemInventory;
	delete otheritemInventory;
	delete itemInventory3;

	/*
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
	*/

	
	
	return 0;
}