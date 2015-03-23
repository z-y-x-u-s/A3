#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Henry Jason Biem 260590556 **/

int main(int argc, char *argv[])
{
        FILE *file_ptr;
        char filename[500];
        char garbage;
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
}
