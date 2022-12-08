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

// Header file
#include "wordscanner.h"

/* Program Driver */
int main()
{
	/// map variable for function calls.
	std::map<std::string, int> m;
	
	/// gets the words from stdin and cleans it.
	get_words(m);
	
	/// prints the words from map m.
	print_words(m);
	
	/// returns 0, on successful execution.	
	return 0;
}