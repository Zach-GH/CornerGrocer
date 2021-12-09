from collections import Counter
import re
import string
from types import resolve_bases
from typing import Dict, KeysView

def readFile(): # read file Groceries.txt
    fname = 'Groceries.txt'
    dict = {}
    with open(fname, 'r') as textfile: # open grocery file
        words = (word for line in textfile.readlines() for word in line.split()) # by line read word
        word_positions = {i: word for i, word in enumerate(words)} # counts words and returns in the form of an object
    Counter1 = Counter(word_positions.values()) # gets values for amount of words
    for key in Counter1: # uses key word and returns the count number
        print(key, Counter1[key]) # prints values
    textfile.close() # closes file

def optionTwo(v):
    fname = 'Groceries.txt'
    dict = {}
    with open(fname, 'r') as textfile:
        words = (word for line in textfile.readlines() for word in line.split())
        word_positions = {i: word for i, word in enumerate(words)}
    Counter1 = Counter(word_positions.values()) 
    if v in Counter1: 
        for key in Counter1: # check key value
            if v == key: # if user input from C++ matches key value
                print(key, Counter1[key]) # print the value
            else:
                pass # if it does not match then pass instance
    else:
        print("No matches found.") # if no matches are found then print no matches found
    textfile.close()
    return 0;

def writeFile():
    fname = 'Groceries.txt'
    oname = 'frequency.dat'
    dict = {}
    with open(fname, 'r') as textfile:
        words = (word for line in textfile.readlines() for word in line.split())
        word_positions = {i: word for i, word in enumerate(words)}
    Counter1 = Counter(word_positions.values())
    textfile.close()
    with open(oname, 'a') as otherfile:
        for key in Counter1:
            otherfile.writelines("%s\n" % t for t in (key, Counter1[key])) # output keys and values to data file
    otherfile.close()