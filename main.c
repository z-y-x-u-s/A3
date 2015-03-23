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
        char garbage, filename[500], beingCareful[500], lineReading[500], answer[500];
        int readNumber, boolean, fileLineLength, j=0;

        /*Loops continously until a valid pointer is produced from fopen */
        do {
                printf("Please provide a valid filepath with the proper extension to be opened: \n");
                scanf("%499[^\n]", filename);      // Read until the carriage return.

                garbage=getchar();                 // Remove the carriage return from.

                file_ptr=fopen(filename, "rt");    // Open the text file in read mode.

        } while (file_ptr ==NULL);

        /* This segment of code counts how many lines are in the inputed file */
        strcpy(lineReading, "wc -l < ");           // These 3 lines create the string to be systemed out.
        strcat(lineReading, filename);
        strcat(lineReading, " > LineNumber.txt");
        system(lineReading);                       // The line count command is executed in bash.
        file_ptr2= fopen("LineNumber.txt", "rt");  // The resulting file is opened.
        fgets(beingCareful, 499, file_ptr2);       // The first line is retrieved.
        fileLineLength = atoi(beingCareful);       // And then converted to an integer.
        fclose(file_ptr2);                         // The created file is closed.

        /*This while loop reads the file to the end */
        while(!feof(file_ptr))
        {
                fgets(beingCareful, 499, file_ptr);// The current line is read. 
                readNumber= atoi(beingCareful);    // The string is converted to an integer.
                add(readNumber);                   // The integer is added to the node.

                /*This segment of code verifies that no extra integers were added to the linked list
                  This prevents errors with numerous corner case files, which inserted extra numbers*/
                j++;                               // j increments with each loop.
                if(j==fileLineLength) break;       // Stop if all lines of the file have been read.
        }
        fclose(file_ptr);                          // The inputed file is closed.
        prettyPrint();                             // Linked list is printed.


        /* This loop's code  deletes the user's inputed number should it exist in the Linked List
           It repeats based on the user's input asking it to do so  */
        do
        {
                printf("What integer would you like to be removed? The first one found will be deleted: \n");
                scanf("%499[^\n]", beingCareful); // Read until the carriage return.
                readNumber= atoi(beingCareful);   // Convert the string to an integer.
                garbage=getchar();                // Garbage collect the carriage return.

                if(delete(readNumber))            // If the delete function returns TRUE,
                {                                 // (The number was successfully deleted)
                        printf("NUMBER WAS DELETED! \n");
                        prettyPrint();            // Display the new Linked List.
                }

                else                              // If the delete function returns FALSE,
                {                                 // (The Number could not be found and deleted)
                        printf("NUMBER WAS NOT FOUND! \n");
                        prettyPrint();            // Display the same Linked List.
                }

                printf("Would you like to delete another number? Enter either Y, y, Yes, YES, or yes. \n");
                scanf("%499[^\n]", answer);       // Get the user's input until the carriage return.
                garbage=getchar();                // Garbage collect the carriage return.

                /*If the inputed string matches one of the 5 answers, the boolean variable is set to true (+1) */
                boolean = 0;                      // The boolean variable is reset to 0 each loop.
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

        } while(boolean ==1);                      // Repeat the loop should the user desire so (boolean became 1).
}




