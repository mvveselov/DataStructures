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
	//Destructor
	~LinkedList() {
		Node* temp;
		while (head != nullptr) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

};