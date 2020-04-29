#pragma once
#include <iostream>

using namespace std;


class ArboreString {
	struct Node {
		char* data;
		Node* stanga;
		Node* dreapta;
		Node* parent;
	};

	Node* start = nullptr;
	void recursiveFreeMem(Node*);
	void printSRD(Node*);
	void printRSD(Node*);

public:
	~ArboreString();

	void insert(const char** arr, int size) {
		for (int i = 0; i < size; i++) insert(arr[i]);
	}

	void insert(const char*);

	void printSRD();
	void printRSD();
	void print() {
		cout << "SRD: ";
		printSRD();
		cout << endl;
		cout << "RSD: ";
		printRSD();
		cout << endl << endl;
	}
};

