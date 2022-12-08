//***************************************************************************
//                                                                           
//	Sanoj Oad                                                                
//  Z1980626                                                                 
//  CSCI 340 03                                                              
//                                                                           
//  I certify that this is my own work and where appropriate an extension    
//  of the starter code provided for the assignment.                         
//                                                                           
//***************************************************************************

#include "htable.h"
#include <iostream>
using std::cout;
using std::endl;

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');
  
  return n % hsize;
}

// Student Implemention of Code.
/// Constructor
HT::HT(const unsigned &hs) {
  hTable.resize(hs);  //  resizes the hTable
  hsize = hs;         // sets the size of hTable
}

/// Destructor
HT::~HT() {
  // destroys all the objects
  hTable.clear();
  pTable.clear();
  
  // shrinks the memory to 0
  hTable.shrink_to_fit();
  pTable.shrink_to_fit();
}

/// inserts the record of the item in the hash table
void HT::insert(const Entry &e) {
  
  // gets the index of hTable
  int index = hash(e.key);
  
  // reads/gets the list from hTable
  list<Entry> &lst = hTable[ index ];
  
  // checks to see if the item is already present in the hash table.
  auto it = find_if( lst.begin(), lst.end(), [e] (const Entry a) {
  	// lambda function defination.
    // returns true if key matches.
    return (a.key == e.key)? true: false;
  });

  if ( it == lst.cend()) // item is new
  {
    // pushes the entry into the front of hash list.
    lst.push_front(e);
    
    // pushes the location into pTable.
    pTable.push_back( &lst.front() );
	
	// prints the entry.
    cout << " entry =  " << index << endl; 
  }
  else	// item is already present in the list.
  {
  	// prints error message.
    cout << " not inserted - duplicate key!!!" << endl;
  }
}

/// searches the hash table for a record with key.
void HT::search(const string &s) {
	
  // gets the index from hash function.
  int index = hash(s);
  
  // reads the list from hTable.
  list<Entry> &lst = hTable[ index ];
  
  // finds the item in the list.
  auto it = find_if( lst.begin(), lst.end(), [s] (const Entry e) {
  	// lambda function defination.
    // returns true if key matches else returns false.
	  return (e.key == s)? true: false;
  });
  
  if ( it == lst.cend() ) // item not found in the hTable.
    cout << " not in table!!" << endl;
  else 	// item found
  {
  	// prints the item details
    cout << " ==> number: ";
    cout.flags(ios :: right);
    cout << setw(4) << (*it).num;
    cout << " - item:";
	cout.flags(ios :: left);
    cout << setw(24) << (*it).desc << endl;
  }

}

/// prints the subscript and the contents of all active records in the hash table.
void HT::hTable_print() {
  
    // loops over hash table size.
    for ( unsigned int i = 0; i < hsize; ++i)
    {
      // reads a list of hash items from the table.
      list<Entry> &list = hTable[i];
      
      // prints all the active items in the list.
      for (auto x : list)
      {
          cout << "\n";
          cout.flags(ios :: left); 
          cout << setw(4) << i << ":" << setw(7) << x.key;
          cout << "- " << setw(7) << x.num;
          cout << "-  " << setw(24) << x.desc;
      }
    }
    cout << endl;
}

/// sorts and prints the contents of all the active records in the hash table.
void HT::pTable_print() {
	// sorts the pTable by key values (alphabetic order).
	sort( pTable.begin(), pTable.end(), []( Entry *p, Entry *q ){ 
      // lambda function defination.
      return q->key > p->key;
    });

	// prints the pTable contents/values.
    for ( auto i = pTable.begin(); i != pTable.end(); ++i )
    {
      cout.flags( ios :: right );
      cout << setw(6) <<  (*i) -> key << "  -"<< setw(6) << (*i) -> num << "  -  ";
      cout.flags( ios :: left );
      cout << setw(24) << (*i) -> desc << endl;
    }
}