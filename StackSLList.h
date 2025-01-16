#pragma once
#include "LinkedLIst.h"



class StackSLList { 
	LinkedList list; 
public:
	void push(int e) {
		list.addToHead(e);
	}

	void pop() {
		list.removeFromHead();
	}

	int top() const {
		 return list.top();
	}

	int size() const {
		return list.size();
	}

	bool empty() const {
		return list.empty();
	}
	void print() const {
		list.Show();
	}
};

//inheretence coming soon