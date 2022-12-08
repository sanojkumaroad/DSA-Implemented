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

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "node.h" 	// node header file.
#include "btree.h"	// binary tree header file.

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

/* Function Definations */

/**
 * A template member function that calls its private member function 
 * _Insert() to insert a node into the Binary Search Tree. 
 *
 * @param x The value that needs to be inserted in BST.
 *************************************************************************/
template <typename T>
void BinarySearchTree <T> :: Insert(const T& x)
{
	// Inserts x, if it is not present in the tree.
	if ( !Search(x) )
		_Insert(this->root, x);
}

/**
 * A template member function that calls its private member function 
 * _Search() to search a key in the Binary Search Tree. 
 *
 * @param x The value to be searched in the BST.
 * 
 * @return True	 when x is in the BST.
 * 		   False when x is not in the BST.
 *************************************************************************/
template <typename T>
bool BinarySearchTree <T> :: Search(const T &x) const
{
	// searches for x in the tree.
	return _Search(this->root, x); 
}

/**
 * A template member function that calls its private member function 
 * _Remove() to remove a leaf-node from the Binary Search Tree. 
 *
 * @param x The value to be removed from the BST.
 * 
 * @return True	 when x is removed from the BST.
 * 		   False when x is not removed from the BST.
 *************************************************************************/
template <typename T>
bool BinarySearchTree <T> :: Remove(const T &x)
{
	// check if x is in the tree
	if ( Search(x) )
	{
		// removes x
		_Remove( this->root, x);
		
		// returns true after removing x
		return true;
	}
	
	// otherwise, return false
	return false;
}

/**
 * A private member function that inserts a node into BST. 
 *
 * @param node  The root node of the Binary Search Tree.
 * @param value The value to be inserted in the BST.
 *************************************************************************/
template <typename T>
void BinarySearchTree <T> ::_Insert(Node<T>* &node, const T &value)
{	
	// Inserts the value at the node.
	if(node == nullptr)
		node = new Node <T> ( value );
	
	// Inserts the value to the left of the node.
	else if ( value < node -> data )
		_Insert( node -> left, value );
	
	// Inserts the value to the right of the node.
	else if (value > node -> data)
		_Insert( node -> right, value );
}

/**
 * A private member function to search a key in the Binary Search Tree. 
 *
 * @param node  The root-node of the Binary Search Tree.
 * @param value The value to be searched in the BST.
 * 
 * @return True	 when x is in the BST.
 * 		   False when x is not in the BST.
 *************************************************************************/
template <typename T>
bool BinarySearchTree<T>:: _Search( Node <T> *node, const T &value) const
{	
	// node is null
    if ( node == nullptr )
      return false;
    
	// value is present at node
	if ( node -> data == value )
		return _Leaf( node ); 		// returns true if node is a leaf node.
    
	// value is greater than node's data
    if ( node -> data < value )
       return _Search( node -> right, value );
 
    // value is smaller than node's data
    return _Search( node -> left, value );
}

/**
 * A private member function to remove a key in the Binary Search Tree. 
 *
 * @param node  The root-node of the BST.
 * @param value The value to be searched in the BST.
 *************************************************************************/
template <typename T>
void BinarySearchTree<T>:: _Remove( Node <T>* &node, const T &value)
{
	// node is null
	if ( node == nullptr )
		return;
		
	// checks to the left
	else if ( value < node -> data ) 
		_Remove( node -> left, value );
	
	// checks to the right
	else if ( value > node -> data )
    	_Remove( node -> right, value );
    	
	else // value is found.
	{
		// removes it if it is a leaf node
    	if ( _Leaf ( node ) ) 
		{
        	delete node;
        	node = nullptr;
    	}
	}
}

/**
 * A private member function that checks if a node is leaf or not. 
 *
 * @param node The node to be checked in the BST.
 * 
 * @return True	 when x is a leafnode.
 * 		   False when x is not a leafnode.
 *************************************************************************/
template <typename T>
bool BinarySearchTree<T>:: _Leaf( Node <T>* node ) const
{
	// true if left and right of node is nullptr
	if ( node -> left == nullptr && node -> right == nullptr)
		return true;
	return false;
}

#endif // End of BINARYSEARCHTREE_H_
