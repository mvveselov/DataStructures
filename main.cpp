#include <iostream>
#include "PQueue.h"
using namespace std;



void main() {
	
	PQueue<4> pqueue;
	pqueue.enqueue(10);
	pqueue.enqueue(5);
	pqueue.enqueue(4);

	pqueue.enqueue(2);
	pqueue.enqueue(1);
	pqueue.enqueue(3);
	pqueue.enqueue(1);
	pqueue.enqueue(2);
	pqueue.enqueue(10);
	////look up first pages of data structures
	////Highest priority should push lower one out

	pqueue.print();
	
}