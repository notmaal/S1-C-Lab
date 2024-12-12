#include <stdio.h>
#define size 6

void display(int []);
void displaybit(int [], int []);
void unioning(int [], int [], int []);
void intersection(int [], int [], int []);

void main()
{
    int u[size] = {1, 2, 3, 4, 5, 6}, a[size] = {1, 0, 0, 1, 0, 1}, b[size] = {1, 1, 1, 0, 0, 0};
    printf("\nThe universal set is: ");
    display(u);
    printf("\nThe set a is: ");
    displaybit(u, a);
    printf("\nThe set b is: ");
    displaybit(u, b);

    printf("\nA union B is : ");
    unioning(u,a,b);
    printf("\nA intersection B is : ");
    intersection(u,a,b);

}

void display(int u[])
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", u[i]);
    }
}
void displaybit(int u[], int a[])
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 1)
        {
            printf("%d ", u[i]);
        }
    }
}

void unioning(int u[],int a[],int b[])
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 1 || b[i] == 1)
        {
            printf("%d ", u[i]);
        }
    }
}

void intersection(int u[],int a[],int b[])
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 1 && b[i] == 1)
        {
            printf("%d ", u[i]);
        }
    }
}