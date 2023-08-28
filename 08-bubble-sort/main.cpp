#include<iostream>
#include<fstream>
using namespace std;

void sort(int arr[], int n);

int main() {
	int arr[100], n = 0, value;
	ifstream Input("./input.txt");

	while (Input.is_open() && n < 99 && Input >> value) {
		arr[n++] = value;
	}
	Input.close();

	sort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	system("pause");
	return 0;
}

void sort(int arr[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int o = 0; o < i; o++) {
			if (arr[o] > arr[o + 1]) {
				int temp = arr[o];
				arr[o] = arr[o + 1];
				arr[o + 1] = temp;
			}
		}
	}
}
