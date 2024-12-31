#pragma once
#include <iostream>
using namespace std;

template <int size>
class PQueue {
	int arr[size]{};
	int n;
public:
	PQueue() { n = 0; }
	void enqueue (int e) {
		if (n == size) {
			if(arr[n - 1] < e)
				return;
		} else 
			n++;

		int i{};
		i = n - 2;

		while (i >= 0 && e < arr[i]) {
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i+1] = e;
	}
	void print() {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << endl;
	}
};