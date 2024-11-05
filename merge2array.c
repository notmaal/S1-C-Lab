#include<stdio.h>
#define smallsize 5
#define bigsize 10

void main(){
    int a[bigsize], b[smallsize], i;
    printf("\nEnter the elements of first array: \n");
    for(i=0; i<smallsize; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("\nEnter the elements of second array: \n");
    for(i=0; i<smallsize; i++){
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }
    for(i=smallsize; i<bigsize; i++){
        a[i] = b[i - smallsize];
    }
    printf("\nThe merged array is: ");
    for(i=0; i<bigsize; i++){
        printf("%d ", a[i]);
    }
}