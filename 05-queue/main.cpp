#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

void init(int arr[], int& front, int& rare);
int _enqueue(int arr[], int& front, int& rare);
int _dequeue(int arr[], int& front, int& rare);
void show(int arr[], int front, int rare);

int main() {
	int arr[MAX], front = -1, rare = -1;
	init(arr, front, rare);
	_dequeue(arr, front, rare);
	show(arr, front, rare);

	system("pause");
	return 0;
}

bool _isEmpty(int arr[], int front, int rare) {
	return front == -1;
}

bool _isFull(int arr[], int front, int rare) {
	return rare - front == MAX - 1 || rare - front == -1;
}

bool _isOver(int arr[], int front, int rare) {
	return rare == MAX - 1;
}

int _enqueue(int arr[], int& front, int& rare, int value) {
	if (!_isFull(arr, front, rare)) {
		if (_isEmpty(arr, front, rare)) front = 0;

		if (_isOver(arr, front, rare)) {
			rare = -1;
		}

		arr[++rare] = value;
		return 1;
	}
	return 0;
}

int _dequeue(int arr[], int& front, int& rare) {
	if (!_isEmpty(arr, front, rare)) {
		if (front == rare) {
			front = -1;
			rare = -1;
		}
		else {
			if (front == MAX - 1) front = -1;
			front++;
		}
		return 1;
	}
	return 0;
}

void show(int arr[], int front, int rare) {
	if (front == -1) return;
	for (int i = front; i <= rare; i++) {
		cout << arr[i] << endl;
	}
}

void init(int arr[], int& front, int& rare) {
	int value;
	ifstream Input("./input.txt");
	while (!_isFull(arr, front, rare) && Input >> value) {
		_enqueue(arr, front, rare, value);
	}
}
