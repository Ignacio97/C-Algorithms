#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utility.h"

/**PROTOTYPES*/
void selectionSort(int *array,int size);
/**PROTOTYPES**/

int main(int argc, char const *argv[]) {
        int list[]={78,25,30,0,40,0,1,10};
        int size =sizeof(list)/sizeof(list[0]);

        printArray(list,size);
        selectionSort(list,size);
        printArray(list,size);
        return EXIT_SUCCESS;
}



void selectionSort(int *array,int size) {
        int i,j,minor_index;

        for (i = 0; i < size-1; i++) {
                minor_index = i;
                for ( j = i+1; j < size; j++)
                        if (array[j] < array[minor_index])
                                minor_index = j;

                if (minor_index != i)
                        swap(&array[i],&array[minor_index]);
        }


}
