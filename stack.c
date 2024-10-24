#include<stdio.h>
#define MAX 5

void PUSH();
void POP();
void DISPLAY();
void PEEK();

int top = -1, is_running = 1, choice, stack[MAX];

void main(){

    while(is_running){

        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n...Press 0 to exit...\nEnter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            is_running = 0;
            break;
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            PEEK();
            break;      
        default:
            printf("\nWrong Choice :(\n");
            break;
        }

    }
}

void PUSH(){
    int data;
    if(top >= MAX - 1){
        printf("\nSTACK OVERFLOW\n");
    }
    else{
        top += 1;
        printf("\nEnter the data to be pushed: ");
        scanf("%d", &data);
        stack[top] = data;
        printf("\n!! %d has been pushed into the stack !!\n", data);
    }
}

void POP(){
    int data;

    if(top == -1){
        printf("\nSTACK UNDERFLOW\n");
    }
    else{
        data = stack[top];
        top -= 1;
        printf("\n!! %d has been popped from the stack !!\n", data);
    }

}

void DISPLAY(){
    if(top == -1){
        printf("\n!! The stack is empty !!\n");
    }
    else{
        printf("\nThe stack contains: \n");

        for(int i=top; i>=0; i-- ){
            printf("| %d |\n", stack[i]);
        }
    }
}

void PEEK(){
    if(top == -1){
        printf("\n!! The stack is empty !!\n");
    }
    else{
        printf("\nThe top of the stack points to %d\n", stack[top]);
    }
}