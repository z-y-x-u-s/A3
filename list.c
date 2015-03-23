#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0

/** Henry Jason Biem 260590556 **/

typedef int BOOLEAN;
typedef struct NODE
{
        int value;
        struct NODE* next;
} aNode;

aNode* root;
int i = 0;

void add(int input)
{
        if(i == 0)
        {
                root = (aNode *) malloc(sizeof(aNode));
                root-> next = NULL;
        }
        i++;

        aNode* newNode;
        aNode* freeSpot;

        newNode = (aNode *) malloc(sizeof(aNode));
        newNode -> value= input;
        newNode -> next = NULL;

        freeSpot = root;
        while(freeSpot->next != NULL)
        {
                freeSpot = freeSpot->next;
        }
        freeSpot->next = newNode;
}

void prettyPrint()
{
        aNode* printHere;
        printHere = root->next;
        printf("Content of list is :");
        while(printHere != NULL)
        {
                printf(" %i ", printHere->value);
                printHere = printHere->next;
        }
        printf( "\n");
}

struct NODE* find(int input)
{
        struct NODE* newNode;
        newNode= root;

        while(newNode->next != NULL)
        {
                newNode = newNode->next;
                if(newNode->value == input) return(newNode);
        }
        return NULL;
}

BOOLEAN delete(int input)
{
        aNode* newNode;
        aNode* nextNewNode;
        newNode =(struct NODE*) find(input);
        if(newNode == NULL) return FALSE;
        else
        {       if(newNode->next !=NULL)
                {
                        nextNewNode = newNode -> next;
                        newNode->value = nextNewNode-> value;
                        newNode->next = nextNewNode -> next;
                        free(nextNewNode);
                }
                else
                {
                        nextNewNode= root;
                        while((nextNewNode->next)->next != NULL) nextNewNode= nextNewNode->next;
                        nextNewNode->next= NULL;
                }

        }
return TRUE;
}





