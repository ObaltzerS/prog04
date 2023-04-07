#include "Item.h"
//#include "ItemHashTableLinked.h"
#include "ItemHashTableLinear.h"
#include <iostream>

using namespace std;


int main() {
	ItemHashTableLinear table;
	//ItemHashTableLinked table;
	Item apples = Item(3, "apples", 45);
	Item bananas = Item(13, "banana", 4);
	
	cout << table.insert(bananas) << endl;
	cout << table.insert(apples) << endl;
	cout << table.isContains(3) << endl;
	cout << table.retrieve(13).getName() << endl;
	cout << table.retrieve(3).getName();

	return 0;
}