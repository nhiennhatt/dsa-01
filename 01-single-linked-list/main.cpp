#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int value;
	Node* next = NULL;
};

void init(Node*& start);
void unallocNode(Node*& start);
void show(Node* start);
void find(Node* start);
void insertHead(Node*& start);
void insertFoot(Node*& start);
void removeHead(Node*& start);
void removeFoot(Node*& start);
void findAndRemove(Node*& start);

int main() {
	Node* start = NULL;
	init(start);
	findAndRemove(start);
	show(start);
	unallocNode(start);
	system("pause");
	return 0;
}

void unallocNode(Node*& start) {
	Node* current = start;
	Node* temp;
	while (current != NULL) {
		temp = current->next;
		delete current;
		current = temp;
	}
};

void init(Node*& start) {
	Node* current = start;
	int value = NULL;
	ifstream InputFile("./input.txt");
	while (InputFile >> value) {
		Node* newNode = new Node({value});
		if (current == NULL) {
			start = newNode;
		}
		else {
			current->next = newNode;
		}
		current = newNode;
	}
}

void show(Node* start) {
	Node* current = start;
	while (current != NULL) {
		cout << current->value << endl;
		current = current->next;
	}
}

int _find(Node* start, int value) {
	int currentPosi = 0;
	Node* currentNode = start;
	while (currentNode != NULL) {
		if (currentNode->value == value) return currentPosi;
		currentNode = currentNode->next;
		currentPosi++;
	}
	return -1;
}

void find(Node* start) {
	int value = NULL;
	while (value == NULL || value < 0) {
		cout << "Nhap gia tri can tim: ";
		cin >> value;
	}
	const int result = _find(start, value);
	if (result != -1) {
		cout << "Gia tri \"" << value << "\" nam o vi tri: " << result << endl;
	}
	else {
		cout << "Khong co gia tri \"" << value << "\"\n";
	}
}

void insertHead(Node*& start) {
	int value;
	cout << "Nhap gia tri can them: ";
	cin >> value;
	Node* newNode = new Node({ value });
	newNode->next = start;
	start = newNode;
}

void insertFoot(Node*& start) {
	int value;
	cout << "Nhap gia tri can them: ";
	cin >> value;
	Node* newNode = new Node({ value });
	if (start == NULL) {
		start = newNode;
		return;
	}
	Node* current = start;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;
}

void removeHead(Node*& start) {
	if (start == NULL) return;
	Node* temp = start;
	start = start->next;
	delete temp;
}

void removeFoot(Node*& start) {
	if (start == NULL) return;

	if (start->next == NULL) {
		Node* temp;
		temp = start;
		start = NULL;
		delete temp;
		return;
	}

	Node* current = start, *previous = NULL;
	while (current->next != NULL) {
		previous = current;
		current = current->next;
	}
	delete current;
	previous->next = NULL;
}

void findAndRemove(Node*& start) {
	if (start == NULL) return;
	int value;
	cout << "Nhap gia tri can xoa: ";
	cin >> value;
	Node* previous = NULL, * current = start;
	while (current != NULL) {
		if (current->value == value) {
			if (previous == NULL) {
				Node* temp = start;
				start = start->next;
				delete temp;
				break;
			}

			previous->next = current->next;
			delete current;
			break;
		}

		previous = current;
		current = current->next;
	}
}
