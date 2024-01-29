#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n');
}

int main(){
    printf("Print input lines\n");
    List *list = list_new();
    char input;
    create_list(list);
    do{
        printf("Input line:\n\n");
        print_list(list);
        printf("Output line:\n\n");
        print_output_list(list);
        input = getchar();
        switch(input){
            case '1':
                printf("Do 1 func\n");
                break;
            case '2':
                printf("Do 2 func\n");
                break;
            case '3':
               printf("New line\n");
                  break;
            default:
                  printf("Incorrect input\n");
            }
    }while(input != -1); 
    free_list(list);
    return 0;
}
