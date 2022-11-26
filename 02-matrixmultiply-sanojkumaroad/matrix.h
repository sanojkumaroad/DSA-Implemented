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

#ifndef H_MATRIX_MULTIPLY
#define H_MATRIX_MULTIPLY

#include <istream>
#include <vector>

class matrix
{
public:
    
   /**
    * Constructor function that initializes the matrix.
    * 
    * It initializes and set the number of rows and columns in a matrix.
    *
    * @param rows Number of rows this matrix will have.
    * @param cols Number of columns this matrix will have.
    ********************************************************************************/
    matrix(unsigned int rows=0, unsigned int cols=0);
    
   /**
    * This function is called with inside the constructor function and it basically resizes the matrix.
    *
    * @param rows Number of rows this matrix will have.
    * @param cols Number of columns this matrix will have.
    ********************************************************************************/
    void resize(unsigned int rows, unsigned int cols);
    
   /**
    * loads the data from the file to the matrix.
    * 
    * It starts with reading the matrix dimensions and then reads the matrix data/values and assigns to the given matrix.
    *
    * @param is A pointer that points to the data that will be loaded in the matrix.
    ********************************************************************************/
    void load(std::istream &is);
    
   /**
    * Prints the Matrix dimensions and its values.
    *
    * @param colWidth A variable to set the column width in formatting and printing the matrix values.
    ********************************************************************************/
    void print(int colWidth) const;

   ///Overloads the at() to store/refer to a location within a specific row and column inside the matrix.
    const int & at(unsigned int row, unsigned int col) const
    {
        return mat[row][col];       ///@note mat[row] returns a reference to the col vector
    }

    ///Overloads the at() to store/refer to a location within a specific row and column inside the matrix.
    int & at(unsigned int row, unsigned int col)
    {
        return mat[row][col];       ///@note mat[row] returns a reference to the col vector
    }
    
   /**
    * Overloads the operator * to multiply the two matrix.
    *
    * e.g. C = A*B where A, B, C are the matrices. 
    *
    * @matrix& points to the address of matrix on the right hand side of the operator *. 
    *
    * @return The matrix storing the result of multiplication of two matrices.
    ********************************************************************************/
    matrix operator*(const matrix&) const; 

   ///Returns the number of rows or the size of mat vector.
    unsigned int getRows() const { return mat.size(); }

   /// Gets the number of columns in the matrix.
   /// @note if have 0 rows then we have no col vectors to ask about their size!
    unsigned int getCols() const { return (getRows()==0? 0 : mat[0].size()); }

private:

    // can't use vector<vector<int> > A(nrows, vector<int>(ncols)) notation because might 
    // not know the dimension when constructed.
    std::vector<std::vector<int>> mat;      ///< rows is the outer vector. be careful with the >>
};

#endif
