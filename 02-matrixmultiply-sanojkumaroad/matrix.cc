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

#include"matrix.h" //includes the matrix.h header file given for this assignment.
#include<iostream> // includes the cout and cin functions for printing.
#include<cassert> // includes the assert() function to catch an error for checking the matrix compatibility.
#include<iomanip> // includes the setw() function to format the output matrix printing.

using namespace std;

//matrix constructor
matrix::matrix(unsigned int rows, unsigned int cols)
{
	matrix::resize(rows, cols); // resize function call.
}

void matrix::resize(unsigned int rows, unsigned int cols)
{
	mat.resize(rows); //Sets the number of rows.
	
	//Sets the number of items each row will have, that is the number of columns.
	for (unsigned int i = 0; i < rows; i++)
	{
		mat.at(i).resize(cols);
	}
}

void matrix::load(istream &is)
{
	unsigned int loadRows; // Reads and store the number of rows in the matrix from the file.
	unsigned int loadCols; // Reads and store the number of columns in the matrix from the file.

	is >> loadRows;
	is >> loadCols;

	resize(loadRows, loadCols); // Resizes the matrix to the dimensions provided.
	
	//this loop reads matrix values from the file and assigns them to the mat vector.
	for (unsigned int i = 0; i < loadRows; i++)
	{
		for (unsigned int j = 0; j < loadCols; j++)
		{
			is >> mat.at(i).at(j);
		}
	}
}

// function to print the matrix.
void matrix::print(int colWidth) const
{
	//prints the matrix dimensions.
	cout<<getRows()<<" x "<<getCols()<<endl;
	
	//Printing the Dashed Lines to format the output.
	unsigned int dashLength = 8*getCols(); // number of times the - has to be printed.	
	for (unsigned int i = 0; i <= dashLength; i++)
	{
		cout<<"-";
	}
	cout<<endl;
	
	//Printing the Matrix Values.
	for(unsigned int i = 0; i < mat.size(); i++)
	{
		for(unsigned int j=0; j < mat[i].size(); j++)
		{
			cout<<"|"<<setw(colWidth)<<mat.at(i).at(j)<<" ";
		}
		cout<<"|"<<endl;
	}

	//Printing the bottom dashed line to format the output.
	for (unsigned int i = 0; i <= dashLength; i++)
	{
		cout<<"-";
	}
	cout<<endl;
}

//operator overload function that multiplies the two matrices and returns a new matrix with the results.
matrix matrix::operator*(const matrix &rhs) const
{
	//Checks if the columns of Matrix 1 are equal to the Rows of Matrix 2.
	assert(getCols() == rhs.getRows());
	
	//Creates product Matrix.
	matrix M;
	
	//Resizing the resultant matrix to store the product of matrices.
	M.resize(getRows(), rhs.getCols());
	
	// Matrix Multiplication Algorithm Implemented.
	for (unsigned int i = 0; i < M.getRows(); i++)
	{
		for (unsigned int j = 0; j < M.getCols(); j++ )
		{
		       	for (unsigned int k = 0; k < rhs.getRows(); k++)
			{
				M.at(i,j) += (at(i,k) * rhs.at(k,j));
			}
		}
	}
	
	//returning the result/product matrix.
	return M;
}

