#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    printf("Print input lines\n");
    List *list = list_new();
    create_list(list);
    printf("Input list:\n");
    print_list(list);
    printf("Output list:\n");
    print_output_list(list);
    printf("1. Delete all occurrences of a certain word\n");
    printf("2. Insert a new word before the first occurrence of the specified word\n");
    printf("3. Exit\n");
    int input;
    free_list(list);
    return 0;
}
