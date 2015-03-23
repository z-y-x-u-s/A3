#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/** Henry Jason Biem 260590556 **/

/*Typedefs to be used by the below functions */
typedef int BOOLEAN;

typedef struct NODE
{
        int value;
        struct NODE* next;
} aNode;

/* This is my global header/root node. It is accesible
   by each invocation of the below functions */
aNode* root;

/* This counter allows for the root's  creation once
    a correct file  be inputed by the user */
int i = 0;

/* Creates and then adds a new node to the linked List each time */
void add(int input)
{
        aNode* freeSpot;                                // Declaration of Linked List node pointers.
        aNode* newNode;

        if(i == 0)                                      // If this is the first invocation of this function,
        {
                root = (aNode *) malloc(sizeof(aNode)); // Create the global root node in dynamic memory.
                root-> next = NULL;                     // Initialize its 'next' field to NULL.
        }
        i++;                                            // Counts the number of times this function was called.

        freeSpot = root;                                // Start from the global root node with the 1st pointer.
        while(freeSpot->next != NULL)                   // Iterate through the linked list until the freeSpot pointer
        {                                               // finds a node with a NULL 'next' field.
                freeSpot = freeSpot->next;              // This line moves the pointer to the next node in the list.
        }

        newNode = (aNode *) malloc(sizeof(aNode));      // Creation and initialization of a new node with the 2nd pointer.
        newNode -> value= input;
        newNode -> next = NULL;
        freeSpot->next = newNode;                       // Add this newly created node to the end of the Linked List.
}

/* This method prints out all the nodes in the linked list */
void prettyPrint()
{
        aNode* printHere;                                       // Declaration of a node pointer.
        printHere = root->next;                                 // Point to the first node after the root.
        printf("Content of list is :");

        while(printHere != NULL)                                // While the node that printHere points to exists,
        {
                printf(" %i ", printHere->value);               // Print out the 'value' field.
                printHere = printHere->next;                    // Proceed to the next node.
        }
        printf( "\n");
}

/* This method finds the first node whose value matches the input */
struct NODE* find(int input)
{

        struct NODE* newNode;                                   // Declaration of the node pointer.
        newNode= root;                                          // Point to the root node.

        while(newNode->next != NULL)                            // While the next node exists,
        {
                newNode = newNode->next;                        // Point to the next node.
                if(newNode->value == input)                     // If the node's 'value' field matches input,
                {
                        return(newNode);                        // Return the node pointer.
                }
        }
        return NULL;                                            // Else, return NULL.
}

/* This method deletes the node found by the above function */
BOOLEAN delete(int input)
{
        aNode* newNode;                                         // Declaration of node pointers.
        aNode* nextNewNode;
        newNode =(struct NODE*) find(input);                    // The 1st pointer points to the found node

        if(newNode == NULL) return FALSE;                       // If no pointer was returned, return FALSE.
        else
        {       if(newNode->next !=NULL)                        // If the pointed-to node is not the end node,
                {
                        nextNewNode = newNode -> next;          // The 2nd pointer now  points to the next node.
                        newNode->value = nextNewNode-> value;   // Copy the next node into the found node.
                        newNode->next = nextNewNode -> next;
                        free(nextNewNode);                      // Free the next node from dynamic memory.
                }
                else
                {
                        nextNewNode= root;                      // If the pointed-to node is the end node,
                        while((nextNewNode->next)->next != NULL)// This while loop finds the penultimate node.
                        {
                                nextNewNode= nextNewNode->next;
                        }
                        nextNewNode->next= NULL;                // Sever the connection to the last node.
                        free(newNode);                          // Free the found node from dynamic memory.
                }

        }
        return TRUE;                                            // Return TRUE once deletion has occured.
}







