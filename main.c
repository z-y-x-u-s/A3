#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        {
                nextNewNode = newNode -> next;
                newNode->value = nextNewNode-> value;
                newNode->next = nextNewNode -> next;
                free(nextNewNode);
        }
return TRUE;
}

int main(int argc, char *argv[])
{
        FILE *file_ptr, *file_ptr2;
        char filename[500];
        char garbage;
        char beingCareful[500], answer[500];
        char lineReading[500];
        int readNumber, boolean;
        int fileLineLength;
        int j;
        do {
                printf("Please provide a valid filepath with the proper extension to be opened: \n");
                scanf("%499[^\n]", filename);

                garbage=getchar();
                while (garbage !=10)
                {
                        garbage = getchar();
                }

                file_ptr=fopen(filename, "rt");

        } while (file_ptr ==NULL);

        j=0;
        strcpy(lineReading, "wc -l < ");
        strcat(lineReading, filename);
        strcat(lineReading, " > LineNumber.txt");
        system(lineReading);
        file_ptr2= fopen("LineNumber.txt", "rt");
        fgets(beingCareful, 499, file_ptr2);
        fileLineLength = atoi(beingCareful);
        fclose(file_ptr2);
        //printf("%d \n \n", fileLineLength);

        while(!feof(file_ptr))
        {
        fgets(beingCareful, 499, file_ptr);
        readNumber= atoi(beingCareful);
        add(readNumber);
        j++;
        if(j==fileLineLength) break;
        }
        fclose(file_ptr);
        prettyPrint();

        do
        {
                printf("What integer would you like to be removed? The first one found will be deleted \n");
                boolean=0;
                scanf("%499[^\n]", beingCareful);
                readNumber= atoi(beingCareful);
                garbage=getchar();

                if(delete(readNumber)) prettyPrint();
                else
                {
                        printf("Number not found!");
                }

                printf("Would you like to delete another number? \n");
                scanf("%499[^\n]", answer);
                garbage=getchar();

                /*If the inputed string matches one of the 4 answers, the boolean variable is set to true (+1) */
                switch(strlen(answer))
                {
                        case 1:
                        if (strcmp("Y", answer) == 0 || strcmp("y", answer) == 0) boolean = 1;
                        break;

                        case 3:
                        if (strcmp("YES", answer) == 0 || strcmp("yes", answer) == 0 || strcmp("Yes", answer))  boolean = 1;
                        break;

                        default:
                        break;
                }

        } while(boolean ==1);
}

