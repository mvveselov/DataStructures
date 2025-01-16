#pragma once
#include <iostream>

template <typename T>
class DLinkedList {
	struct DNode {
		T elem;
		DNode* next;
		DNode* prev;
	};
	DNode* head;
	DNode* trail;

public:
	DLinkedList();

	DLinkedList(T e);

	void addFront(T e); // push
	void addBack(T e);

	void removeFront(); // pop
	void removeBack();

	T front() const; // top
	T back() const;

	bool empty() const; // empty
	int size() const; //size


	void add(int index, T e);//
	void remove(int index);//

	void print() const;

	//DESTRUCTOR
	//~DLinkedList();

};

template <typename T>
DLinkedList<T>::DLinkedList() {
	head = new DNode;
	trail = new DNode;

	head->next = trail;
	trail->prev = head;

	head->prev = nullptr;
	trail->next = nullptr;
}


template <typename T>
DLinkedList<T>::DLinkedList(T e) {
	head = new DNode;
	trail = new DNode;

	DNode* temp = new DNode;
	head->next = temp;
	head->prev = nullptr;

	temp->elem = e; // operator=
	temp->prev = head;
	temp->next = trail;

	trail->prev = temp;
	trail->next = nullptr;
}

template <typename T>
void DLinkedList<T>::addFront(T e) {
	DNode* v = new DNode;
	v->next = head->next;
	v->prev = head;

	v->elem = e;

	head->next = v;
	v->next->prev = v;

}


template <typename T>
void DLinkedList<T>::print() const {
	DNode* cursor = head->next;
	while (cursor != trail) {
		std::cout << cursor->elem << " ";
		cursor = cursor->next;
	}
	std::cout << std::endl;
}
