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
	for (int i = 0; i < n - 1; i++) {
		for (int o = i + 1; o < n; o++) {
			if (arr[o] < arr[i]) {
				int temp = arr[o];
				arr[o] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
