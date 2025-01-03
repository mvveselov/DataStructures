#pragma once
#include <iostream>
using namespace std;

template <class T, int capacity, typename Compare>
class PQueue {
	T arr[capacity];
	int n;
	Compare compare;
public:
	PQueue() { n = 0; }
	void enqueue(T e);
	void dequeue();
	const T front() const { return *arr; }
	void print() {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	int size() { return n; }
	
};



template <class T, int capacity, typename Compare>
void PQueue<T, capacity, Compare>::dequeue() {
	if (n == 0)
		return;
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	n--;
}

//comparison rule is not necessaryly can be done using boolean operators, but also with comparison object
//in this case, there is no need for operator< overloaded in user class

template <class T, int capacity,typename Compare>
void PQueue<T, capacity, Compare>::enqueue(T e) {
	if (n == capacity) {
		if (compare(arr[n - 1], e))
			return;
	}
	else
		n++;

	int i{};
	i = n - 2;

	while (i >= 0 && compare(e , arr[i])) {
		arr[i + 1] = arr[i];
		i--;
	}

	arr[i + 1] = e;
}

