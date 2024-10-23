#include<stdio.h>

void main(){
    
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];

    for(int i=0; i<size; i++){
        printf("Enter a[%d] = ", i);
        scanf("%d", &array[i]);
    }

    printf("The array elements are: ");

    for(int i=0; i<size; i++){
        printf("%d ", array[i]);
    }

}