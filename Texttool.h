// Project 2
// Texttool.h

#pragma once

#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

class TextTool {
public:
	// default constructor
	TextTool() {
        wordlist = new list<string>;
	}

	// destructor
	~TextTool() {
        delete wordlist;
	}

	// Load information from a text file with the given filename.
	void loadListFromTextfile(string filename) {
		ifstream ifs;
		ifs.open(filename);

		if (ifs.is_open()) {
			string aword;
			while (ifs >> aword) {
				addEntryBack(aword);
			}
			ifs.close();
		}
		else
			throw invalid_argument("Could not open file " + filename);
	}

	// return the number of words in the linked list
	int totalWords() {
        list<string> *temp;
        temp = wordlist;
        
        int words;
        while (!temp->empty())
        {
            if(temp->front() != "")
                words++;
        }
        
        delete temp;
        return words;
	}

	// add entry at the back of the linked list
	void addEntryBack(const string& aword) {
        wordlist->push_back(aword);
	}

	// print all words stored in the linked list, separated by a space
	const string listToString() {
        for (list<string>::iterator i = wordlist->begin(); i != wordlist->end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
	}

	// print duplicated words in the linked list
	void printDuplicates() {
        for (list<string>::iterator i = wordlist->begin(); i != wordlist->end(); i++)
        {
            string word;
            cout << *i << " ";
        }
        cout << endl;
		
	}

	// remove duplicated words in the linked
	void removeDuplicates() {
		// TO BE COMPLETED
		
	}

	// determine the total number of duplicated words in the list
	int totalDuplicates() {
		// TO BE COMPLETED
		
	}

	// check if the list is empty
	bool isEmpty() {
		// TO BE COMPLETED
	}

	// Empty the list
	void makeEmpty() {
		// TO BE COMPLETED
	}

private:

	list<string> *wordlist;
};
