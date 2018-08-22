#include "myStack.h"

int main(int argc, char const *argv[]) {
  char cad[N];


  printf("%s","Enter a word:" );
  setbuf(stdin,NULL);
  scanf("%s",cad);
  printf("%s reversed is: %s\n",cad,strReverse(cad) );
  isPalindrome(cad) ? printf("%s\n","Palindrome" ) : printf("%s\n","not palindrome" );

  return EXIT_SUCCESS;
}
