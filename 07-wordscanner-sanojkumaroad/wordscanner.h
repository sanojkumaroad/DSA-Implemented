//***************************************************************************
//
//  Sanoj Oad
//  Z1980626
//  CSCI 340 03
//
//  I certify that this is my own work and where appropriate an extension 
//  of the starter code provided for the assignment.
//
//***************************************************************************

#ifndef H_WORDSCANNER
#define H_WORDSCANNER

/* Header files */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>

/* Global Variables */
int NO_ITEMS = 4;			/// number of words to print in one line.
int ITEM_WORD_WIDTH = 14; 	/// the width reserved for the words.
int ITEM_COUNT_WIDTH = 3; 	/// the width reserved for the frequency.

/* Function Declarations */

/**
 * Reads from standard input word by word, calls the clean_word and
 * stores the <word, frequency> pair in map.
 *
 * @param m The <word, frequency> pair in map.
 *************************************************************************/
void get_words(std::map<std::string, int>&);

/**
 * Takes the word as input and removes punctuations from it, makes it
 * lowercase and stores it in key variable, ready to store in map.
 *
 * @param word The reference of the word that needs to be cleaned.
 * @param key Stores the cleaned word, ready for inserting into map.
 *************************************************************************/
void clean_entry(const std::string& word, std::string& key);

/**
 * Prints the words and its frequency from the map in a
 * clean and proper format.
 *
 * @param m The <word, frequency> pair in map.
 *************************************************************************/
void print_words(const std::map<std::string, int>&m);

/* Function Definations */
void get_words(std::map<std::string, int>&m)
{
	std::string words = ""; 	/// holds one word from stdin.
	std::string key = "";		/// stores the clean and ready-to-insert words.
	
	/// loop reads one word at a time.
	while ( (getline( std::cin, words, ' ') ))
	{
		/// function call to remove punctuation and clean it.
		clean_entry(words, key);
		
		/// increments the frequency of each word.
		//m[key]++;
		if(key.length() > 0)
		{
			m[key]++;
		}
	}
	m["i"]++; 	/// increments i-value frequency by one.
}

void clean_entry(const std::string& word, std::string& key)
{	
	/// Lambda expression for isAlphaNumeric
	auto isAlphaNum  = [](char ch) { return isalnum(ch); };
	
	/// Lambda expression for isNotAlphaNumeric
	auto isNotAlphaNum = [](char ch) { return !(isalnum(ch)); };
	
	/// gets index of first alpha numeric character.
	auto indexFirst = std::find_if(word.begin(), word.end(), isAlphaNum);
	
	/// gets index of first non-alpha numeric character.
	auto indexTwo = std::find_if(word.begin(), word.end(), isNotAlphaNum);
	
	/// assigns the alphanumeric characters only to the key variable.
	key.assign(indexFirst, indexTwo);
	
	/// Lambda expression for for_each to convert word to lowercase.
	auto Tolowercase = [](char& ch){ (ch = tolower(ch)); };
	
	/// for_each function to lowercase all letters in the word.
	std::for_each( key.begin(), key.end(), Tolowercase);
}

void print_words(const std::map<std::string, int>&m)
{ 
	int col = 1;		/// counts the number of cols to print.
	int inputSize = 0; 	/// holds the number of words in input stream.
	
	/// loops through m to print all the word in map m, and prints it with proper format.
	for(auto it = m.begin(); it != m.end(); ++it)
	{
		std::cout<<it->first<<std::setw((ITEM_WORD_WIDTH)-(it->first.length()-1))<<":";
		std::cout<<it->second<<std::setw((ITEM_COUNT_WIDTH)-(std::to_string(it->second).length()))<<" ";
		
		/// checks when it is the time to print the newline.
		if (col % NO_ITEMS == 0)
			std::cout<<std::endl;
		++col;
	}
	
	std::cout<<std::endl;
	
	/// sums the number of words in input stream
	for (auto it = m.begin(); it != m.end(); ++it)
	{ 	inputSize += it->second;	}
	
	/// prints number of words in input and output stream respectively.
	std::cout<<"number of words in input stream   :"<<inputSize<<std::endl;
	std::cout<<"number of words in output stream  :"<<m.size()<<std::endl;
}
#endif
