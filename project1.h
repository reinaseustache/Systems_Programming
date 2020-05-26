// Reina Eustache
// Project 1: "Linked List"
// Due 02/21/2020 11:59 pm
// project1.h
// This header file contains header files along with the struct
// definitions and function prototypes needed in project1.c.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; // stores a value inside each node
        
    struct node *next; // pointer to store a next item
} NODE;

// NODE *add_At_End
// Description: This function allocates memory for a new NODE with
// the data passed in then checks if the list is empty to modify
// head. If the list is not empty the a temporary pointer iterates
// through the list searching for the last node to insert after.
// It accepts the head node, an integer with the value for the new
// node
// It returns a NODE pointer for the head of the new list with the
// inserted NODE at the end
NODE *add_At_End(NODE *head, int data);

// NODE *delete_Node
// Description: This function first checks if the list contains items
// and if it does, it creates a temporary pointer to head and another 
// pointer to store the previous node.  If the data in the node being
// deleted matches the head then the next node is assigned as the new 
// head and free is called on temp othersiwe we iterate through the list
// moving both pointers while searching for the node to free.
// It accepts the head node for the list and an integer for the value 
// inside the NODE to delete
// It returns a NODE pointer for the head of the new list or if the value
// was not found then the head of the original list
NODE *delete_Node(NODE *head, int data);

// NODE *insert_Node
// Description: This function first calls the search funtion on the 
// value passed in to insert after to see if it exists, it it does
// space is allocated for the new node and it is inserted after the 
// pointer returned by the search function. If that value to insert
// after was not found, the head pointer for the original list is
// returned.
// It accepts the head node, an integer with the value for the new
// node and an integer with the value to insert after
// It returns a NODE pointer for the head of the new list with the
// inserted NODE or the head of the original list if it could not
// be inserted successfully
NODE *insert_Node(NODE *head, int data, int afterVal);

// NODE *search
// Description: This function first creates a temporary pointer to the head, 
// then iterates through the list checking if the values inside each node
// matches the value passed in as a parameter.
// It accepts the head node for the list and the integer value to look for
// It returns a pointer to the NODE with that value otherwise it returns 
// NULL indicating the value was not found.
NODE *search(NODE *head, int data);

// void print_Node
// Description: This function first checks if the node pointer passed is NULL
// otherwise it accessses the data value inside the node to print.
// It accepts the pointer to the node that should be printed
void print_Node(NODE *theNode);

// void print_List
// Description: This function prints the entirety of the linked list, by first  
// creating a temporary pointer to the head and iterating through the list.
// It accepts the head node for the list that should be printed
void print_List(NODE *head);

// NODE *delete_List
// Description: This function deletes the entirety of the linked list, by first  
// creating a temporary pointer to the head, saving the node that follows
// and iterating through the list calling free on each node.
// It accepts the head node for the list that should be printed
// It returns a NODE pointer for the head of a list after it is empty 
// which should always be NULL
NODE *delete_List(NODE *head);