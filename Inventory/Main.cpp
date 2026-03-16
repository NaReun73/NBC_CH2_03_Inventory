#include "Item.h"
#include "Inventory.h"

int main(void)
{
	std::cout << "-----인벤토리1 생성-----" << std::endl;
	Inventory<Item>* itemInventory = new Inventory<Item>(5);

	std::cout << "-----인벤토리 1-----" << std::endl;
	itemInventory->AddItem(Item("검", 1000));
	itemInventory->GetCapacity();
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->AddItem(Item("목검", 100));
	itemInventory->GetCapacity();
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	itemInventory->RemoveLastItem();
	itemInventory->GetSize();
	itemInventory->PrintAllItems();


	std::cout << "-----인벤토리 1을 복사해서 인벤토리 2 생성-----" << std::endl;
	Inventory<Item>* otheritemInventory = new Inventory<Item>(*itemInventory);

	std::cout << "-----인벤토리 2-----" << std::endl;
	otheritemInventory->GetCapacity();
	otheritemInventory->GetSize();
	otheritemInventory->PrintAllItems();
	otheritemInventory->RemoveLastItem();
	otheritemInventory->RemoveLastItem();
	otheritemInventory->PrintAllItems();

	std::cout << "-----인벤토리 1-----" << std::endl;
	itemInventory->PrintAllItems();

	std::cout << "-----인벤토리 1에 인벤토리 1 대입-----" << std::endl;
	itemInventory->Assign(*itemInventory);

	std::cout << "-----인벤토리 1에 인벤토리 2 대입-----" << std::endl;
	itemInventory->Assign(*otheritemInventory);

	std::cout << "-----인벤토리 1-----" << std::endl;
	itemInventory->GetCapacity();
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	itemInventory->AddItem(Item("대검", 1500));
	itemInventory->GetSize();
	itemInventory->PrintAllItems();

	std::cout << "-----인벤토리 2-----" << std::endl;
	otheritemInventory->PrintAllItems();


	std::cout << "-----기존 인벤토리 1의 크기-----" << std::endl;
	itemInventory->GetCapacity();
	std::cout << "-----인벤토리 1 크기 재설정-----" << std::endl;
	itemInventory->Resize(10);

	// 사용량이 전체 크기보다 클 경우
	//itemInventory->Resize(2);
	//itemInventory->GetCapacity();
	//itemInventory->PrintAllItems();

	itemInventory->Resize(20);
	itemInventory->GetCapacity();
	itemInventory->PrintAllItems();

	delete itemInventory;
	delete otheritemInventory;

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