#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>
#include "Groceries.h"

using namespace std;

void main()
{
	Groceries currUser{}; // creates instance of class to use and call functions 
	
	currUser.MainMenu(currUser.GetUserInput()); // call function main menu
}