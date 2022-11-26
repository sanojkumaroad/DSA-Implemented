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

#ifndef STACK_H
#define STACK_H
#include <queue>

/**
 * This is our template class Stack which shows the implementation of a stack data structure
 * using the Queue STL in C++.
 *
 * It uses two queues to implement its member functions.
 *********************************************************************************/
template<typename T>
class Stack
{
private:
    /// These queues are where the stack's elements are to be saved.
    std::queue<T> q1; 
    std::queue<T> q2;

public:
    /**
     * Checks to see if the stack is empty or not.
     *
     * @return True when the q1 is empty otherwise, returns False.
     ********************************************************************************/
    bool empty() const;

    /**
     * Checks the size of stack or number of values stored in it.
     *   
     * @return The size of the stack, an integer value that is the number
     *     of elements stored in q1.
     ********************************************************************************/
    int size() const;

    /**
     * This function implements the top() functionality of stack.
     *
     * @return T value that is the reference to the element that is on top of stack.
     ********************************************************************************/
    const T& top();

    /**
     * Implements push() functionality of stack data structure using queue.
     *
     * It pushes the element at the end of stack (or at the beginning of queue q1)
     * so that it will be the top value of stack.
     *
     * @param val An element of type T that needs to be pushed in stack. 
     ********************************************************************************/
    void push(const T &val);

    /**
     * Implements the pop() functionality of stack using queue.
     *
     * Pops out the top element from stack.
     ********************************************************************************/
    void pop();
};


// Note that the members of a template go into a .h file since 
// they are not compiled directly into a .o file like the members 
// of regular/non-template classes.


template<typename T>
bool Stack<T>::empty() const
{
	return q1.empty();	//< Returns True if q1 is empty, False when q1 is not empty.
}

template<typename T>
int Stack<T>::size() const
{
	return int(q1.size());	//< Returns the size or number of elements it has stored in it.
}

template<typename T>
const T& Stack<T>::top()
{
	return q1.front();	//< Returns top/front element in q1.
}

template<typename T>
void Stack<T>::push(const T &val)
{
	q2.push(val);		//< Pushes vale in q2 first.
	          
	/// Push all the remaining elements in q1 to q2, keeping elements like a Stack DS.
        while (!q1.empty()) {
		q2.push(q1.front());
                q1.pop();
	}
	
	q1.swap(q2);		//< Swaps the q2 and q1, making q1 as its working queue.
}

template<typename T>
void Stack<T>::pop()
{
	q1.pop();		//< Removes element from q1.
}

#endif // STACK_H
