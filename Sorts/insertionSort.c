#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utility.h"

/**PROTOTYPES*/
void insertionSort(int array[],int size);
/**PROTOTYPES**/

int main(int argc, char const *argv[]) {
        int list[]={78,25,30,0,40,0,1,10};
        int size =sizeof(list)/sizeof(list[0]);

        printArray(list,size);
        insertionSort(list,size);
        printArray(list,size);
        return EXIT_SUCCESS;
}


void insertionSort(int array[],int size){
        int i,j,tmp;

        for ( i = 1; i < size; i++) {
                j = i;
                tmp = array[i];

                while (j>0 && tmp < array[j-1]) {
                        array[j] = array[j-1];
                        j--;
                }
                array[j] = tmp;
        }
}
