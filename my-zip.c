#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // checking if there waas enough arguments given and if wasn't exit with return code 1
    if (argc < 2) {
        printf("my-zip: file1 [file2 ...]\n"); // printing error message
        exit(1);
    }

    //initializing variables for keeping count and previous character
    int count = 1;
    int prevChar = -1;

    // for loop to open input file(s) in read binary
    for (int i = 1; i < argc; i++) {

        // opening file in read binary
        FILE *file = fopen(argv[i], "rb");

        // checking if file was succesfully opened and if it fails print error message and exit with return code 1
        if (file == NULL) {
            printf("my-zip: cannot open file\n"); // printing error message
            exit(1);
        }

        int currentChar; // initialzing currect character to store the currect charater read from input file

        // while loop for reading file character by character until the end of the file
        while ((currentChar = fgetc(file)) != EOF) {

            // if first character of the file we skip it because we need at least 2 character to know if it needs to be compressed
            if (prevChar == -1) {
                prevChar = currentChar;
                continue;
            }

            // check if current character is same as previous character so that we can add count to count all consecutive characters
            if (currentChar == prevChar) {
                count++;

            // if characters differ then print out the number and character in binary to stdout and reset the count to 1
            } else {
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&prevChar, sizeof(char), 1, stdout);
                count = 1;
            }

            // store current character into previous character
            prevChar = currentChar;
        }

        fclose(file); // close input file
    }

    // print out the final number and character in binary to stdout
    fwrite(&count, sizeof(int), 1, stdout);
    fwrite(&prevChar, sizeof(char), 1, stdout);

    return 0;
}
