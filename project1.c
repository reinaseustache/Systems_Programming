// Reina Eustache 
// Project 1: "Linked List"
// Due 02/21/2020 11:59 pm
// project1.c
// This file contains functions that manipulate items in a linked list. It
// cointains funtions to add at the end or after a node, search for a node,
// print a node, print the list, delete a node or delete the entire list.
// It also has a main function that tests all of these functions.

#include "project1.h"

int main(int argc, char *argv[]) {
    NODE *head = NULL; // stores the head of the list
    NODE *aNode = NULL; // node pointer to store a return value

    head = add_At_End(head, 0);
    head = add_At_End(head, 1);
    head = add_At_End(head, 1);
    head = add_At_End(head, 2);
    head = add_At_End(head, 3);
    head = add_At_End(head, 5);
    head = add_At_End(head, 8);
    head = add_At_End(head, 13);
    head = add_At_End(head, 21);
    head = add_At_End(head, 34);
    head = add_At_End(head, 55);
    head = add_At_End(head, 89);
    head = add_At_End(head, 144);

    printf("\nThe list after calling add_At_End with the 1st 13 values of the Fibonacci sequence: ");
    print_List(head);
    printf("\n");
    
    head = delete_Node(head, 13);
    printf("\nThe list after calling delete_Node on 13: ");
    print_List(head);
    printf("\n");

    head = delete_Node(head, 0);
    printf("\nThe list after calling delete_Node on 0: ");
    print_List(head);
    printf("\n");

    head = delete_Node(head, 200);
    printf("\nThe list after calling delete_Node on 200 (not in the list): ");
    print_List(head);
    printf("\n");

    aNode = search(head, 89);
    printf("\nValue returned when calling print_Node on pointer returned from passing 89 to the search function: ");
    print_Node(aNode);
    printf("\n");

    aNode = search(head, 0);
    printf("\nValue returned when calling print_Node on pointer returned from passing 0 (not in list) to the search function: ");
    print_Node(aNode);
    printf("\n");

    aNode = search(head, 1);
    printf("\nValue returned when calling print_Node on pointer returned from passing 1 to the search function: ");
    print_Node(aNode);
    printf("\n");

    head = delete_List(head);
    printf("\nThe list after calling delete_List: ");
    print_List(head);
    printf("\n");

    printf("\nCalling print_Node passing head: ");
    print_Node(head);
    printf("\n");

    head = add_At_End(head, 13);
    head = add_At_End(head, 21);
    head = add_At_End(head, 34);
    head = add_At_End(head, 55);

    printf("\nThe list after calling add_At_End with the 4 values: ");
    print_List(head);
    printf("\n");

    head = insert_Node(head, 119, 13);

    printf("\nThe list after calling insert_Node after 13 with value 119: ");
    print_List(head);
    printf("\n");

    head = insert_Node(head, 2901, 34);

    printf("\nThe list after calling insert_Node after 34 with value 2901: ");
    print_List(head);
    printf("\n");

    head = insert_Node(head, 77, 43);

    printf("\nThe list after calling insert_Node after 43 (not in list) with value 77: ");
    print_List(head);
    printf("\n");

    head = insert_Node(head, 111, 55);

    printf("\nThe list after calling insert_Node after 55 with value 111: ");
    print_List(head);
    printf("\n");

    head = delete_List(head);
    printf("\nThe list after calling delete_List: ");
    print_List(head);
    printf("\n");

    free(head);
    free(aNode);

    return 0;
}

NODE *add_At_End(NODE *head, int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE)); // allocate memory
    temp->data = data;
    temp->next = NULL;

    if(head == NULL){ // check if list is empty
        head = temp;
    }
    else {
        NODE *current = head;

        while(current->next != NULL)
            current = current->next;
        current->next = temp;
    }

    return head;
}

NODE *delete_Node(NODE *head, int data){
    if(head != NULL){ // check if list is not empty
        NODE *temp = head;
        NODE *prev = head;

        if(temp->data == data){ // check if it is head element
            head = head->next;
            free(temp);
        }
        else{
            while(temp != NULL){
                if(temp->data == data){
                    prev->next = temp->next;
                    free(temp);
                }
                prev = temp;
                temp= temp->next;
            }
        }
    }
    return head;
}

NODE *insert_Node(NODE *head, int data, int afterVal){
    NODE *afterNode = search(head, afterVal); // search for a node to insert after

    if (afterNode != NULL){ // if that node is in the list
        NODE *temp = (NODE *)malloc(sizeof(NODE)); // allocate memory
        temp->data = data;
        temp->next = NULL;

        temp->next = afterNode->next;
        afterNode->next = temp;
    }

    return head;
}

NODE *search(NODE *head, int data){
    NODE *current = head;

    while(current != NULL){ // iterate through entire list
        if(current->data == data) // check value in current node
            return current;
        current = current->next;
    }
    return NULL;
}

void print_Node(NODE *theNode){
    if (theNode == NULL){ // check if a valid node is passed in
        printf("NULL");
    }
    else{
        printf("%d ", theNode->data);
    }
}

void print_List(NODE *head){
    NODE *temp = head;

    while(temp != NULL){ // iterate through entire list
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

NODE *delete_List(NODE *head){
    NODE *temp;

    while(head != NULL){ // iterate through entire list
        temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}