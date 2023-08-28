#include<iostream>
#include<fstream>
using namespace std;

const int MAX = 100;

void init(int arr[], int& current);
void pop(int arr[], int& current);
void push(int arr[], int& current);

void show(int arr[], int current) {
	for (int i = 0; i <= current; i++) {
		cout << arr[i] << endl;
	}
}

int main() {
	int arr[MAX], current = -1;
	init(arr, current);
	pop(arr, current);
	show(arr, current);

	system("pause");
	return 0;
}

int _pop(int arr[], int& current) {
	if (current < 0) return numeric_limits<int>::quiet_NaN();
	return arr[current--];
}

int _push(int arr[], int& current, int value) {
	if (current >= MAX - 1) return numeric_limits<int>::quiet_NaN();
	arr[++current] = value;
	return arr[current];
}

void init(int arr[], int& current) {
	int value;
	ifstream Input("./input.txt");
	while (current < MAX - 1 && Input >> value) {
		arr[++current] = value;
	}
}

void pop(int arr[], int& current) {
	const int result = _pop(arr, current);
	if (result != numeric_limits<int>::quiet_NaN()) {
		cout << "Deleted \"" << result << "\"\n";
	}
	else {
		cout << "No delete any item\n";
	}
}

void push(int arr[], int& current) {
	int value;
	cout << "Nhap vao gia tri can nhap: ";
	cin >> value;
	const int result = _push(arr, current, value);
	if (result != numeric_limits<int>::quiet_NaN()) {
		cout << "Pushed \"" << result << "\"\n";
	}
	else {
		cout << "No push any item\n";
	}
}
