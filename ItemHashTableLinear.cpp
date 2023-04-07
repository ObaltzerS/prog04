#include "Item.h"
#include "ItemHashTableLinear.h"
#include <iostream>
using namespace std;

// constructor - initializes table to empty.
ItemHashTableLinear::ItemHashTableLinear() {
	Item buckets[NUMBER_OF_BUCKETS];

}


int ItemHashTableLinear::hashFunction(int id) const {
	// Compute hash function using the modulo operator
	int hashedID = (id % NUMBER_OF_BUCKETS);
	// return computed hash value
	return hashedID; // Placeholder return value so program compiles without
	// error.
}


bool ItemHashTableLinear::insert(Item& V) {

	if (V.getId() > 0) {
		if (buckets[hashFunction(V.getId())].getId() == -1) {
			buckets[hashFunction(V.getId())] = V;
			return true;
		}
		else {
			int index = V.getId();
			while (buckets[hashFunction(index)].getId() != -1) {
				if (index > NUMBER_OF_BUCKETS - 1) {
					index = 0;
				}
				index++;
			}
			buckets[hashFunction(V.getId())] = V; \
			return true;
		}
	}
	return false;
}

bool ItemHashTableLinear::isContains(int id) const {

	if (buckets[hashFunction(id)].getId() == id) {
		return true;
	}
	else {
		int index = id;
		int start = index;
		while (buckets[hashFunction(index)].getId() != id) {
			if (index > NUMBER_OF_BUCKETS - 1) {
				index = 0;
			}
			index++;
			if (index == start) {
				return false;
			}
		}
		return true;
	}


	return false;
}

// retrieve
// pre-condition: receives an integer ID value. The integer ID is the
// unique integer Stock Keeping Unit number for a product.
// post-condition: return Item matching the given ID.
// Item will contain invalid values of id -1 and name "undefined" and price of 0
// if not Item in the hash table has the given ID.
Item ItemHashTableLinear::retrieve(int ID) {
	Item empty = Item();
	if (buckets[hashFunction(ID)].getId() == ID) {
		return buckets[hashFunction(ID)];
	}
	else {
		int index = ID;
		int start = index;
		while (buckets[hashFunction(index)].getId() != ID) {
			if (index > NUMBER_OF_BUCKETS - 1) {
				index = 0;
			}
			index++;
			if (index == start) {
				return empty;
			}
		}
		return buckets[hashFunction(index)];
	}


	return empty;
}
