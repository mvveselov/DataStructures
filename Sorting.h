#pragma once


////insertion sorting

void insertionSorting(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int j = i;
		int temp = arr[i];
		while (j >= 1 && temp < arr[j - 1]) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}