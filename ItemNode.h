#ifndef ITEM_NODE_HDR
#define ITEM_NODE_HDR

#include "Item.h"

class ItemNode {
public:
	// item node constructor w/ default values
	ItemNode();

	void Insert(Item data);

	ItemNode* next;
	Item data;


};
#endif