#pragma once
#include <iostream>

using namespace std;


class Arbore {
	struct Node {
		int data;
		Node* stanga;
		Node* dreapta;
		Node* parent;
	};

	Node* start=nullptr;
	void recursiveFreeMem(Node*);
	void printSRD(Node*);
	void printRSD(Node*);
	void remove(Node*);
	void printinInterval(Node*, int, int);

public:
	~Arbore();

	void insert(int* arr, int size) {
		for (int i = 0; i < size; i++) insert(arr[i]);
	}

	void insert(int);
	bool find(int);
	void printSRD();
	void printRSD();
	void print() {
		cout << "SRD: ";
		printSRD();
		cout << endl;
		cout << "RSD: ";
		printRSD();
		cout << endl<<endl;
	}
	void remove(int);

	void printinInterval(int k1, int k2) {
		printinInterval(start, k1, k2);
		cout << endl;
	}
};

