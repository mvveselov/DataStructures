#pragma once
#include <iostream>
using namespace std;

template <class T, int capacity>
class PQueue {
	T arr[capacity]{};
	int n;
public:
	PQueue() { n = 0; }
	void enqueue(T e);
	void dequeue();
	const int front() const { return *arr; }
	void print() {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
	int size() { return n; }

};

template <class T, int capacity>
void PQueue<T, capacity>::enqueue(T e) {
	if (n == capacity) {
		if (arr[n - 1] < e)
			return;
	}
	else
		n++;

	int i{};
	i = n - 2;

	while (i >= 0 && e < arr[i]) {
		arr[i + 1] = arr[i];
		i--;
	}

	arr[i + 1] = e;
}

template <class T, int capacity>
void PQueue<T, capacity>::dequeue() {
	if (n == 0)
		return;
	for (int i = 0; i < n - 1; i++)
		arr[i] = arr[i + 1];
	n--;
}