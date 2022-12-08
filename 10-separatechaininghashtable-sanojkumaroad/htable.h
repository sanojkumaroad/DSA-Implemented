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

#include "entry.h"

#ifndef H_HASH_TABLE
#define H_HASH_TABLE

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// class for hash table

class HT {
 public:
  HT(const unsigned& = TBL_SZ);  // constructor
  ~HT();                         // destructor

  void insert(const Entry&);   // inserts item in hash table
  void search(const string&);  // searches for item

  void hTable_print();  // prints hash table entries
  void pTable_print();  // prints hash table entries in sorted order

 private:
  unsigned hsize;  // size of hash table

  vector<list<Entry> > hTable;  // hash table
  vector<Entry*>       pTable;  // ptr table

  int hash(const string&);  // hash function
};

#endif
