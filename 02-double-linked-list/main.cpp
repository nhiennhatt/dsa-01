#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int value;
	Node* previous = NULL;
	Node* next = NULL;
};

void init(Node*& start);
void unAllocNode(Node*& start);
void show(Node* start);
void insertHead(Node*& start);
void insertFoot(Node*& start);
void removeHead(Node*& start);
void removeFoot(Node*& start);
Node* findEnd(Node* start);
void findAndRemove(Node*& start);
void specialInsert(Node*& start);

int main() {
	Node* start = NULL;
	init(start);
	specialInsert(start);
	show(start);
	unAllocNode(start);
	system("pause");
	return 0;
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
			newNode->previous = current;
		}
		current = newNode;
	}
}

void unAllocNode(Node*& start) {
	Node* current = start, *temp;
	while (current != NULL) {
		temp = current;
		current = current->next;
		delete temp;
	}
}

void show(Node* start) {
	Node* current = start;
	while (current != NULL) {
		cout << current->value << endl;
		current = current->next;
	}
}
void insertHead(Node*& start) {
	int value;
	cout << "Nhap gia tri can nhap: ";
	cin >> value;
	Node* newNode = new Node({ value, NULL, start });
	if(start != NULL) start->previous = newNode;
	start = newNode;
}

void insertFoot(Node*& start) {
	Node* current = start;
	int value;
	cout << "Nhap gia tri can nhap: ";
	cin >> value;
	Node* newNode = new Node({ value });
	if (start == NULL) {
		start = newNode;
		return;
	}
	while (current->next != NULL) {
		current = current->next;
	}
	newNode->previous = current;
	current->next = newNode;
}

void removeHead(Node*& start) {
	if (start == NULL) return;
	Node* temp = start;
	if (start->next != NULL) {
		start = start->next;
		start->previous = NULL;
	}
	else {
		start = NULL;
	}
	delete temp;
}

void removeFoot(Node*& start) {
	if (start == NULL) return;
	Node* current = start, * temp;
	while (current->next != NULL) {
		current = current->next;
	}
	if (current->previous != NULL) {
		current->previous->next = NULL; 
	} else {
		start = NULL;
	}
	delete current;
}

Node* findEnd(Node* start) {
	Node* current = start;
	while (current->next != NULL) {
		current = current->next;
	}
	return current;
}

void findAndRemove(Node*& start) {
	if (start == NULL) return;
	int value;
	cout << "Nhap gia tri can tim: ";
	cin >> value;
	Node* current = start;
	while (current != NULL) {
		if (current->value == value) {
			if (current->previous == NULL && current->next == NULL) start = NULL;
			if (current->previous != NULL) current->previous->next = current->next;
			if (current->next != NULL) current->next->previous = current->previous;
			delete current;
			break;
		}
		current = current->next;
	}
}

Node* _find(Node* start, int value) {
	Node* current = start;
	while (current != NULL) {
		if (current->value == value) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

Node* nearAndgreater(Node* start, int value) {
	if (start == NULL) return NULL;
	Node* current = start, * currentResult = NULL;
	while (current != NULL) {
		if (current->value > value) {
			if (currentResult == NULL || current->value < currentResult->value) currentResult = current;
		}
		current = current->next;
	}
	return currentResult;
}

void specialInsert(Node*& start) {
	int value;
	cout << "Nhap gia tri can ap dung thuat toan: ";
	cin >> value;
	Node* findResult = _find(start, value);
	Node* targetNode = findResult != NULL ? findResult : nearAndgreater(start, value);
	cout << targetNode << endl;
	if (targetNode != NULL) {
		Node* newNode = new Node();
		cout << "Nhap gia tri can nhap: ";
		cin >> newNode->value;
		newNode->next = targetNode;
		newNode->previous = targetNode->previous;
		if (targetNode->previous != NULL) {
			targetNode->previous->next = newNode;
		} else {
			start = newNode;
		}
		targetNode->previous = newNode;
	}
}
