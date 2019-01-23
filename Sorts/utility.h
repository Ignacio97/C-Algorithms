void swap(int *a,int *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
}

void printArray(int *array,int size) {
        int i;
        for ( i = 0; i < size; i++) {
                printf("%d ",array[i] );
        }
        printf("\n");
}
