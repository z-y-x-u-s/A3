#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#include "list.h"

/** Henry Jason Biem 260590556 **/

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
                printf("What integer would you like to be removed? The first one found will be deleted: \n");
                boolean=0;
                scanf("%499[^\n]", beingCareful);
                readNumber= atoi(beingCareful);
                garbage=getchar();

                if(delete(readNumber))
                {
                        printf("NUMBER WAS DELETED! \n");
                        prettyPrint();
                }

                else
                {
                        printf("NUMBER WAS NOT FOUND! \n");
                        prettyPrint();
                }

                printf("Would you like to delete another number? Enter either Y, y, Yes, YES, or yes. \n");
                scanf("%499[^\n]", answer);
                garbage=getchar();

                /*If the inputed string matches one of the 5 answers, the boolean variable is set to true (+1) */
                switch(strlen(answer))
                {
                        case 1:
                        if (strcmp("Y", answer) == 0 || strcmp("y", answer) == 0) boolean = 1;
                        break;

                        case 3:
                        if (strcmp("YES", answer) == 0 || strcmp("yes", answer) == 0 || strcmp("Yes", answer) ==0)  boolean = 1;
                        break;

                        default:
                        break;
                }

        } while(boolean ==1);
}


