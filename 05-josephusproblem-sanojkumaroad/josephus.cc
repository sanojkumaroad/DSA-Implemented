
#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>


void print_underlined_string(const std::string &message);
void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols);


/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0) {
	std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
	exit(1);
}


/**
* Create a std::list of people with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv) {
	unsigned num_people = 41;       //< The number of people to start with
	unsigned modulus = 3;           //< The count used to determine the elimination
	unsigned print_frequency = 13;  //< How often to print the state of the system
	unsigned num_cols = 12;         //< Number of colums to print per line

	int opt;
	
	/// This loops scans for the -options when executing the output.
	while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1) {
		switch (opt) {
			case 'n':  
				std::istringstream(optarg) >> num_people;
				break;
			case 'm':
				std::istringstream(optarg) >> modulus;
				break;
			case 'p':
				std::istringstream(optarg) >> print_frequency;
				break;
			case 'c':
				std::istringstream(optarg) >> num_cols;
				break;
			default:
				usage(argv[0]);
		}
	}
	
	if (optind < argc)
		usage(argv[0]); //< If we get here, there was extra junk on command line
	else
	{
		std::list<std::string> listx; 	//< Creates empty list.
		SEQ seq; 						//< Class variable to manipulate member functions.
		
		/// generate_n generates the number of people in the list.
		generate_n(std::back_inserter(listx), num_people, SEQ(num_people));
		
		/// prints the initial list of people.
		seq.print_list(listx, 0, num_cols);
	
		int print_time = 0; 				//< checks when it is the time to print the list.
		unsigned int modulus_check = 1; 	//< check for modulus.
		unsigned int eliminated = 0; 		//< counts how many people are eliminated.
		auto it1 = listx.begin(); 			//< iterator for the list.
		
		while( listx.size() > 1) 			//< loops until one person remains in the list.
		{
			if ( it1 == listx.end()) 		//< if iterator is at the end, reset it to begin().
				it1 = listx.begin();
				
			/// when it is time to eliminate a person.
			if ( modulus_check == modulus)
			{
				modulus_check = 1;	 		//< resets modulus check
				++eliminated;				//< increments on number of people eliminated.
				++print_time;				//< increments on print time.
				it1 = listx.erase(it1); 	//< removes the person.
			}
			else /// if it is not time yet.
			{
				++modulus_check;
				++it1;	
				
				/// prints the list of people when true.
				if ( (print_time % print_frequency == 0)  && (print_time != 0) ) 
				{
					/// prints the list because it's time now.
					seq.print_list(listx, eliminated, num_cols);
					print_time = 0; //< resets the flag/check.
				}
			}
			
			/// prints elimination complete when the list size is 1.
			if ( (listx.size()) == 1)
			{
				std::cout<<"Eliminations Completed"<<std::endl;
				seq.print_list(listx, eliminated, num_cols);
			}
		}
	}
	
	return 0;
}
