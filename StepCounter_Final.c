#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array

void longest_period(FITNESS_DATA *fitness_data, int elements){
    int longeststart = 0, longestend = 0;
    int currentstart = 0, currentend = 0;
    int longestduration = 0, currentduration = 0;

    for (int counter = 0; counter < elements; counter++){
        int steps = atoi(fitness_data[counter].steps);

        if(steps > 500){
            if (currentduration == 0){
                currentstart = counter;
            }
            currentduration++;
            currentend = counter;
        } else {
            if (currentduration > longestduration){
                longestduration = currentduration;
                longeststart = currentstart;
                longestend = currentend;

            }
            currentduration = 0;
        }
        
    }

    if (currentduration > longestduration){
        longestduration = currentduration;
        longeststart = currentstart;
        longestend = currentend;
    }

    printf("Longest period start: %s %s\n", fitness_data[longeststart].date, fitness_data[longeststart].time);
    printf("Longest period end: %s %s\n", fitness_data[longestend].date, fitness_data[longestend].time);
}

     

    
        
          

void highest_steps(FITNESS_DATA *fitness_data, int elements){
    
    
    int i=0;
     float maxsteps=0,current;
    
                for (int counter = 0; counter < elements; counter++)
                {
            
                    int steps = atoi(fitness_data[counter].steps);
                    current = steps;
                    if(current>maxsteps){
                        maxsteps=current;
                        i = counter;
                    }
                 
             }
             
             printf("Largest steps: %s %s\n", fitness_data[i].date, fitness_data[i].time); 
}

void count_function(){
    
    
    // int count = 0;
    // char recordcount; 
    // recordcount = fgetc(input); //extracts characters from the file and stores it in character recordcount
    // while (recordcount != EOF ) { // while loop will stop when we reach end of file
    //     if (recordcount == '\n'){ // implying that it will count for encountering a new line
        
    //         count = count + 1;
    //     }
    //         recordcount = fgetc(input); //takes the next character from file until we reach end of file
    // }

    // fclose(input);
    // printf("Total records: %d\n", count);

}

void lowest_steps(FITNESS_DATA *fitness_data, int elements){
    
    
    int i=0;
    float minsteps=10000,current;
    

    

    for (int counter = 0; counter < elements; counter++){
        int steps = atoi(fitness_data[counter].steps);
        current = steps;
        if(current<minsteps){
            minsteps=current;
            i = counter;
        }
    }
    
    printf("Fewest steps: %s %s\n", fitness_data[i].date, fitness_data[i].time); 

}

void mean_count(FITNESS_DATA *fitness_data, int elements){
    float mean = 0;
    int counter;
            for ( counter = 0; counter < elements; counter++)
            {  
                int steps = atoi(fitness_data[counter].steps);
                mean += steps;
            }
            mean /= counter;
            printf("Mean step count: %.0f\n", mean);            
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
    int counter = 0;
    int elements = 0;
    char choice;
    char line[buffer_size];
    char filename[buffer_size];
    FITNESS_DATA fitness_data[900];
    
    while (1)
    {   
       //FILE *input = fopen(filename, "r");

        printf("A: Specify the filename to be imported\n");                       
        printf("B: Display the total number of records in the files\n");                    
        printf("C: Find the date and time of the timeslot with the fewest steps\n");                     
        printf("D: Find the date and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file \n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n"); 
        printf("Q: Quit\n");

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
                printf("Input filename: ");
                //these lines read in a line from the stdin (where the user types)
                //and then takes the actual string out of it
                //this removes any spaces or newlines.
                fgets(line, buffer_size, stdin);
                sscanf(line, " %s ", filename);
                FILE *input = fopen(filename, "r"); 
                

                if (input == NULL)
                {
                    printf("Error: Could not find or open the file.\n");
                    continue;
                } 
                else {
                    printf("File successfully loaded.\n");
                }
                while (fgets(line, buffer_size, input)!=NULL){
                    tokeniseRecord(line, ",", fitness_data[counter].date, fitness_data[counter].time, fitness_data[counter].steps);
                    counter++;
                }
                elements = counter;
                break;
            case 'B':
            case 'b':
                printf("Total records: %d\n",elements);
                
                break;
            case 'C':
            case 'c':
                lowest_steps(fitness_data, elements);
                break;
            case 'D':
            case 'd':
                highest_steps(fitness_data, elements);
                break;
            case 'E':
            case 'e':
                mean_count(fitness_data, elements);
                break;
            case 'F':
            case 'f':
                longest_period(fitness_data, elements);
                break;
            case 'Q':
            case 'q':
                exit(0);
                break;
            default:
                printf("invalid choice.\n");
                break;
        }
        
    }
    return 0;
}







