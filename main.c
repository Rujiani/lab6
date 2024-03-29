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
    int input;
    create_list(list);
    do{
        printf("1. Delete all occurrences of a certain word.\n");
        printf("2. Insert a new word before the first occurrence of the specified word.\n");
        printf("3. New line\n\n");
        printf("Input line:\n\n");
        print_list(list);
        printf("Output line:\n\n");
        print_output_list(list);
        if(EOF == scanf("%d", &input)){
                free_list(list);
                return 0;
                }
        switch(input){
            case 1:
                clearInputBuffer();
                delete_word(list);
                break;
            case 2:
                clearInputBuffer();
                add_word(list);
                break;
            case 3:
                clearInputBuffer();
                list = list_new();
                create_list(list);
                break;
            default:
                  printf("Incorrect input\n");
                  break;
            }
    }while(1); 
    free_list(list);
    return 0;
}
