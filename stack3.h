// FILE: stack3.h (part of the namespace main_savitch_7A)
// TEMPLATE CLASS PROVIDED: Stack<Item> -- with a peek( ) function!
//
// TEMPLATE PARAMETER, TYPEDEFS and MEMBER CONSTANTS for the Stack<Item> class:
//   The template parameter, Item, is the data type of the items in the Stack,
//   also defined as Stack<Item>::value_type. It may be any of the C++ built-in
//   types (int, char, etc.), or a class with a default constructor, a copy
//   constructor, and an assignment operator. The definition
//   Stack<Item>::size_type is the data type of any variable that keeps track of
//   how many items are in a Stack. The static const CAPACITY is the
//   maximum capacity of a Stack for this first Stack implementation.
// NOTE:
//   Many compilers require the use of the new keyword typename before using
//   the expressions Stack<Item>::value_type and Stack<Item>::size_type.
//   Otherwise the compiler doesn't have enough information to realize that it
//   is the name of a data type.
//
// CONSTRUCTOR for the Stack<Item> template class:
//   Stack( )
//     Postcondition: The Stack has been initialized as an empty Stack.
//
// MODIFICATION MEMBER FUNCTIONS for the Stack<Item> class:
//   void push(const Item& entry)
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been pushed onto the Stack.
//
//   Item pop( )
//     Precondition: size( ) > 0.
//     Postcondition: The top item of the Stack has been removed.
//
// CONSTANT MEMBER FUNCTIONS for the Stack<Item> class:
//   bool empty( ) const
//     Postcondition: Return value is true if the Stack is empty.
//
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the Stack.
//
//   Item top( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the top item of the Stack but the
//     Stack is unchanged. This differs slightly from the STL Stack (where
//     the top function returns a reference to the item on top of the Stack).
//
//   Item peek(size_type i) const
//     Precondition: size( ) >= i and i > 0.
//     Postcondition: The return value is the item that is i from the top
//     (with the top at i=1, the next at i=2, and so on).
//     The Stack is unchanged.
//
//  VALUE SEMANTICS for the Stack<Item> class:
//     Assignments and the copy constructor may be used with Stack<Item>
//     objects.

#ifndef MAIN_SAVITCH_Stack3_H
#define MAIN_SAVITCH_Stack3_H

#include <cstdlib> // Provides size_t

namespace main_savitch_7A
	{

	template<class Item>
	struct Node
	{
		int data;
		Node* next;
	};

	/*template<class Item>
    struct Node
    {
        Node* link;
        Item value;
    };*/

	template <class Item>
	class LinkedList
	{
	public:
		typedef std::size_t size_type;
		static const size_type CAPACITY = 30;
		
		// These 3 functions Need to change if the stack grows down!
		// CONSTRUCTOR
		//Stack( );
		//~Stack();
		// CONSTANT MEMBER FUNCTIONS
		void initNode( Node *head,int n);
		void addNode( Node *head, int n);
		void insertFront( Node **head, int n);
	    Node *searchNode( Node *head, int n);
		bool deleteNode( Node **head, Node *ptrDel);
		void copyLinkedList( Node *node, Node **pNew);
		int compareLinkedList( Node *node1, Node *node2);
		void deleteLinkedList( Node **node);
		void display( Node *head);


		//bool empty( ) const { return (stackPointer == nullptr); }
		size_t size( ) const { return used; }
		
		// The folowing does NOT change even if the stack grow down!
		// MODIFICATION MEMBER FUNCTIONS
		void push(const Item& entry);
		Item pop( );
		// CONSTANT MEMBER FUNCTIONS
		Item top( ) const;
		Item peek(size_type index);
	private:
		//Item data[CAPACITY];        // Partially filled array
		size_t used; 
		Node<Item>* head;

		//Node<Item>* stackPointer ;            // How much of array is being used
	};
	}

#include "stack3.tpp.h" // Include the implementation.
#endif

