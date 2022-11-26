//***************************************************************************
//
//  Sanoj Oad
//  Z1980626
//  CSCI340 - Section 3
//
//  I certify that this is my own work and where appropriate an extension 
//  of the starter code provided for the assignment.
//
//***************************************************************************

#include "matrix.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;    // This is OK here because it concerns the namespace of this file only

/*
   This program opens two data files for reading. If either file can't
   be opened, it prints an error message on stderr and aborts the
   program. It generates two input matrices from the data in data
   files, then generates a new matrix by multiplying the numbers in
   two input matrices. Finally, it prints all three matrices on
   stdout.
*/

ifstream safeopen(const string &fname)
{
    ifstream f;
    try {
        f.open(fname, std::ifstream::in); //opens the file to read.
    } catch (const std::ios_base::failure &e) {
        cerr << e.code().message() << endl;
        exit(1);        // nonzero here means to the O/S that the application has failed
    }
    return f;
}

int main(int argc, char **argv)
{
    ifstream is1;
    ifstream is2;
    int col_width;

    if (argc != 4)      // make sure we have 4 command line args
    {
        cerr << "Usage: matmul file1 file2 colwidth" << endl;
        exit(1);
    }
        
    is1 = safeopen(argv[1]);
    is2 = safeopen(argv[2]);

    istringstream iss(argv[3]);     // convert the C string to an istringstream
    iss >> col_width;               //    ...so we can do this to convert it into an int

    matrix a;
    matrix b;
    matrix c;

    a.load(is1);        // resize & deserialize
    b.load(is2);        // resize & deserialize

    c = a*b;            // the memberwise copy of std::vector in here will deep-copy themselves!

    // print contents of all matrices on stdout
    cout << "\nMatrix1: ";
    a.print(col_width);
    cout << "\nMatrix2: ";
    b.print(col_width);
    cout << "\nMatrix3: ";
    c.print(col_width);
    cout << endl;


    // Note: is1 and is2 are closed here when they go out of scope
    return 0;   // zero here tells the O/S that the application has succeeded
}
