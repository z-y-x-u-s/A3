#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Henry Jason Biem 260590556 **/

int main(int argc, char *argv[])
{
        FILE *file_ptr, *file_ptr2;
        char filename[500];
        char garbage;
        char beingCareful[500];
        char lineReading[500];
        int readNumber;
        int fileLineLength;
        int i;
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

        i=0;
        strcpy(lineReading, "wc -l < ");
        strcat(lineReading, filename);
        strcat(lineReading, " > LineNumber.txt");
        system(lineReading);
        file_ptr2= fopen("LineNumber.txt", "rt");
        fgets(beingCareful, 499, file_ptr2);
        fileLineLength = atoi(beingCareful);
        fclose(file_ptr2);
        printf("%d \n \n", fileLineLength);
        
        while(!feof(file_ptr))
        {    
        fgets(beingCareful, 499, file_ptr);
        readNumber= atoi(beingCareful);
        printf("%d\n", readNumber);
        i++;
        if(i==fileLineLength) break; 
        }
}   