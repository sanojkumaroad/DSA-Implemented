//***************************************************************************                                                  
//	Sanoj Oad                                                                
//  Z1980626                                                                 
//  CSCI 340 03                                                              
//                                                                           
//  I certify that this is my own work and where appropriate an extension    
//  of the starter code provided for the assignment.                         
//***************************************************************************

#ifndef GRAPH_H
#define GRAPH_H
#include <list>
#include <vector>

class Graph {
 private:
  int                          size;              // holds the size of adj-matrix of graph
  std::vector<std::list<int> > adj_list;          // adjacency list of edges for the graph
  std::vector<char>            labels;            // labels for the graph
  
  /**
   * Depth First Search algorithm that traverses over the graph.
   * 
   * @param v The vertex that needs to be traversed
   ****************************************************************************************/
  void                         Depthfirst(int); 

 public:
  /**
   * Constructor for graph, it initializes the size of graph and loads 
   * the edges/data from the input file.
   * 
   * @param filename The name of the input file from which to read the adjacency matrix.
   ****************************************************************************************/
  Graph(const char* filename);

  /**
   * Destructor for graph, it deletes the global variables to free memory
   ****************************************************************************************/
  ~Graph();

  /**
   * A member function that returns the size of graph or number of vertices.
   * 
   * @return The size of graph
   ****************************************************************************************/
  int  Getsize() const;

  /**
   * A member function of class graph, it initializes iterates over all the vertices and
   * calls Depthfirst() to implement the DFS traversal algorithm.
   ****************************************************************************************/
  void Traverse();

  /**
   * A member function of class graph, it prints the number of vertices, its edges of 
   * the graph.
   ****************************************************************************************/
  void Print() const;
};

#endif  // GRAPH_H
