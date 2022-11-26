#ifndef RATIONAL_H
#define RATIONAL_H

//***************************************************************************
//  
//  Sanoj Oad
//  Z1980626
//  CSCI 340 03
//  
//  I certify that this is my own work and where appropriate an extension
//  of the starter code provided for the assignment.
//
//  rational.h
//  CSCI 241 Operator Overloading Example
//  Created by Kurt McMahon (t90kjm1)
//
// See: http://faculty.cs.niu.edu/~winans/CS501/#operator_overloading
//
//***************************************************************************

#include <iostream>

class Rational
{
    // Overload the stream insertion and extraction operators as standalone
    // functions - can't be done as member functions
    friend std::ostream& operator<<(std::ostream&, const Rational&);
    friend std::istream& operator>>(std::istream&, Rational&);

    // Overload addition operator with int as left operand - can't be done as a 
    // member function
    friend Rational operator+(int, const Rational&);
    
public:
   
    // Constructors
    Rational() = default;
    Rational(int, int);

    // Function to display fraction as a floating-point number
    void display_float() const;

    // Accessor and mutator methods      
    int get_numerator() const;
    int get_denominator() const;
      
    void set_numerator(int);
    void set_denominator(int);
    void set_rational(int, int);

    // Overloaded arithmetic operators
    Rational operator+(const Rational&) const;
    Rational operator-(const Rational&) const;
    Rational operator*(const Rational&) const;
    Rational operator/(const Rational&) const;

    // Addition with int as right operand
    Rational operator+(int) const;                      
            
    // Overloaded relational operators
    bool operator==(const Rational&) const;
    bool operator<(const Rational&) const;
    bool operator<=(const Rational&) const;
    bool operator>(const Rational&) const;
    bool operator>=(const Rational&) const;
    bool operator!=(const Rational&) const;

private:
    
    int numerator{1};
    int denominator{1};
      
    int find_gcd(int, int) const;     // Find greatest common divisor
    int find_lcm(int, int) const;     // Find least common multiplier
};
   
#endif /* RATIONAL_H */
