#include "Groceries.h"
#include <fstream>
#include <iostream>

using namespace std;

void Groceries::OptionTwo(string stringInput) // OptionTwo function used in main menu
{
	while (true) {
		try {
			cout << "Please enter input" << endl; // asks for user input
			std::cin.clear(); // allows user input to be entered if any prior value is in there 
			cin >> stringInput;
			for (int i = 0; i < stringInput.length(); i++) // optimizes user input to match input in the list
			{
				stringInput[i] = tolower(stringInput[i]); // lowercase user input
			}
			stringInput[0] = toupper(stringInput[0]); // uppercase the first letter
			Groceries::callIntFunc("optionTwo", stringInput); // call python function using users input
			if (!cin) { // if not string variable
				throw 1;
			}

		}
		catch (...) { 
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter correct input." << endl;
			system("pause");
			system("CLS");
		}
		return;
	}
}

int Groceries::Histogram(string gString, int gNum) { // Histogram function
	fstream dataFile;
	dataFile.open("frequency.dat", ios::in); // open frequency.dat
	if (dataFile.is_open()) {
		while (dataFile >> gString >> gNum) { // take values from user
			Groceries groceryMap{ {gString, gNum} }; // put values into hash map
			groceryMap.mapDisplay(); // display hash map
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
	}
	dataFile.close();
	dataFile.open("frequency.dat", std::fstream::out | std::fstream::trunc); // open file and erase the data at the end of the function
	dataFile.close();
}