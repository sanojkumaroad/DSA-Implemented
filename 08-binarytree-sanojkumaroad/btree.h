//***************************************************************************
//  Sanoj Oad
//  Z1980626
//  CSCI 340 03
//
//  I certify that this is my own work and where appropriate an extension 
//  of the starter code provided for the assignment.
//***************************************************************************

#ifndef H_BTREE
#define H_BTREE

#include "node.h" 	// Node.h Header file for node class.

/// enum to random chose left or right subtree for insertion.
typedef enum {left_side, right_side } SIDE;
SIDE rnd() { 
    return rand()%2 ? right_side : left_side;
}// End of rnd()

// Class Binary Tree
template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

/* Function Definations */

/**
 * The default constructor of template class BinaryTree.
 *************************************************************************/
template <typename T>
BinaryTree <T> :: BinaryTree()
{
	/// sets root to null.
	root = nullptr;
}
    
/**
 * A template member function that calls its private member function 
 * _getSize() to get the number of nodes or size of the binary tree. 
 *
 * @return unsigned int value that is the size of binary tree.
 *************************************************************************/
template <typename T>
unsigned BinaryTree <T> :: getSize() const
{
	return _getSize(root);
}

/**
 * A template member function that calls its private member function 
 * _getHeight() to get the height of the binary tree.
 *
 * @return unsigned int value that is the height of binary tree.
 *************************************************************************/
template <typename T>
unsigned BinaryTree <T> :: getHeight() const
{
	return _getHeight(root);
}   
	
/**
 * A template member function that calls its private member function 
 * _Insert() to insert a node in the binary tree.
 *
 * @param value The value of a node that needs to be inserted in Binary Tree.
 ****************************************************************************/
template <typename T>
void BinaryTree <T> :: Insert(const T& value)
{
	// private member function
	// passing root and the node value.
	_Insert(root, value);
}
	
/**
 * A template member function that calls its respective private member 
 * function _Inorder() to perform inorder traversal of the binary tree.
 * It also prints each node value while traversing the tree.
 *
 * @param printNode It is a function passed by reference that prints a
 * 			single value/node of a binary tree.
 *************************************************************************/
template <typename T>
void BinaryTree <T> :: Inorder( void (*printNode) (const T&) )
{
	if(root != nullptr)
	{
		_Inorder(root, printNode);
	}
}
	
/**
 * A template function that is the private version of getSize(). This is 
 * a recursive function used to get the size of Binary Tree.
 * 
 * @param node The starting node (or root-node) of the Binary Tree.
 * 
 * @return The size of the Binary Tree starting from the given node.
 * ************************************************************************/
template <typename T>
unsigned BinaryTree <T> :: _getSize( Node<T> *node ) const
{
	if (node == NULL)
		return 0;
	else
		// recursive function call for left and right node.
		return( _getSize(node->left) + 1 + _getSize(node->right) );
}
	
/**
 * A template function that is the prviate version of getHeight(). It calcu-
 * lates the height of the tree and returns it.
 * 
 * @param node The starting node (or root-node) of the Binary Tree.
 *
 * @return The height of the Binary Tree starting from the given node.
 * *************************************************************************/
template <typename T>
unsigned BinaryTree <T> :: _getHeight( Node<T> *node ) const
{
	if (node == NULL)
		return 0;
	else {
       		/* compute the depth of each subtree */
 	   	int lDepth = _getHeight(node->left);
        	int rDepth = _getHeight(node->right);
 
        	/* use the larger one */
        	if (lDepth > rDepth)
           		return (lDepth + 1);
        	else
            		return (rDepth + 1);
    	}
}
    
/**
 * A template function that is the private version of Insert(). It inserts 
 * the value (or node) in the Binary Tree.
 *
 * @param node The root-node of the Binary Tree.
 * @param value The node (or value) that needs to be inserted in the tree.
 * *************************************************************************/
template <typename T>
void BinaryTree <T> :: _Insert( Node<T> *&node, const T& value )
{	
	// root-node is empty then insert the value the root node.
	if (node == nullptr)
	{
		Node<T> *newNode; 			// creates a new node.
		newNode = new Node<T> ( value );	// inserts the value into the node.
		node = newNode; 			// replaces the node newNode.
    	} 

	// otherwise, rootnode is not empty, insert the node in left or right sub-tree
	else 
	{
		SIDE s;		// enum SIDE
    		s = rnd();	// gets a random side left or right.
    		
		if (s == right_side)
    		{
			// inserts the new value/node to the rightside.
			_Insert( node->right, value );
		}
    		else
    		{
			// inserts the new value/node to the leftside.
			_Insert(node->left, value);	
		}
	}
}

/**
 * A template function that is the private version of Inorder(). This recursively 
 * performs inorder traversal of the binary tree.
 *
 * @param node The root-node of the binary tree to start traversing from.
 * @param function A function passed by reference that prints the single value
 * 			of a given node.
 *
 * ********************************************************************************/
template <typename T>
void BinaryTree <T> :: _Inorder( Node<T> *node, void (*function)(const T& value) )
{
	// traverses the binary tree when the root node is not empty.
	if(node != nullptr)
	{
		_Inorder(node->left, function);		// traverses the left node/sub-tree.
		function(node->data);			// traverses the root-node.
		_Inorder( node ->right, function);	// traverses the right node/sub-tree.
	}
}

#endif // End of H_BTREE
