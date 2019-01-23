#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utility.h"

/**PROTOTYPES*/
void quickSort(int a[],int primero,int ultimo);
/**PROTOTYPES**/

int main(int argc, char const *argv[]) {
        int list[]={4,3,2,1};
        int size =sizeof(list)/sizeof(list[0]);

        printArray(list,size);
        quickSort(list,0,size-1);
        printArray(list,size);

        return EXIT_SUCCESS;
}

void quickSort(int a[],int primero,int ultimo) {
        int i,j,central,pivote;

        central = (primero + ultimo) /2;
        pivote = a[central];
        i = primero;
        j = ultimo;

        do {
                while(a[i]<pivote) i++;
                while(a[j]>pivote) j--;

                if (i<=j) {
                        swap(&a[i],&a[j]);
                        i++;
                        j--;
                }

        } while(i >=j);

        if (primero < j) quickSort(a,primero,j);

        if (i < ultimo) quickSort(a,i,ultimo);
}
