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
        int words = 0;
        for (list<string>::iterator i = wordlist->begin(); i != wordlist->end(); i++)
        {
            words++;
        }
        return words;
	}

	// add entry at the back of the linked list
	void addEntryBack(const string& aword) {
        wordlist->push_back(aword);
	}

	// print all words stored in the linked list, separated by a space
	const string listToString() {
        string output;
        for (list<string>::iterator i = wordlist->begin(); i != wordlist->end(); i++)
        {
            output = output + *i + " ";
        }
        cout << endl;
        return output;
	}

	// print duplicated words in the linked list
	void printDuplicates() {
        string word;
        for (list<string>::iterator i = wordlist->begin(); i != wordlist->end(); i++)
        {
            if (*i == word)
            {
                cout << *i << endl;
            }
            word = *i;
        }
        cout << endl;
	}

	// remove duplicated words in the linked
	void removeDuplicates() {
        wordlist->unique();
	}

	// determine the total number of duplicated words in the list
	int totalDuplicates() {
        string word;
        int count = 0;
        for (list<string>::iterator i = wordlist->begin(); i != wordlist->end(); i++)
        {
            if (*i == word)
            {
                count++;
            }
            word = *i;
        }
        return count;
	}

	// check if the list is empty
	bool isEmpty() {
        bool isIt;
        if(wordlist != NULL)
            isIt = true; // is empty
        else
            isIt = false; // isn't empty
        return isIt;
	}

	// Empty the list
	void makeEmpty() {
        delete wordlist;
        wordlist = new list<string>;
	}

private:
	list<string> *wordlist;
};
