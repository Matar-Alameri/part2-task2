#include<stdio.h>
int main(){
    char choice;
    int a;
    printf("choose option from 1 to 2\n");
    scanf("%d", &a);
    

    while(1){
        switch(a){
            case 1:
                printf("good");
                break;

            case 2:
                printf("bad");
                break;

            default:
                printf("invalid");
                


        }


    }

    return 0;

}