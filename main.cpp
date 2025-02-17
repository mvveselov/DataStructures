#include <iostream>
#include "PQueue.h"
#include "Point.h"
#include "LinkedLIst.h"
#include <queue>
#include "StackSLList.h"
#include "DLinkedList.h"
using namespace std;

class LeftRight {
public:
	bool operator()(const Point& p1, const Point& p2) {
		return p1.getX() < p2.getX();
	}
};


class UpDown {
public:
	bool operator()(const Point& p1, const Point& p2) {
		return p1.getY() < p2.getY();
	}
};


class BackForth {
public:
	bool operator()(const Point& p1, const Point& p2) {
		return p1.getZ() < p2.getZ();
	}
};


//determine the way of comparison using function class.
//operator< is not being used to compare objects of class Point


void main() {
	
	PQueue<Point, 4, BackForth> pq;
	
	pq.enqueue(Point{ 1,2,0 });
	pq.enqueue(Point{ 2,1,2 });
	pq.enqueue(Point{ 0,0,1 });

	pq.print();


	//using with integral types
	//specify comparison with standart classes std::less<T>, std::greater<T>
	//approach doesn't suppose using operator< in PQueue class

	PQueue<int, 4, std::greater<int>> pqstandart;
	pqstandart.enqueue(2);
	pqstandart.enqueue(0);
	pqstandart.enqueue(3);

	pqstandart.print();

	cout << "Using std::priority queue" << endl;

	std::priority_queue<Point, std::vector<Point>, UpDown> q;

	q.push(Point{10,20});
	q.push({20,30});
	q.push({100,20});

	while (!q.empty()) {
		cout << q.top() << endl;
		q.pop();
	}

	cout << "Testing initialiser list priority queue object" << endl;
	PQueue<int, 10, less<int>> initpq{2,3,0,2,5};

	initpq.print();


	cout << "Composition method demostration" << endl;

	priority_queue<pair<Point, int>> compq;
	compq.push({ Point{10,20}, 10 });
	compq.push({ Point{20,10}, 5 });
	compq.push({ Point{1,2}, 7 });

	while (!compq.empty()) {
		cout << compq.top().first << endl;
		compq.pop();
	}

	/*
		pair(e,k); e - element(data), k - key(priority ordering object)
		page 325 Data Structures, Chapter 8
		"Each key object defines its own comparison function."
		"The key part doesn't need to depend on element part"
		"Studied at Chapter 9 in more details"
	*/

	// Linked List

	std::cout << "Linked List test" << std::endl;

	
	LinkedList list;
	

	list.addToHead(10); 
	list.addToHead(20); 
	list.addToHead(30); 

	list.Show();
	cout << "Insertion test. List size: "<<endl;

	list.insert(5, 3);
	list.Show();

	list.insert(15, 2);
	list.Show();

	list.insert(40, 0);
	list.Show();

	list.removeFromHead();
	list.Show();

	list.insert(25, 1);
	list.Show();

	list.remove(1);
	list.Show();

	list.remove(0);
	list.Show();


	cout << "List size: " << list.size() << endl;
	
	list.reverse();
	list.Show();


	cout << "==========My stack=============" << endl;

	StackSLList mystack;

	mystack.push(50);
	mystack.push(30);
	mystack.push(10);

	cout << "My top: " << mystack.top() << endl;

	mystack.print();

	cout << "Doubly Linked List" << endl;


	DLinkedList<Point> dlist;

	dlist.addFront(Point{1,2,3});
	dlist.addFront(Point{ 4,5,6 });
	dlist.addFront(Point{ 7,8,9 });


	dlist.print();


}