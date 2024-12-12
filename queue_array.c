#include<stdio.h>
#define MAX 5

void ENQUEUE();
void DEQUEUE();
void DISPLAY();

int front = 0, rear = -1, is_running = 1, choice, queue[MAX];

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

    if(rear == MAX - 1){
        printf("\n!!QUEUE IS FULL!!\n");
    }
    else{
        int data;
        rear += 1;
        printf("\nEnter the data to be added: ");
        scanf("%d", &data);
        queue[rear] = data;
        printf("\n!!%d has been added!!\n", data);
    }

}

void DEQUEUE(){

    if(front > rear){
        printf("\n!!QUEUE IS EMPTY!!\n");
    }
    else{
        int data;
        data = queue[front];
        front += 1;
        printf("\n%d has been removed!! \n", data);
    }

}

void DISPLAY(){

    if(front > rear){
        printf("\n!!QUEUE IS EMPTY!!\n");
    }
    else{
        for(int i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
    }

}