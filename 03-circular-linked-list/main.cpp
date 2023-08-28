#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int value;
	Node* next = NULL;
};

void init(Node*& start);
void show(Node* start);
void unAllocNode(Node*& start);
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
	unAllocNode(start);
	system("pause");
	return 0;
}

Node* _findEnd(Node* start) {
	if (start == NULL) return NULL;
	Node* current = start;
	while (current->next != start) {
		current = current->next;
	}
	return current;
}

void init(Node*& start) {
	Node* current = start;
	int value;

	ifstream InputFile("./input.txt");
	while (InputFile >> value) {
		Node* newNode = new Node({ value });
		if (current == NULL) {
			start = newNode;
		}
		else {
			current->next = newNode;
		}
		newNode->next = start;
		current = newNode;
	}
}

void show(Node* start) {
	Node* current = start;
	if (start == NULL) return;
	do {
		cout << current->value << endl;
		current = current->next;
	} while (current != start);
}

void unAllocNode(Node*& start) {
	Node* current = start, * temp;
	if (start == NULL) return;
	do {
		temp = current;
		current = current->next;
		delete temp;
	} while (current != start);
}

void insertHead(Node*& start) {
	int value;
	cout << "Nhap vao gia tri can nhap: ";
	cin >> value;
	Node* newNode = new Node({ value, start });
	if (start != NULL) {
		_findEnd(start)->next = newNode;
	}
	else {
		newNode->next = newNode;
	}
	start = newNode;
}

void insertFoot(Node*& start) {
	int value;
	cout << "Nhap vao gia tri can nhap: ";
	cin >> value;
	Node* newNode = new Node({ value, start });
	if (start != NULL) {
		_findEnd(start)->next = newNode;
	}
	else {
		newNode->next = newNode;
		start = newNode;
	}
}

void removeHead(Node*& start) {
	if (start == NULL) return;
	Node* temp = start;
	if (start->next == start) {
		start = NULL;
	}
	else {
		_findEnd(start)->next = start->next;
		start = start->next;
	}
	delete temp;
}

void removeFoot(Node*& start) {
	if (start == NULL) return;
	Node* current = start, * previous = _findEnd(start);
	do {
		previous = current;
		current = current->next;
	} while (current->next != start);

	Node* temp = current;
	if (current == start) {
		start = NULL;
	}
	else {
		previous->next = current->next;
	}
	delete temp;
}

void findAndRemove(Node*& start) {
	if (start == NULL) return;
	int value;
	cout << "Nhap gia tri can tim: ";
	cin >> value;
	Node* current = start, * previous = _findEnd(start), * target = NULL;
	do {
		if (current->value == value) {
			target = current;
			break;
		}
		previous = current;
		current = current->next;
	} while (current != start);

	if (target == NULL) return;
	if (start->next == start) start == NULL;
	if (start == target) start = target->next;
	previous->next = target->next;
	delete target;
}
