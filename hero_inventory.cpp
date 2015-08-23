#include <iostream>
#include <string>
#include <vector>

using namespace std;

class inventory
{
private:
	vector<string> items;
public:
	void addItem(string a) {items.push_back(a);}
	void removeLastItem() {items.pop_back();}
	void removeMiddleItem() {items.erase(items.begin()+1);};
	void listItems();
	int inventorySize() {return items.size();}
	void gotRobbed() {items.clear(); cout << "You were robbed of all of your possessions by a thief!\n\n";}
};	//class inventory

void inventory::listItems(void)
{
	cout << "listing total number of " << items.size() << " items in the inventory:\n";
	for(unsigned int i=0; i<items.size(); i++)
	{
		cout << items[i] << "\n";
	}
	cout << "\n";
}

int main(void)
{
	inventory a;
	a.addItem("durum");
	a.listItems();
	a.addItem("lahmacun");
	a.listItems();
	a.gotRobbed();
	a.listItems();
	a.addItem("pizza");
	a.addItem("doner");
	a.removeMiddleItem();
	a.listItems();
}
