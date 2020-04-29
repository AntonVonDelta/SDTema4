#include "Arbore.h"
#include <iostream>

Arbore::~Arbore() {
	recursiveFreeMem(start);
}
void Arbore::recursiveFreeMem(Node* start_node) {
	if (start_node == nullptr) return;
	if (start_node->stanga != nullptr) recursiveFreeMem(start_node->stanga);
	if (start_node->dreapta != nullptr) recursiveFreeMem(start_node->dreapta);

	delete start_node;
}

void Arbore::insert(int key) {
	Node* new_node = new Node;
	Node* parent = start;

	*new_node = { key,nullptr,nullptr,nullptr };

	if (start == nullptr) {
		start = new_node;
		return;
	}

	while (true) {
		if (key <= parent->data) {
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

bool Arbore::find(int key) {
	Node* parent = start;

	while (true) {
		if (parent == nullptr) return false;

		if (key == parent->data) return true;
		if (key < parent->data) parent = parent->stanga;
		else parent = parent->dreapta;
	}
}

void Arbore::remove(int key) {
	Node* parent = start;
	Node* node_found = nullptr;

	while (true) {
		if (parent == nullptr) break;

		if (key == parent->data) {
			node_found = parent;
			break;
		}
		if (key < parent->data) parent = parent->stanga;
		else parent = parent->dreapta;
	}
	if (node_found == nullptr) return;

	remove(node_found);
}

// Warning! This deletes the provided node.
void Arbore::remove(Node* start_node) {
	if (start_node == nullptr) return;
	Node* parent = start_node->parent;

	if (start_node->stanga == nullptr && start_node->dreapta == nullptr) {
		if (parent->stanga == start_node) parent->stanga = nullptr;
		else parent->dreapta = nullptr;
		delete start_node;

		return;
	}

	if (start_node->stanga != nullptr && start_node->dreapta != nullptr) {
		// We have both child elements

		//First case. The default path is right and then keep left. This is the case where there is no left:
		if (start_node->dreapta->stanga == nullptr) {
			Node* right_node = start_node->dreapta;
			right_node->parent = parent;
			right_node->stanga = start_node->stanga; // take the left branch of the start_node and add it to this node(which could contain a right branch but defintely no left one)

			if (parent->stanga == start_node) parent->stanga = right_node;
			else parent->dreapta = right_node;
		} else {
			// Find the leftmost node from the right branch of start_node
			Node* loop_node = start_node->dreapta;
			while (loop_node->stanga != nullptr) loop_node = loop_node->stanga;

			start_node->data = loop_node->data;

			// Remove this small node
			remove(loop_node);
			return;	// We don't want to continue execution and delete this node
		}


	} else {
		Node* next_node;

		if (start_node->stanga != nullptr) next_node = start_node->stanga;
		else next_node = start_node->dreapta;
		next_node->parent = parent;

		if (parent->stanga == start_node) parent->stanga = next_node;
		else parent->dreapta = next_node;
	}

	delete start_node;
}

void Arbore::printinInterval(Node* start_node,int k1, int k2) {
	if (start_node == nullptr) return;

	if (k1 < start_node->data && start_node->data < k2) {
		cout << start_node->data << " ";

		// Both left and right seem good at this point
		printinInterval(start_node->stanga, k1, k2);
		printinInterval(start_node->dreapta, k1, k2);
		return;
	}

	if (k2 <= start_node->data) {
		// Search in the left branch
		printinInterval(start_node->stanga, k1, k2);
	}
	if (k1 >= start_node->data) {
		// Search in the left branch
		printinInterval(start_node->dreapta, k1, k2);
	}
}


void Arbore::printSRD() {
	printSRD(start);
}
void Arbore::printSRD(Node* start_node) {
	if (start_node == nullptr) return;

	printSRD(start_node->stanga);
	std::cout << start_node->data << " ";
	printSRD(start_node->dreapta);
}

void Arbore::printRSD() {
	printRSD(start);
}
void Arbore::printRSD(Node* start_node) {
	if (start_node == nullptr) return;

	std::cout << start_node->data << " ";
	printRSD(start_node->stanga);
	printRSD(start_node->dreapta);
}