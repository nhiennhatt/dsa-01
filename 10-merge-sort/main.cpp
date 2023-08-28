#include<iostream>
#include<fstream>
using namespace std;

void mergeSort(int arr[], int start, int end);

int main() {
	int arr[100], n = 0, value;
	ifstream Input("./input.txt");

	while (Input.is_open() && n < 99 && Input >> value) {
		arr[n++] = value;
	}
	Input.close();

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}

int* assignIntArray(int arr[], int start, int end) {
	int* newArr = new int[end - start + 1];
	for (int i = start; i <= end; i++) {
		*(newArr + i - start) = *(arr + i);
	}
	return newArr;
}

void merge(int arr[], int start, int mid, int end) {
	int numberOfLeft = mid - start + 1,
		numberOfRight = end - mid,
		* left = assignIntArray(arr, start, mid),
		* right = assignIntArray(arr, mid + 1, end),
		currentLeft = 0,
		currentRight = 0,
		current = start;

	while (currentLeft < numberOfLeft && currentRight < numberOfRight) {
		if (*(left + currentLeft) < *(right + currentRight)) {
			*(arr + current) = *(left + currentLeft);
			currentLeft++;
		}
		else {
			*(arr + current) = *(right + currentRight);
			currentRight++;
		}
		current++;
	}

	while (currentLeft < numberOfLeft) {
		*(arr + current) = *(left + currentLeft);
		currentLeft++;
		current++;
	}

	while (currentRight < numberOfRight) {
		*(arr + current) = *(right + currentRight);
		currentRight++;
		current++;
	}
	
	delete[] right;
	delete[] left;
}

void mergeSort(int arr[], int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid, end);
}
