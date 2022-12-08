//***************************************************************************                                                  
//	Sanoj Oad                                                                
//  Z1980626                                                                 
//  CSCI 340 03                                                              
//                                                                           
//  I certify that this is my own work and where appropriate an extension    
//  of the starter code provided for the assignment.                         
//***************************************************************************

#include "graph.h"      // graph header file
#include <iostream>     // cout, cin, endl
#include <string>       // string, getline
#include <fstream>      // read from file
using namespace std;

// a pointer to point to the array that keeps the track of nodes visited
bool *visited;

// list of pairs of traversing vertices/edges
vector< pair<char, char>> traversePair;

// Implements the DFS Algorithm
void Graph::Depthfirst(int v) 
{
    // marks the vertex v as visited/true
     visited[v] = true;

    cout << labels[v] << " "; //vist the vertex
    
    // checks its edges and visits the remaining vertices
    for ( auto graphIt = adj_list[v].begin(); graphIt != adj_list[v].end(); ++graphIt )
    {
        int w = *graphIt;
        if (!visited[w])
        {
            traversePair.push_back(make_pair(labels[v], labels[w]));
            Depthfirst(w);
        }
    }

} // end of DFS algorithm

// Constructor of class graph
Graph::Graph(const char* filename)
{
    string line;                // reads the line from file
    ifstream infile(filename);  // opens the file and reads it
    int labelIndex;             // stores the vertex that is being initialzed

    // reads and sets the size of the adjacency matrix
    getline(infile, line, '\n');
    // sets the size of graph
    size = stoi( line );

    // creates the adj list of given size
    adj_list.resize(size);
    
    // reads and sets all the labels
    getline(infile, line, '\n');
    for (unsigned int i = 0; i < line.size(); ++i)
    {    
        if ( isalpha( line[i] ) )
            labels.push_back( line[i] );
    }

    // reads the edges from the adjacency matrix
    while ( !infile.eof() )
    {
        getline(infile, line, '\n');    // reads the edges of a vertex from file
        int edge = 0;  // tracks which vertex the edge refers to 
        for ( unsigned int i = 0; i < line.size(); ++i)
        {
            // reads the vertex that is being initialized
            if ( isalpha(line[i]) )
                labelIndex = line[i] - 65; 

            // sets the edges to its respective vertex
            else if ( isdigit(line[i]) ) 
            {
                if ( line[i] == '1' )
                    adj_list.at(labelIndex).push_back( edge );
                ++edge;
            }
        }
    }
}

Graph::~Graph()
{
    // destroys the globally declared pointer
    delete [] visited;
}

int Graph::Getsize() const 
{ 
    // returns the size of the adjacency matrix
    return size;
}

void Graph::Traverse() 
{
    // points to the size number of elements in visited
    visited = new bool[size]; 

    // sets all visited vertices to false
    for ( int i = 0; i < size; ++i)
        visited[i] = false;

    // traversing the graph begins
    cout << "------- traverse of graph ------" << endl;
    
    // for each vertex that is not visited, do a depth first traversal
    for ( int i = 0; i < size; ++i )
    {
        // visit vertex i if not visited
        if ( !visited[i] )
            Depthfirst(i);
    }
    cout << endl;  // newline

    // prints the pairs of vertices visited while traversing
    for ( auto x : traversePair )
        cout << "(" << x.first << ", " << x.second << ") ";

    // end of graph traversing
    cout << "\n--------- end of traverse -------\n" << endl;
}

// prints the size of graph, vertices of graph, and its edges
void Graph::Print() const 
{
    // prints the number of vertices in the graph
    cout << "\nNumber of vertices in the graph: " << Getsize() << endl;
    
    // printing graph begin
    cout << "\n-------- graph -------\n";
    
    // iterates over the vertices
    for ( int i = 0; i < size; ++i )
    {
        cout << labels.at(i) << ": ";   // prints the vertex
        
        // iterator to last element in a vertex
        auto lastIt = adj_list[i].end();
        --lastIt;

        // iterates over the edges in each edge
        for (auto it = adj_list[i].begin(); it != adj_list[i].end(); ++it )
        {
            // prints all other edges
            if ( it != lastIt )
                cout << (char)((*it)+65) << ", ";

            // prints the last edge without the comma
            else   
                cout << (char)((*it)+65) << endl; 
        }
    }
    cout << "------- end of graph ------\n" << endl;    // end of graph
}