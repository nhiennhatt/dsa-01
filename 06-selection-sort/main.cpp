#include<iostream>
#include<fstream>
using namespace std;

void sort(int arr[], int n);

int main() {
	int arr[100], n = 0, value;
	ifstream Input("./input.txt");
	while (n < 99 && Input >> value) {
		arr[n] = value;
		n++;
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
		int* min = &arr[i];
		for (int o = i + 1; o < n; o++) {
			if (arr[o] < *min) min = &arr[o];
		}
		int temp = *min;
		*min = arr[i];
		arr[i] = temp;
	}
}