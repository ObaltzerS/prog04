#include "Item.h"
#include "ItemHashTable.h"
#include "ItemNode.h"
#include <iostream>
using namespace std;
// constructor - initializes table to empty.
ItemHashTable::ItemHashTable() {
	ItemNode* buckets[NUMBER_OF_BUCKETS] = {NULL};
	/*for (int i = 0; i < NUMBER_OF_BUCKETS; i++) {
		buckets[i] = nullptr;
	}*/
}

// hashFunction
// pre-condition: receives an Item id
// post-condition: returns hash function that tells us the array index position
// within the fixed-sized array into which this Item will be stored.
int ItemHashTable::hashFunction(int id) const {
	// Compute hash function using the modulo operator
	int hashedID = (id % NUMBER_OF_BUCKETS);
	// return computed hash value
	return hashedID; // Placeholder return value so program compiles without
	// error.
}

// insert
// pre-condition: receives an Item data value that must have a positive ID
// value. post-condition: save the given Item into the hash table and return
// true if successful; else, false.
bool ItemHashTable::insert(const Item& V) {

	if (V.getId() > 0) {
		ItemNode* newNode = new ItemNode();
		newNode->data = V;
		ItemNode* current = buckets[hashFunction(V.getId())];


		if (current == NULL) {
			current = newNode;
			cout << current->data.id << endl; // debug
			cout << current->next << endl; // debug
			delete newNode;
			return true;
		}

		while (current->next != NULL) {
			current = current->next;

		}
		current->next = newNode;
		delete newNode;
		return true;
	}
	else {
		return false;
	}

}

// isContains
// pre-condition: receives an integer ID value. The integer ID is the
// unique integer Stock Keeping Unit number for a product.
// post-condition: return true if the hash table contains an Item with
// the given ID; else, return false.
bool ItemHashTable::isContains(int id) const {
	ItemNode* current = buckets[hashFunction(id)];
	while (current != NULL) {
		if (current->data.id == id) {
			cout << current->data.id;
			return true;
		}
		current = current->next;
	}
	return false;
}

// retrieve
// pre-condition: receives an integer ID value. The integer ID is the
// unique integer Stock Keeping Unit number for a product.
// post-condition: return Item matching the given ID.
// Item will contain invalid values of id -1 and name "undefined" and price of 0
// if not Item in the hash table has the given ID.
Item ItemHashTable::retrieve(int ID) {
	// Create default Item that has invalid ID, undefined name, and price of 0.
	Item empty = Item();
	//Item V = search(buckets[hashFunction(ID)], ID)->data;
	/*if (V.id == ID) {
		return V;
	}
	return empty;*/

	// Call hashFunction to find array index of bucket into
	// which an Item with the given unique id would be stored.
	// Check whether or not the Item in this bucket entry matches the given id.

	// If yes, then that is the Item to return;
	// otherwise, return the emptyItem to signal failed to retrieve.
	return empty;
}
