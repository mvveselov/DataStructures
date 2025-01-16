#pragma once
#include <iostream>


class LinkedList {
	struct Node {
		int elem;
		Node* next;
	};
	Node* head;
	
public:
	LinkedList() : head{ nullptr } {};

	LinkedList(int e) {
		head = new Node{};
		head->elem = e;
		head->next = nullptr;
	}

	void addToHead(int e) {
		Node* temp = new Node{};
		temp->elem = e;
		temp->next = head;
		head = temp;
	}

	void Show() const {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->elem << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	void insert(int e, int index) {
		if (index == 0)
			addToHead(e);
		else {
			Node* temp = new Node{ e, nullptr };
			Node* cursor = head;
			int i = 0;
			while (i < index - 1) { // недостаток списка по сравнению с массивом
				cursor = cursor->next; 
				i++;
			}
			temp->next = cursor->next;
			cursor->next = temp;
		}
	}

	void remove(int index) {
		if (index == 0) {
			removeFromHead();
			return;
		}
		Node* cursor = head;
		int i = 0;
		while (i < index - 1) {
			cursor = cursor->next;
			i++;
		}
		Node* temp = cursor->next;
		cursor->next = cursor->next->next;
		delete temp;
	}

	int size() const {
		int count{ 0 };
		Node* cursor = head;
		while (cursor != nullptr) {
			cursor = cursor->next;
			count++;
		}
		return count;
	}




	bool empty() const {
		return head == nullptr;
	}


	void removeFromHead() {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	int top() const {
		return head->elem;
	}



	void reverse() {
		LinkedList reverse;
		while (!this->empty()) {
			reverse.addToHead(this->top());
			this->removeFromHead();
		}
		head = reverse.head;
		reverse.head = nullptr;
	}


	//Destructor
	~LinkedList() {
		while (!empty())
			removeFromHead();
	}




};