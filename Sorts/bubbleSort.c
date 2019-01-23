#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utility.h"

/**PROTOTYPES*/
void bubbleSort(int *array,int size);
/**PROTOTYPES**/

int main(int argc, char const *argv[]) {
        int list[]={78,25,30,0,40,0,1,10};
        int size =sizeof(list)/sizeof(list[0]);

        printArray(list,size);
        bubbleSort(list,size-1);
        printArray(list,size);
        return EXIT_SUCCESS;
}





void bubbleSort(int *array,int size){
        int lap,j;
        bool key = true;

        for (lap = 0; lap < (size-1) && key; lap++) {
                key = false;
                for (j = 0; j < size-lap-1; j++) {
                        if (array[j] > array[j+1]) {
                                key = true;
                                swap(&array[j],&array[j+1]);
                        }

                }
        }
}
