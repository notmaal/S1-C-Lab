#include <stdio.h>
#include <stdlib.h>

void insatbeg();
void insatend();
void insatpos();
void display();
void delete();

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;
node *current;

void main()
{
    int is_running = 1, ch;
    while (is_running)
    {
        printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete\n5.Display\n6.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insatbeg();
            break;
        case 2:
            insatend();
            break;
        case 3:
            insatpos();
            break;
        case 4:
            delete ();
            break;
        case 5:
            display();
            break;
        case 6:
            is_running = 0;
            break;
        default:
            printf("\nWrong Choice :(\n");
            break;
        }
    }
}

void insatbeg()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        newnode->next = head;
        head = newnode;
        current->next = head;
    }
}

void insatend()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    int data;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        newnode->next = head;
        current->next = newnode;

    }
}

void insatpos()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    int data, pos;
    printf("\nEnter the data to be added: ");
    scanf("%d", &data);
    newnode->data = data;
    printf("\nEnter the position to insert the data: ");
    scanf("%d", &pos);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
    }
    else if (pos == 1)
    {
        node *current;
        current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    else
    {
        current = head;
        for (int i = 2; i < pos; i++)
        {
            if (current->next == head)
            {
                break;
            }
            current = current->next;
        }
        if (current->next == head)
        {
            newnode->next = head;
            current->next = newnode;
        }
        else
        {
            newnode->next = current->next;
            current->next = newnode;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\n!!There are no nodes to display!!\n");
    }
    else
    {
        current = head;
        do
        {
            printf("%d ", current->data);
            current = current->next;
        }while (current != head);
    }
}

void delete()
{
    if (head == NULL)
    {
        printf("\n!!There are no nodes to delete!!\n");
    }
    else
    {
        int pos;
        current = head;
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        if(current->next == head){
            head = NULL;
            free(current);
        }
        else if (pos == 1)
        {
            while(current->next != head){
                current = current->next;
            }
            current->next = head->next;
            current = head;
            head = head->next;
            free(current);
        }
        else
        {
            for (int i = 2; i < pos; i++)
            {
                if (current->next == head)
                {
                    break;
                }
                current = current->next;
            }
            if (current->next == head)
            {
                printf("\n!!There was no node to delete at the position!!\n");
            }
            else
            {
                node *temp;
                temp = current->next;
                current->next = current->next->next;
                free(temp);
            }
        }
    }
}