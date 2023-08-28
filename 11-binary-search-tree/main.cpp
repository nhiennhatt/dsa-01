#include<iostream>
#include<fstream>
using namespace std;

struct Node {
	int value;
	Node* left = NULL;
	Node* right = NULL;
};

void add(Node*& start);
void init(Node*& start);
void lnr(Node* start);
void unAlloc(Node* start);
void deleteNode(Node*& node, int value);

int main() {
	Node* start = NULL;
	init(start);
	lnr(start);
	cout << endl;
	deleteNode(start, 31);
	lnr(start);
	cout << endl;
	unAlloc(start);

	system("pause");
	return 0;
}

int _add(Node*& start, int value) {
	Node* newNode = new Node({value});
	if (start == NULL) {
		start = newNode;
		return 1;
	}

	Node* current = start;
	while (true) {
		if (current->value < value) {
			if (current->right != NULL) {
				current = current->right;
				continue;
			}
			current->right = newNode;
		}
		else if (current->value > value) {
			if (current->left != NULL) {
				current = current->left;
				continue;
			}
			current->left = newNode;
		}
		else {
			return 0;
		}
		return 1;
	}
}

void add(Node*& start) {
	int value;
	cout << "Nhap gia tri can nhap: ";
	cin >> value;
	_add(start, value);
}

void init(Node*& start) {
	int value;
	ifstream Input("./input.txt");

	while (Input >> value) {
		_add(start, value);
	}
}

void lnr(Node* start) {
	if (start != NULL) {
		lnr(start->left);
		cout << start->value << " ";
		lnr(start->right);
	}
}

void deepDelete(Node*& node, Node*& target) {
	if (node->left == NULL) {
		target->value = node->value;
		Node* temp = node;
		node = node->right;
		delete temp;
		return;
	}
	deepDelete(node->left, target);
}

void deleteNode(Node*& node, int value) {
	if (node == NULL) return;
	if (node->value == value) {
		if (node->left == NULL) {
			Node* temp = node;
			node = node->right;
			delete temp;
		}
		else if (node->right == NULL) {
			Node* temp = node;
			node = node->left;
			delete temp;
		}
		else {
			deepDelete(node->right, node);
		}
		return;
	}
	if (node->value < value) deleteNode(node->right, value);
	if (node->value > value) deleteNode(node->left, value);
}

void unAlloc(Node* start) {
	if (start != NULL) {
		unAlloc(start->left);
		unAlloc(start->right);
		delete start;
	}
}
