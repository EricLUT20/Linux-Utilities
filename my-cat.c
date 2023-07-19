#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

int main(int argc, char *argv[]) {

    // check if there is input file(s) given in arguments if not exit with return code 0
    if (argc < 2) {
        exit(0);
    }

    // else for loop for all the input files in arguments and print them out
    for (int i = 1; i < argc; i++) {

        // open input file in read
        FILE *file = fopen(argv[i], "r");

        // check if input file was opened succesfully else print error message and exit with return code 1
        if (file == NULL) {
            printf("my-cat: cannot open file\n"); // print error message
            exit(1);
        }

        char *buffer; // initialize buffer to store contents of input file(s)

        // Dynamically allocate memory for buffer variable and make sure it is succesful in case it fails print error and exit with return code 1
        if ((buffer = malloc(sizeof(char) * BUFFER)) == NULL) {
            printf("malloc failed\n"); // print error message
            exit(1);
        }

        // while loop to read and store contents of input file(s) in buffer variable and print them out
        while (fgets(buffer, BUFFER, file) != NULL) {
            printf("%s", buffer);
        }

        free(buffer); // Free dynamically allocated memory for buffer variable
        fclose(file); // Close input file
    }
    return 0;
}