#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


void file_input_name(FILE *input){
    char filename[buffer_size];
    
        
    char line[buffer_size];
    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    
        
        if (!input)
        {
            printf("Error: File could not be opened\n");
            
        }
}
void count_function(FILE * input){
     
    if (input == NULL) {
        perror("couldn't open file");
        
    }
    int count = 0;
    char recordcount; 
    recordcount = fgetc(input); //extracts characters from the file and stores it in character recordcount
    while (recordcount != EOF ) { // while loop will stop when we reach end of file
        if (recordcount == '\n'){ // implying that it will count for encountering a new line
        
            count = count + 1;
        }
            recordcount = fgetc(input); //takes the next character from file until we reach end of file
    }

    fclose(input);
    printf("Number of records in file: %d\n", count);

}

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main(){
    char choice;
    char line[buffer_size];
    char filename[buffer_size];
    

    while (1)
    {
        FILE *input = fopen(filename, "r");
       
        

        printf("A: file input name\n");                       
        printf("B: view number of records\n");                    
        printf("C: lowest steps\n");                     
        printf("D: highest steps\n");                    
        printf("E: mean \n");       
        printf("F: longest period\n"); 
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');


        // switch statement to control the menu.
        switch (choice){
            case 'A':
            case 'a':
                file_input_name(input);
                fclose(input);
                break;
            case 'B':
            case 'b':
                count_function(input);
                break;
            case 'Q':
            case 'q':
                break;
        }
        return 0;
    }

}







