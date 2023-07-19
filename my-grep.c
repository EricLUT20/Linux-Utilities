#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // check if there is enough arguments given and print error message and exit with return code 1
    if (argc < 2) {
        printf("my-grep: searchterm [file ...]\n"); // print instructions
        exit(1);
    }

    // if there is search term given read from the standart inut (stdin)
    else if (argc == 2) {

        // initialize all the variables used for storing when reading
        ssize_t read;
        size_t len = 0;
        char *result, *line = NULL;

        // while loop to read lines from stdin and store contents to line variable
        while ((read = getline(&line, &len, stdin)) != -1) {
            
            // check if string (line) contrains the search term in it, if it does print it
            if ((result = strstr(line, argv[1])) != NULL) {
                printf("%s", line);
            }
        }
    }

    // if there is search term and input file(s) in arguments then print lines from input file(s) that contain it
    else {

        // for loop to open all input files in read
        for (int i = 2; i < argc; i++) {

            // making a pointer to input file and opening it in read
            FILE *file = fopen(argv[i], "r");

            // checking if input file was opened properly and print error message if it wasn't and exit with return code 1
            if (file == NULL) {
                printf("my-grep: cannot open file\n"); // print error message
                exit(1);
            }

            // initialize all the variables used for storing when reading
            ssize_t read;
            size_t len = 0;
            char *result, *line = NULL;

            // while loop to read lines from input file(s) and store contents to line variable
            while ((read = getline(&line, &len, file)) != -1) {

                // check if string (line) contrains the search term in it, if it does print it
                if ((result = strstr(line, argv[1])) != NULL) {
                    printf("%s", line);
                }
            }
            fclose(file); // close input file(s)
        }
    }
    return 0;
} 