#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <algorithm>
#include "Groceries.h"

using namespace std;

int Groceries::callIntFunc(string proc, int param) {
	{
		char* procname = new char[proc.length() + 1];
		std::strcpy(procname, proc.c_str());

		PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
		// Initialize the Python Interpreter
		Py_Initialize();
		// Build the name object
		pName = PyUnicode_FromString((char*)"PythonCode");
		// Load the module object
		pModule = PyImport_Import(pName);
		// pDict is a borrowed reference 
		pDict = PyModule_GetDict(pModule);
		// pFunc is also a borrowed reference 
		pFunc = PyDict_GetItemString(pDict, procname);
		if (PyCallable_Check(pFunc))
		{
			pValue = Py_BuildValue("(i)", param);
			PyErr_Print();
			presult = PyObject_CallObject(pFunc, pValue);
			PyErr_Print();
		}
		else
		{
			PyErr_Print();
		}
		//printf("Result is %d\n", _PyLong_AsInt(presult));
		Py_DECREF(pValue);
		// Clean up
		Py_DECREF(pModule);
		Py_DECREF(pName);
		// Finish the Python Interpreter
		Py_Finalize();

		// clean 
		delete[] procname;

		return _PyLong_AsInt(presult);
	}
}

int Groceries::callIntFunc(string proc, string param) {
	{
		char* procname = new char[proc.length() + 1];
		std::strcpy(procname, proc.c_str());

		char* paramval = new char[param.length() + 1];
		std::strcpy(paramval, param.c_str());


		PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
		// Initialize the Python Interpreter
		Py_Initialize();
		// Build the name object
		pName = PyUnicode_FromString((char*)"PythonCode");
		// Load the module object
		pModule = PyImport_Import(pName);
		// pDict is a borrowed reference 
		pDict = PyModule_GetDict(pModule);
		// pFunc is also a borrowed reference 
		pFunc = PyDict_GetItemString(pDict, procname);
		if (PyCallable_Check(pFunc))
		{
			pValue = Py_BuildValue("(z)", paramval);
			PyErr_Print();
			presult = PyObject_CallObject(pFunc, pValue);
			PyErr_Print();
		}
		else
		{
			PyErr_Print();
		}
		//printf("Result is %d\n", _PyLong_AsInt(presult));
		Py_DECREF(pValue);
		// Clean up
		Py_DECREF(pModule);
		Py_DECREF(pName);
		// Finish the Python Interpreter
		Py_Finalize();

		// clean 
		delete[] procname;
		delete[] paramval;


		return _PyLong_AsInt(presult);
	}
}

void Groceries::CallProcedure(string pName) {
	{
		char* procname = new char[pName.length() + 1];
		std::strcpy(procname, pName.c_str());

		Py_Initialize();
		PyObject* my_module = PyImport_ImportModule("PythonCode");
		PyErr_Print();
		PyObject* my_function = PyObject_GetAttrString(my_module, procname);
		PyObject* my_result = PyObject_CallObject(my_function, NULL);
		Py_Finalize();

		delete[] procname;
	}

}