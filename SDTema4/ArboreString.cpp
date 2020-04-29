#include "ArboreString.h"
#include <iostream>

ArboreString::~ArboreString() {
	recursiveFreeMem(start);
}
void ArboreString::recursiveFreeMem(Node* start_node) {
	if (start_node == nullptr) return;
	if (start_node->stanga != nullptr) recursiveFreeMem(start_node->stanga);
	if (start_node->dreapta != nullptr) recursiveFreeMem(start_node->dreapta);

	delete[] start_node->data;
	delete start_node;
}

void ArboreString::insert(const char* str_key) {
	char* key = new char[20];
	strncpy_s(key, 20,  str_key, 19);

	Node* new_node = new Node;
	Node* parent = start;

	*new_node = { key,nullptr,nullptr,nullptr };

	if (start == nullptr) {
		start = new_node;
		return;
	}

	while (true) {
		if (strcmp(key, parent->data)<=0) {
			if (parent->stanga == nullptr) {
				new_node->parent = parent;
				parent->stanga = new_node;
				break;
			} else {
				parent = parent->stanga;
			}
		} else {
			if (parent->dreapta == nullptr) {
				new_node->parent = parent;
				parent->dreapta = new_node;
				break;
			} else {
				parent = parent->dreapta;
			}
		}
	}
}


void ArboreString::printSRD() {
	printSRD(start);
}
void ArboreString::printSRD(Node* start_node) {
	if (start_node == nullptr) return;

	printSRD(start_node->stanga);
	std::cout << start_node->data << " ";
	printSRD(start_node->dreapta);
}

void ArboreString::printRSD() {
	printRSD(start);
}
void ArboreString::printRSD(Node* start_node) {
	if (start_node == nullptr) return;

	std::cout << start_node->data << " ";
	printRSD(start_node->stanga);
	printRSD(start_node->dreapta);
}