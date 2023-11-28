#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


//void file_input_name(FILE *input){
    //char filename[buffer_size];
    
        
   //char line[buffer_size];
     

    
        
          
//}
void count_function(FILE * input){
    rewind(input);
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
void lowest_steps(FILE *input){
    rewind(input);
    char *stepchar;
    char line[buffer_size];
    int counter = 0,i=0;
    float minsteps=10000,current;
    char *sp;
    
    FITNESS_DATA fitness_data[100];
    
        while (fgets(line, buffer_size, input)!=NULL)
            {
                
                // split up the line and store it in the right place
                
                tokeniseRecord(line, ",", fitness_data[counter].date, fitness_data[counter].time, fitness_data[counter].steps);
                int steps = atoi(fitness_data[counter].steps);
            
       
                current = steps;
                if(current<minsteps){
                    minsteps=current;
                    i = counter;
                }
                counter++;
            }
            printf("%s %s\n", fitness_data[i].date, fitness_data[i].time); 

}
void mean_count(FILE *input){
    rewind(input);
    FITNESS_DATA fitness_data[100];
    char line[buffer_size];
    int mean = 0;
    int counter = 0;
            while (fgets(line, buffer_size, input))
            {
                // split up the line and store it in the right place
               
                tokeniseRecord(line, ",", fitness_data[counter].date, fitness_data[counter].time, fitness_data[counter].steps);
                int steps = atoi(fitness_data[counter].steps);
                mean += steps;
                counter++;
            }
            mean /= counter;
            printf("Your  %d\n", mean);
            fclose(input);
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
    FILE *input = NULL;
    while (1)
    {   
       //FILE *input = fopen(filename, "r");

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
                
                //get filename from the user
                printf("Please enter the name of the data file: ");
                //these lines read in a line from the stdin (where the user types)
                //and then takes the actual string out of it
                //this removes any spaces or newlines.
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);
                FILE *input = fopen(filename, "r"); 
                
                if (input == NULL)
                    {
                        printf("Error: File could not find or open the file\n");
                        return 1;
                    } 
                    else {
                        printf("File successfully loaded.\n");
                    }
                break;
            case 'B':
            case 'b':
                count_function(input);
                break;
            case 'C':
            case 'c':
                lowest_steps(input);
                break;
            case 'E':
            case 'e':
                mean_count(input);
                break;
            case 'Q':
            case 'q':
                exit(0);
                break;
        }
        
    }
    return 0;
}







