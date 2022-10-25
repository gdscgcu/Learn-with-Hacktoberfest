#pragma once
#include<iostream>
#include"Node.h"
class StackCircularList
{
private:
	Node* top, *first;
public:
	StackCircularList() {
		top = first = NULL;
	}
	// empty check
	bool isEmpty() {
		return top == NULL;
	}
	// push method
	bool push(int key) {
		Node* t = new Node(key);  // creating a new node of list
		if (isEmpty()) {		// necessary empty check 
			top = first = t;	// top and first both point to only node in our circular stack
			top->next = t;		// top points to itself because it is circular
			free(t);			// freeing t pointer because no need of it onwards
			return true;
		}
		// if not empty 
		top->next = t;		// top next will point to t 
		top = t;			// top will move to t then 
		free(t);			// freeing t 
		top->next = first;	// making our stack circular 
		return true;
	}
	// pop method 
	bool pop(int& x) {			
		if (!isEmpty()) {	// we cannot pop from empty stack 
			x = top->data;	// coping top data into a variable given
			Node* t = first; // a new pointer of node type
			while (t) {		// now i will reach in stack before x 
				if (t->next->data == x)		// check will stop one node before top 
					break;					// will break the loop and outer check 
				t = t->next;
			}
			top = t;			// top will come to one node before 
			free(t);			// freeing t
			top->next = first;		// making our updated stack circular
			return true;
		}
		return false;
	}
	}
};
