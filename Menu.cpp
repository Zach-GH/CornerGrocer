#include "Groceries.h"
#include <iomanip>

using namespace std;

// main menu function
int Groceries::MainMenu(int userInput)
{
	// display function for main menu with throw catch to check input
	Groceries::Display();
	while (true) {
		try {
			cout << "Please enter input" << endl;
			std::cin.clear();
			cin >> userInput;
			if ((userInput <= 0) || (userInput > 4)) { // accepts user input 1 through 4 only
				throw 1;
			}
			if (userInput == 1) {
				system("CLS");
				Groceries::CallProcedure("readFile"); // Call python function readfile with CallProcedure to output list
				system("pause");
				system("CLS");
				Groceries::MainMenu(userInput);
				Groceries::Display();
			}

			if (userInput == 2) {
				system("CLS");
				Groceries::OptionTwo(Groceries::GetStringInput()); // Get string input for option two and return python function
				system("pause");
				system("CLS");
				Groceries::MainMenu(userInput);
				Groceries::Display();
			}

			if (userInput == 3) {
				system("CLS");
				Groceries::CallProcedure("writeFile"); // Call python function write file 
				Groceries::Histogram(Groceries::GetGrocerString(), Groceries::GetGrocerNum()); // Call function to output histogram with ascii values
				system("pause");
				system("CLS");
				Groceries::MainMenu(userInput);
				Groceries::Display();
			}

			if (userInput == 4) { // exit
				system("CLS");
				cout << "Bye bye!" << endl;
				exit(0);
			}
			Groceries::SetUserInput(userInput);
			system("CLS");
		}
		catch (...) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a positive, real number." << endl;
			system("pause");
			system("CLS");
			Groceries::MainMenu(userInput);
			Groceries::Display();
		}
	}
	return 0;
}

void Groceries::Display() { // display function called above
	cout << "Choose an option" << endl;
	cout << "[1] Show list" << endl;
	cout << "[2] Show item" << endl;
	cout << "[3] Show histogram" << endl;
	cout << "[4] Quit\n" << endl;
}
