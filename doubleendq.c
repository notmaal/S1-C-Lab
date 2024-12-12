#include <stdio.h>
#include <stdlib.h>

void insert_front();
void delete_front();
void insert_rear();
void delete_rear();
void isempty();
void display();

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void main()
{
    int is_running = 1, ch;
    while (is_running)
    {
        printf("\n----Double Ended Queue Using Linked List----\n");
        printf("\n\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n5. Display\n6. Check if empty\n7. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            delete_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            isempty();
            break;
        case 7:
            is_running = 0;
            break;
        default:
            printf("\nWrong Choice :(\n");
            break;
        }
    }
}

void insert_front()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));

    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        newnode->next = front;
        front->prev = newnode;
        front = newnode;
    }
}
void insert_rear()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));

    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if (rear == NULL && front == NULL)
    {
        rear = newnode;
        front = newnode;
    }
    else
    {
        rear->next = newnode;
        newnode->prev = rear;
        rear = newnode;
    }
}

void delete_front()
{
    if (front == NULL)
    {
        printf("\nQueue Empty!!\n");
    }
    else
    {
        node *temp;
        printf("The deleted element is %d", front->data);
        temp = front;
        front = front->next;
        
        if (front == NULL)
        {
            rear = NULL;
        }
        else{
            front->prev = NULL;
        }
        free(temp);
    }
}
void delete_rear()
{
    if (front == NULL)
    {
        printf("\nQueue Empty!!\n");
    }
    else
    {
        node *temp;
        printf("The deleted element is %d", rear->data);
        temp = rear;
        rear = rear->prev;
        
        if (rear == NULL)
        {
            front = NULL;
        }
        else{
            rear->next = NULL;
        }
        free(temp);
    }
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue Empty\n");
    }
    else
    {
        node *current = front;

        while (current != NULL)
        {
            printf("%d  ", current->data);
            current = current->next;
        }
    }
}

void isempty(){
    if (front == NULL || rear == NULL){
        printf("\nThe queue is empty!!!\n");
    }
    else 
    {
        printf("\nNot empty!\n");
    }
}