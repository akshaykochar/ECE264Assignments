#ifndef PA10_H
#define PA10_H

// ----------------------------------- Stack (Linked List)
typedef struct list_node_t {
    int value;
    struct list_node_t * next;
} ListNode;

typedef struct stack_t {
    ListNode * list;
} Stack;

Stack * Stack_create();
void Stack_destroy(Stack * stack);
int Stack_isEmpty(Stack * stack);
int Stack_pop(Stack * stack);
void Stack_push(Stack * stack, int value);

// ----------------------------------- Stack Sort...
void stackSort(int * array, int len);
int max_value(int *array, int len) ;
int min_value(int *array, int len) ;

// ----------------------------------- Generating 
int isStackSortable(int * array, int len);
void genShapes(int n);
void swap ( int * a , int * b ) ;
void permuteHelper ( int * array , int len , int ind ) ;
void permute ( int * array , int len ) ;


#endif