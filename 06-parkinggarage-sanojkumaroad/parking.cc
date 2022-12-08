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

#include "parking.h"

/**
 * Takes the input, manipulates it, and stores the data in license and xact_type.
 * for the functions to use.
 * 
 * @param line A input string read from stdin.
 * @param xact_type Type of action (A or D): arrival or departure.
 * @param license The license plate number of the car.
 ******************************************************************/
void get_input_vals(const std::string &line, char &xact_type, std::string &license);

int main()
{
	std::string input = " ";	//< Stdin Input
	char act_type;				//< Arrival or Departure var.
	std::string license;		//< License number for the car.
	garage g1;					//< Garage Instace/object to use the functions.
	
	/// This loops reads the stdin until it found the '\0' or CTRL + D.
	while (input != "\0")
	{
		fflush(stdin);								//< Flushes the stdin buffer.
		getline(std::cin, input, '\n');				//< Reads one line input.
		get_input_vals( input, act_type, license);	//< Function Call to extract the input data.
		
		if (act_type == 'A') 			//< Checks if the car is at Arrivals.
			g1.arrival(license); 		//< Arrival function call.
		else if (act_type == 'D')		//< Checks if the car is at Departure.
		{
			g1.departure(license); 		//< Departure function call.
		}
		else if (act_type != 0) 		//< else if it is not a EOF then it is an invalid option.
			std::cout<<"\'"<<act_type<<"\': invalid action!\n"<<std::endl;
	}
	
	return 0;
}

/* Function defiantion */
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
	xact_type = line[0];					//< extracts the first character.
	std::size_t found = line.find(":", 2);	//< stores the next : position.
	
	if (found != std::string::npos) 		//< if it is not the end :
	{
		license = line.substr(2, found-2);	//< extracts the license number.
	}	
}