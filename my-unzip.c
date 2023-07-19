#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    // checking if there waas enough arguments given and if wasn't exit with return code 1
    if (argc < 2) {
        printf("my-unzip: file1 [file2 ...]\n"); // print instructions how to use
        exit(1);
    }

    // in case there was enough arguments given
    else {
        for (int i = 1; i < argc; i++) {
            FILE *file = fopen(argv[1], "rb"); // Opening input file in read-binary
            
            // checking if file was opened succesfully and in case it wasn't exit with return code 1 and print message for user
            if (file == NULL) {
                printf("my-unzip: cannot open file\n"); // printing the error
                exit(1);
            }
            int count; // Initializing count to store the count of the characters
            char character; // Initializing character to store the character

            // Reading the count and character and storing them in variables count and character
            while (fread(&count, sizeof(int), 1, file) == 1) {
                fread(&character, sizeof(char), 1, file);

                // For loop for printing each character their respective amount of count times 
                for (int j = 0; j < count; j++) {
                    fwrite(&character, sizeof(char), 1, stdout);
                }
            }
            fclose(file); // Closing the input file
        }
    }
    return 0;
}
