#include<stdio.h>
#define MAX 10

int array[MAX], end = -1;

void display();
void insert();
void delete();
void search();

void main(){
    int ch, is_running = 1;

    while(is_running){
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            search();
            break;
        case 4:
            display();
            break;
        case 5:
            is_running = 0;
            printf("\n...Exiting...\n");
            break;
        
        default:
            printf("\n!!Invalid Choice!!\n");
            break;
        }
    }

}

void display(){
    if(end == -1){
        printf("\nThe array is empty!!\n");
    }
    else{
        printf("\nThe array elements are: ");

        for(int i=0; i<=end; i++){
            printf("%d ", array[i]);
        }
    }
}

void insert(){
    int n;
    printf("\nHow much elements to add ? : ");
    scanf("%d", &n);
    if((n+end+1) > MAX){
        printf("\nNot Enough Space :(\n%d spaces left\n", MAX - end - 1);
    }
    else{
        for(int i=end + 1; i<=end+n; i++){
            printf("Enter array[%d] element: ", i);
            scanf("%d", &array[i]);
        }
        end += n;
    }
}

void search(){
    if(end == -1){
        printf("\nThe array is empty!!\n");
    }
    else{
        int tosearch;
        printf("\nEnter the element to search for: ");
        scanf("%d", &tosearch);
        for(int i=0; i<=end; i++){
            if(array[i] == tosearch){
                printf("\n%d found at index %d\n", tosearch, i);
                return;
            }
        }
        printf("\n%d was not found :( \n", tosearch);
    }
}

void delete(){
    if(end == -1){
        printf("\nThe array is empty!!\n");
    }
    else{
        printf("\nEnter the index of the element to be deleted: ");
        int index;
        scanf("%d", &index);
        if(index>end){
            printf("\nThere is no data at that index\n");
        }
        else{
            for(int i=index; i<end; i++){
                array[i] = array[i+1];
            }
            end--;
        }
    }
}