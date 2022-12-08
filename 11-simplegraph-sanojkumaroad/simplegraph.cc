//***************************************************************************                                                                           
//	Sanoj Oad                                                                
//  Z1980626                                                                 
//  CSCI 340 03                                                              
//                                                                           
//  I certify that this is my own work and where appropriate an extension    
//  of the starter code provided for the assignment.                         
//***************************************************************************

#include <fstream>
#include <iostream>
#include <list>
#include <vector>

#include "graph.h"

using namespace std;

int main(int argc, char** argv) {
  if (argc < 2) {
    // missing args filename
    cerr << "args: input-file-name\n";
    return 1;
  }

  // graph initialization
  Graph g(argv[1]);

  // graph print call
  g.Print();

  // graph traverse call
  g.Traverse();

  // exits or return 0 on success
  return 0;
}