#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 50
#define cls() system("clear"); //for linux/mac users
//#define cls() system("cls"); //for windows users

//dataType type the stack will hold.
typedef char dataType;

//Stack.
typedef struct  {
        int size;
        dataType *array;
        int top;
}stack;

/**PROTOTYPES**/
stack newStack(const int size);
void error(const int value);
bool isFull(const stack stk);
bool isEmpty(const stack stk);
void push(stack *ptr,const dataType value );
dataType pop(stack *ptr);
dataType peek(stack *ptr);
void clearStack(stack *ptr); // to implement.
char *strReverse(const char *str);
bool isPalindrome(const char *str);
/*****END PROTOTYPES******/

/******* MAIN *********/
int main(int argc, char const *argv[]) {
  char cad[N];


  printf("%s","Enter a word:" );
  setbuf(stdin,NULL);
  scanf("%s",cad);
  printf("%s reversed is: %s\n",cad,strReverse(cad) );

  isPalindrome(cad) ? printf("%s\n","Palindrome" ) : printf("%s\n","not palindrome" );

  return EXIT_SUCCESS;
}
/******* ENDMAIN *********/


/*****FUNTIONS*****/

//Creates a new empty stack.
stack newStack(const int size){
        stack stk;
        stk.size=size;
        stk.array = (dataType*) malloc(sizeof(dataType)*size);
        stk.top = -1;
        return stk;
}

//Prints in screen an error message then ends the program.
void error(const int value) {
  switch (value) {
    case 1:
    printf("%s\n","Error!, Empty Stack!!");
    break;
  }
  exit(EXIT_FAILURE);
}

//Returns true is stack is full,, otherwise false.
bool isFull(const stack stk){
  return stk.top == (stk.size - 1);
}

//Returns true is stack is empty, otherwise false.
bool isEmpty(const stack stk){
  return (stk.top == -1);
}

//Add an element to the stack.
void push(stack *ptr,const dataType value ) {
        ( !(isFull((stack)*ptr)) ) ? ptr->array[++(ptr->top)]=value : printf("%s\n","FULL STACK!");
}

//Removes the top element from the stack and return it.
dataType pop(stack *ptr){
        dataType aux=0;

      ( !(isEmpty((stack)*ptr)) ) ? (aux = (ptr->array[(ptr->top)--])) : error(EXIT_FAILURE);

        return aux;
}

//Returns the top element without removing it from the stack.
dataType peek(stack *ptr){
    dataType aux=0;

  ( !(isEmpty((stack)*ptr)) ) ? aux = ptr->array[ptr->top] : error(EXIT_FAILURE);

  return aux;
}

//Reverse a string using a stack, return the reversed string.
char *strReverse(const char *str){
  int i; //loop variable
  int strSize = 1+strlen(str); //String size including '\0'.
  char *rev = (char*) malloc(strSize * sizeof(char)); //reservin' space for the reversed string.
  stack st = newStack(strSize-1); //stack

  for ( i = 0; i < strSize-1 ; i++) push(&st,str[i]);

  for ( i = 0; i < strSize-1 ; i++) rev[i]= pop(&st);

  rev[strSize]='\0'; //Do not forget to put back the end of string character '\0'.

return rev;
}

//Returns true if the given string is palindrome, otherwise false.
bool isPalindrome(const char *str){
  bool aux;

    (strcmp(str,strReverse(str)) == 0) ? (aux=true) : (aux=false);

  return aux;
}

/****END FUNTIONS*****/
