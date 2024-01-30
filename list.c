#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct item{
    struct item *previous;
    char *word;
    struct item *next;
}Item;

typedef struct list{
    Item *head;
    Item *tail;
}List;

#define MAX_WORD_LENGTH 50 
List *list_new(){
    return (List *) calloc(1, sizeof(List)); 
}

void add_element(List *list, char *word_t){
    Item *ptr = malloc(sizeof(Item));
    ptr -> word = word_t;
    if(!(list->head)){
        list -> head = ptr;
        list -> tail = ptr;
    }
    else{
        ptr->previous = list->tail;
        list->tail->next = ptr;
        list->tail = ptr;
    }
}

void print_list(List *list){
    printf("'");
    Item *n_element = list -> head;
    while(n_element){
        if(n_element -> next){
            printf("%s ", n_element -> word);
            n_element = n_element -> next;
        }
        else{
            printf("%s", n_element -> word);
            n_element = n_element -> next;
        }
    }
    printf("'");
    printf("\n");
}

void print_output_list(List *list){
    printf("'");
    Item *n_element = list ->tail;
    while(n_element){
        if(n_element -> previous){
            printf("%s ", n_element -> word);
            n_element = n_element -> previous;
        }
        else{
            printf("%s", n_element -> word);
            n_element = n_element -> previous;
        }
    }
    printf("'");
    printf("\n");
}

void free_list(List *list){
    Item *n_element = list -> tail;
    while(n_element){
        free(n_element -> word);
        free(n_element -> next);
        n_element = n_element -> previous;
    }
    free(list->head);
    free(list);
    list = NULL;
}

void free_new(List *list){
    Item *n_element = list -> tail;
    while(n_element){
        free(n_element -> word);
        free(n_element -> next);
        n_element = n_element -> previous;
    }
    free(list->head);
    list -> head = NULL;
    list -> tail = NULL;
}

void create_list(List *list){
    char currentchar;
    char *word = calloc(MAX_WORD_LENGTH, sizeof(char));
    int wordIndex = 0;
    while ((currentchar = getchar()) != '\n') {
        if (currentchar == ' ' || currentchar == '\t') {
            if (wordIndex > 0) {
                word[wordIndex] = '\0';
                add_element(list, word);
                wordIndex = 0;
                word = calloc(MAX_WORD_LENGTH, sizeof(char));
            }
            continue;
        }

        word[wordIndex++] = currentchar;

        if (wordIndex >= MAX_WORD_LENGTH - 1) {
            printf("ERROE VERY BIG WORD\n");
        }
    }

    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        add_element(list, word);
    }
}

char *word_cr(){
    char currentchar;
        char *word = calloc(MAX_WORD_LENGTH, sizeof(char));
        int wordIndex = 0;
        while ((currentchar = getchar()) != '\n') {
            if (currentchar == ' ' || currentchar == '\t') {
                printf("Error no space\n");                
            }
    
            word[wordIndex++] = currentchar;
    
            if (wordIndex >= MAX_WORD_LENGTH - 1) {
                printf("ERROE VERY BIG WORD\n");
            }
        }
    
        if (wordIndex > 0) {
            word[wordIndex] = '\0';
        }
        else{
            printf("Error no word\n");
        }
    return word;
}        
 
void delete_word(List *list){
   printf("Input word:\n");
       Item *n_element = list -> head;
       char *word_temp = word_cr();
        while(n_element){
            if(!strcmp(n_element -> word, word_temp)){
                if(n_element -> next && n_element -> previous){
                    n_element -> previous -> next = n_element -> next;
                    n_element -> next -> previous = n_element -> previous;
                    free(n_element -> word);
                    free(n_element);
                    n_element = list -> head;
                }
                else if(n_element -> next){
                    list -> head = n_element -> next;
                    n_element -> next -> previous = n_element -> previous;
                    free(n_element -> word);
                    free(n_element);
                    n_element = list -> head;
                }
                else if(n_element -> previous){
                    list -> tail = n_element -> previous;
                    n_element -> previous -> next = n_element -> next;
                    free(n_element -> word);
                    free(n_element);
                    n_element = list -> tail;
                }

            }
            else{
                n_element = n_element ->next;
            }
        }
    free(word_temp);
}
    
void add_word(List *list){
    printf("Print input word:\n");
    char *word_input = word_cr();
    printf("Print word in list:\n");
    char *word_in_list = word_cr();
    Item *temp_el = list -> head;
    while(strcmp(temp_el -> word, word_in_list)){
        
        temp_el = temp_el -> next;
        if(!temp_el){
            printf("ERORRRRRRRRRRR NO THAT WORD\n");
            break;
        }
    }
    
    Item *new_el = calloc(1, sizeof(Item));
    new_el -> word = word_input;
    if(temp_el -> previous){
        new_el -> previous =  temp_el -> previous;
        temp_el -> previous -> next = new_el;
    }
    else{
        list -> head = new_el;
    }
    temp_el -> previous = new_el;
    new_el -> next = temp_el;
    free(word_in_list);
}
        
