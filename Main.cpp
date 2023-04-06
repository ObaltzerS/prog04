#include "Item.h"
#include "ItemHashTable.h"
#include "ItemNode.h"
#include <iostream>

using namespace std;


int main() {
	ItemHashTable table;
	Item apples = Item(3, "apples", 45);
	Item bananas = Item(13, "banana", 4);
	if (table.insert(apples)) {
		cout << "inserted" << endl;
	}
	cout << table.isContains(3);
	//table.insert(bananas);
	//cout << table.isContains(3);


	return 0;
}