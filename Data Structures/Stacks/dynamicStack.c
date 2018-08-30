#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 50
#define cls() system("clear"); //for linux/mac users
//#define cls() system("cls"); //for windows users

//dataType type the stack will hold.
typedef int dataType;

//Stack.
typedef struct node {

        dataType item;
        struct node* next;

}stack;


/**PROTOTYPES**/
void push(stack **stk,dataType value);
dataType pop(stack **stk);
bool isEmpty(stack *stk);
dataType peek( stack ** stk);
void error();
/*****END PROTOTYPES******/

/******* MAIN *********/
int main(int argc, char const *argv[]) {
        stack *st=NULL;
        int i;

        printf("stack empty? %d\n",isEmpty(st)); //should print true (1).

        for ( i = 0; i < 10; i++) {
                push(&st,i);
        }

        printf("stack empty? %d\n",isEmpty(st)); //should print false (0).

        for ( i = 0; i < 10; i++) {
                printf("%d\n", pop(&st));
        }

        printf("stack empty? %d\n",isEmpty(st)); //should print true (1).

        return EXIT_SUCCESS;
}
/******* ENDMAIN *********/


/*****FUNTIONS*****/

//Add an element to the stack.
void push(stack **stk,dataType value) {
        stack *temp = (stack*)malloc(sizeof(stack));

        temp->item = value;
        temp->next = *stk;

        *stk = temp;
}

//Removes the top element from the stack and return it.
dataType pop(stack **stk) {

        if (isEmpty(*stk)) error();

        dataType aux = (*stk)->item; //saves the data value.
        stack *temp = *stk; //saves the refence.
        *stk = (*stk)->next; //pointing to next element

        free(temp); //delete the old reference.
        return aux; //return the data value deleted.
}

//Returns true is stack is empty, otherwise false.
bool isEmpty(stack *stk){

        return (stk==NULL);
}

//Returns the top element without removing it from the stack.
dataType peek(stack ** stk) {
        return ( (*stk)->item );
}
//Prints in screen an error message then ends the program.
void error() {
        printf("%s\n","Error!, Empty Stack!!");
        exit(EXIT_FAILURE);
}
/****END FUNTIONS*****/
