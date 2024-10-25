#include<stdio.h>
#define MAX 5

void ENQUEUE();
void DEQUEUE();
void DISPLAY();
int ADDINDEX(int index);

int front = -1, rear = -1, is_running = 1, choice, queue[MAX];

void main(){

    while(is_running){

        printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n...Press 0 to exit...\nEnter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            is_running = 0;
            break;
        case 1:
            ENQUEUE();
            break;
        case 2:
            DEQUEUE();
            break;
        case 3:
            DISPLAY();
            break;     
        default:
            printf("\nWrong Choice :(\n");
            break;
        }

    }
}

void ENQUEUE(){

    if(ADDINDEX(rear) == front){
        printf("\n!!QUEUE IS FULL!!\n");
    }
    else{
        if(front == -1){
            front = 0;
        }
        rear = ADDINDEX(rear);
        int data;
        printf("\nEnter the data to be added: ");
        scanf("%d", &data);
        queue[rear] = data;
        printf("\n!!%d has been added!!\n", data);
    }

}

void DEQUEUE(){
    if(front == -1){
        printf("\n!!QUEUE IS EMPTY!!\n");
    }
    else{
        int data;
        data = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = ADDINDEX(front);
        }
        printf("\n%d has been removed!! \n", data);
    }
}

void DISPLAY(){

    if(front == -1){
        printf("\n!!QUEUE IS EMPTY!!\n");
    }
    else{
        int i = front;
        while(i != rear){
            printf("%d ", queue[i]);
            i = ADDINDEX(i);
        }
        printf("%d", queue[rear]);
    }

}

int ADDINDEX(int index){

    return (index + 1) % MAX;
}