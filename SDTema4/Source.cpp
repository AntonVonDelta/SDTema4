#include <iostream>
#include "Arbore.h"
#include "ArboreString.h"

using namespace std;

int main() {
	Arbore temp;
	int data[] = { 90,50,20,5,75,66,68,80,150 };

	temp.insert(data,sizeof(data)/sizeof(int));

	temp.print();
	temp.printinInterval(79, 200);

	ArboreString tempstr;
	const char* str[] = {  "for", "geeks", "a", "portal",
		"to", "learn", "can", "be", "computer",
		"science", "zoom", "yup", "fire", "in", "data" };
	tempstr.insert(str, sizeof(str) / sizeof(str[0]));
	tempstr.print();

	return 0;
}