#include "Groceries.h"

// getters and setters

void Groceries::SetUserInput(int userInput) {
	input = userInput;
}
int Groceries::GetUserInput() const {
	return input;
}

void Groceries::SetStringInput(string stringInput) {
	pyInput = stringInput;
}

string Groceries::GetStringInput() const {
	return pyInput;
}

void Groceries::SetGrocerString(string gString) {
	grocerString = gString;
}

void Groceries::SetGrocerNum(int gNum) {
	grocerNum = gNum;
}

string Groceries::GetGrocerString() const {
	return grocerString;
}

int Groceries::GetGrocerNum() const {
	return grocerNum;
}