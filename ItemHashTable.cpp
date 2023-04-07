#include "Item.h"
#include "ItemHashTable.h"
#include "ItemNode.h"
#include <iostream>
using namespace std;

// constructor - initializes table to empty.
ItemHashTable::ItemHashTable() {
	this->buckets[NUMBER_OF_BUCKETS];

}


int ItemHashTable::hashFunction(int id) const {
	// Compute hash function using the modulo operator
	int hashedID = (id % NUMBER_OF_BUCKETS);
	// return computed hash value
	return hashedID; // Placeholder return value so program compiles without
	// error.
}


bool ItemHashTable::insert(Item& V) {

	if (V.getId() > 0) {
		Item* newNode = &V;

		if (buckets[hashFunction(V.getId())] == NULL) {
			buckets[hashFunction(V.getId())] = newNode;
			return true;
		}
		else {
			Item* current = buckets[hashFunction(V.getId())];
			while (current == NULL) {
				current = current->next;
			}
			current->next = newNode;
			return true;
		}
		return false;
	}

}

bool ItemHashTable::isContains(int id) const {


	Item* current = buckets[hashFunction(id)];
	while (current != NULL) {
		if (current->id == id) {
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
	Item empty = Item();

	Item* current = buckets[hashFunction(ID)];
	while (current != NULL) {
		if (current->id == ID) {
			return *current;
		}
		current = current->next;
	}
	return empty;
}
