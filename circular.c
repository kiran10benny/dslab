#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int cqueue[SIZE];
int f=-1,r=-1;

int isfull(){
    return (f==0 && r==SIZE-1) || (f==(r+1)%SIZE);
}
int isempty(){
    return (f==-1);
}
void enqueue(){
    int val;
    printf("enter the value....");
    scanf("%d",&val);
    if(isfull()){
    printf("Queue full....");
    return;
    }
    if(f==-1)
    f=0;
    
    r=(r+1)%SIZE;
    cqueue[r]=val;
    printf("Element  inserted is %d",val);
}
void dequeue(){
    if(isempty()){
        printf("queue empty.....");
        return;
    }
    int value=cqueue[f];
    printf("vlaue deleted is ...%d",value);
    
    if(f==r)
    f=r=-1;
    else
    f=(f+1)%SIZE;
}
void display(){
    if(isempty()){
        printf("Empty queue...");
        return;
    }
    int i=f;
    while(1){
        printf("%d ",cqueue[i]);
        if(i==r) break;
        i=(i+1) % SIZE;
    }
    printf("\n");
}
void search(){
    int val;
    printf("enter the value to search....");
    scanf("%d",&val);
    int i=f;
    int pos=1;
    int found=0;
    while(1){
        if(val==cqueue[i]){
        printf("Element found at position %d",pos);
        found=1;
        break;
        }
        if(i==r)
        break;
        i=(i+1)%SIZE;
        pos++;
    }
    if(!found)
    printf("Element not found.....\n");
}
void main() {
    int choice, value;

    while (1) {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                search();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
