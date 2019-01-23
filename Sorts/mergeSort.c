#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "utility.h"

/**PROTOTYPES*/
void mergeSort(int *array,int first,int last);
void merge(int *array,int first,int half,int last);
/**PROTOTYPES**/

int main(int argc, char const *argv[]) {
        int list[]={4,3,2,1};
        int size =sizeof(list)/sizeof(list[0]);

        printArray(list,size);
        mergeSort(list,0,size-1);
        printArray(list,size);

        return EXIT_SUCCESS;
}




void mergeSort(int *array,int first,int last){
        int half = (first + last) / 2;

        if (first < last) {
                mergeSort(array,first,half);
                mergeSort(array,half+1,last);
                merge(array,first,half,last);
        }

}
void merge(int *array,int first,int half,int last){
        int *tmp = (int*) malloc(sizeof(int)* last-first+1 );
        int x,y,z;

        x = z = first;
        y = half +1;

        while (x <= half && y <= last) {
                if (array[x] <= array[y])
                        tmp[z++] = array[x++];
                else
                        tmp[z++] = array[y++];
        }


        while (x <= half)
                tmp[z++] = array[x++];

        while (y <= last)
                tmp[z++] = array[y++];

        for ( z = first; z <= last; z++)
                array[z]=tmp[z];

        free(tmp);
}
