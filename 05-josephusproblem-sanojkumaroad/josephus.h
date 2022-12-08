#ifndef H_JOSEPHUS
#define H_JOSEPHUS

#include <iostream>
#include <string>
#include <list>

#define NO_LETS  26    // no of letters in English alphabet

/**
* A class that may be used as a generator to assign IDs/names
* For the Josephus problem.
*****************************************************************************/
class SEQ
{
private:
    std::string id;     ///< name tag for person
    unsigned size;      ///< no of people (spec'd by constructor)
    unsigned nd;        ///< no of characters needed in the name tags

    /**
    * Calculate a log base-26 of the given number.
    * This value represents how manay characters are needed
    * for the generated names.
    *
    * @param sz The number if IDs that need to be generated.
    * @return The character length needed for sz number of names.
    *************************************************************************/
    unsigned find_nd(const double& sz) 
    {
        if ((sz/NO_LETS) <= 1)
            return 1;
        else 
            return(find_nd(sz/NO_LETS)+1);      // calculate the value recursively
    }

public:
    /**
    * Constructor
    *
    * @param s The total number of names that are expected to be generated.
    *************************************************************************/
    SEQ(const unsigned& s=1) : size(s)
    {
        nd = find_nd(s);            // figure out how many chars we need to use
        id = std::string(nd, 'A');  // prime the ID with the first tag name 
    }

    /**
    * @return The value of the next name tag in sequence.
    *************************************************************************/
    std::string operator()()
    {
        auto tmp = id;      // copy the current value to be returned
        bool done = true;   // used to signal when we are done adding

        // Increment the ID name for the next call 
        for (int i=nd-1; i >= 0 && done; --i)
        {
            if (id[i] < 'Z') 
            {
                // If letter is not a Z then we can advance it and be done
                ++id[i];    
                done = false; 
            }
            else 
            {
                // If letter is Z then go back to with a carry into next position 
                id[i] = 'A';
            }
        }
        return tmp;
    }
    
    /**
    * Prints the message passed and a dashed line under it with the same length as its message.
    *
    * @param message The string that needs to be printed.
    *************************************************************************/
    void print_underlined_string(const std::string &message)
    {
    	/// prints the message.
    	std::cout<<message<<std::endl;
    	
		/// prints '-' underline.
    	std::cout<<std::string(message.length(), char('-'))<<std::endl;
	}
    
    /**
    * Prints the list of people before, during, and after the elimination using josephus algorithm.
    * 
    * @param collection The list of people. 
    * @param eliminations The number of people eliminated.
    * @param num_cols The number of columns that needs to be printed in a row.
    *************************************************************************/
    void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols)
    {
    	/// creats the message for print underline function.
    	std::string str = "After eliminating "+ std::to_string(eliminations) + std::string(" people");	
		
		/// prints message and underline.
    	if (eliminations == 0)
	    	print_underlined_string("Initial group of people");
	    else
	    {
	    	/// forwards the message to the print underline function.
	    	print_underlined_string((str.c_str()));
		}
	 
		
		int comma_flag = 1;   //< flag to check for commas.
		
		/// iterates over the list and prints it.
    	for (auto it = collection.begin(); it != collection.end(); ++it)
    	{
    		std::cout<<*it;	//< prints each person name.
    		
    		/// check if comma needs to be printed or not.
    		if ( (comma_flag != num_cols) && ( *it != *collection.rbegin()) )
    		{
    			std::cout<<", ";
			}
			else
    		{
    			std::cout<<std::endl;
    			comma_flag = 0;
			}
			
			++comma_flag;
		}
		
		/// prints a newline at the end of print function call.
		if ( (collection.size() != 1) )
				std::cout<<std::endl;
	}
};

#endif
