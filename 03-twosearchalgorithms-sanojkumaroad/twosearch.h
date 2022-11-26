#ifndef twosearch_H
#define twosearch_H

// Only include those headers that are required by the rest of contents 
// of this header file.
#include <bits/stdc++.h> //for iterators in LS.
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iterator>
// No using statements here.

void init_vector(std::vector<int> &vec, int seed, int lo, int hi);
void print_vector(const std::vector<int> &v, int print_cols, int col_width);
void sort_vector(std::vector<int> &v);
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int));
void print_stat(int found, int total);
bool linear_search(const std::vector<int> &v, int x);
bool binary_search(const std::vector<int> &v, int x);

void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
	int k = 0;
	srand(seed);
	for (unsigned int i = 0; i < vec.size(); ++i)
	{
		k = (rand()%(hi-lo+1)+lo);
		vec.at(i) = k;
	}	
}

void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
	//Printing top '-'
	for (int i = 0; i < (6*print_cols+1); i++)
		std::cout<<'-';
	std::cout<<std::endl;
	
	for (int i = 0, z = 0; i < (int(v.size())/print_cols)+1; i++ )
	{
		for(int j = 0; j < print_cols; j++)
		{
			if( (z) < int(v.size()) )
				std::cout<<'|'<<std::setw(col_width)<<v[z++]<<' ';
			else
				std::cout<<'|'<<std::setw(col_width+2);
		}
		std::cout<<'|'<<std::endl;
	}

	for (int i = 0; i < (6*print_cols+1); i++)
		std::cout<<'-';
	std::cout<<std::endl;
}

void sort_vector(std::vector<int> &v)
{
	std::sort(v.begin(), v.end()); // ascending order.
}

int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
	int search_count = 0;

	for(auto i : v1)
	{
		if ( p(v2,i) )
			search_count += 1;
	}
	return search_count;
}

void print_stat(int found, int total)
{
	std::cout<<"Percent of Successful Searches = "<<std::fixed<<std::setprecision(2)<<((found*1.0)/total)*100<<"%"<<std::endl;
}

bool linear_search(const std::vector<int> &v, int x)
{
	//const std::vector<int>::iterator it;
        auto it = std::find(v.begin(), v.end(), x);
	
	if (it != v.end())
	{
	   return true;
	}
	else
	{
	    return false;
	}
}

bool binary_search(const std::vector<int> &v, int x)
{	
	if (std::binary_search(v.begin(), v.end(), x))
	{
	   return true;
	}
	else
	{
	    return false;
	}
}

#endif
