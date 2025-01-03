#include <iostream>
#include "PQueue.h"
#include "C:\\Users\\vesel\\source\\repos\\classes\\point\\Point.h"
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

}