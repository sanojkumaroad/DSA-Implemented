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

#include <iostream>
//#include <cstring> Not Needed
#include <deque>
#include <stack>

/* Class Car */
class car
{
public:
	/// Constructor to store the id and license of car.
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the number of times the car has been moved.
    void move();

    /// @return the number of times that the car has been moved.
    int get_num_moves() const;
	
    /// @return A reference to the license for this car.
    const std::string &get_license() const;

    /**
    * Overload the << so this can print itself as:
    *    Car X with license plate "Y"
    ******************************************************************/
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs);

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};

/* Class Garage */
class garage
{
public:
		/// Constructor to store the parking lot limit/size.
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.                                                           
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.                                                          
        void departure(const std::string &license);

private:
        int next_car_id = { 1 }; 		///< Is the id for the next arriving car.
        std::deque<car> parking_lot;	///< parking lot of type deque.
        size_t parking_lot_limit;		///< limit/size of parking lot.
};

/* Car Class Function Definations Begin */

void car::move()
{
	++num_moves; 	///< Increments num_moves for the car.
}

int car::get_num_moves() const
{
	return num_moves;	///< returns num_moves for the car.
}

const std::string &car::get_license() const
{
	return license; 	///< returns The license of the car.
}

std::ostream& operator<<(std::ostream& lhs, const car& rhs)
{
	/// Overloads << operator to print the name of the car with license plate.
	lhs<<"Car "<<rhs.id<<" with license plate \""<<rhs.license<<"\" ";
	return lhs;
}
/* Car Class Function Definations End */

/* Garage Class Function Definations Begin */
void garage::arrival(const std::string &license)
{
	car c(next_car_id, license);  	///< Instace of the car that sets it id and license.
	
	/// When the garage is full:
	if ( int(parking_lot_limit) < 1)
	{
		std::cout<<c<<"has arrived."<<std::endl;
		std::cout<<"    But the garage is full!\n"<<std::endl;
		return;
	}
	else 	/// When the garage is not full: 
	{
		std::cout<<c<<"has arrived.\n"<<std::endl; 		///< prints the car details.
		parking_lot.push_front(c);						///< adds the car in the deque.
		--parking_lot_limit;							///< -1 parking space available.
		++next_car_id;									///< updates car id for next car.
	}
}

void garage::departure(const std::string &license)
{
	int found = 0; 				///< flag to check if car was found.
	std::stack<car> car_stack; 	///< stack of cars moved. 
	
	/// Loops from the end to begin of the deque.
	for (auto it = parking_lot.rbegin(); it != parking_lot.rend(); ++it)
	{
		/// When the car is found:
		if ((*it).get_license() == license)
		{
			found = 1; 				///< sets the found flag to be true.
			(*it).move();			///< adds num_moves for the car.
			parking_lot_limit += 1; ///< Increments the parking space available.
			
			/// Printing the Car Details.
			std::cout<<(*it)<<"has departed,\n    car was moved ";
			if ((*it).get_num_moves() == 1)
				std::cout<<(*it).get_num_moves()<<" time in the garage.\n"<<std::endl;
			else
				std::cout<<(*it).get_num_moves()<<" times in the garage.\n"<<std::endl;
			
			parking_lot.pop_back(); 	///< Pops the car from the deque.
			++it;						///< Iterates to the next car in the deque.
			
			/// In case, it was just one car in the deque:
			if (it == parking_lot.rend())
				return;
		}
		else if (found != 1)
		{
			/// Cars that were moved in order to take the departing car out.
			/// Adds 1 to the number of moves.
			(*it).move();
		}
		
		/// Adds the car in the stack.
		car_stack.push(*it);
		/// Pops the car out from the deque.
		parking_lot.pop_back();
	}
	
	/// When found flag is 0 AND car was not found:
	if (found == 0)
	{
		std::cout<<"No car with license plate \""<<license<<"\" is in the garage.\n"<<std::endl;
	}
	else if (found == 1) ///< when we are done with taking the car out.
	{					///< time to put the cars in the stack back to the deque.
		
		/// Loops until car stack is empty.	
		while( !car_stack.empty())
		{
			parking_lot.push_back(car_stack.top());
			car_stack.pop();
		}
	}
}
/* Car Class Function Definations End */