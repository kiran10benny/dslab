#include<stdio.h>
#include<stdlib.h>
struct Node
	{
	int data;
	struct Node* next;
	};
	struct Node *top=NULL;
	
void push(){
struct Node* newnode = malloc(sizeof(struct Node));
if(newnode==NULL)
printf("memory allocation failed\n");
else{
printf("Enter the element\n");
scanf("%d",&newnode -> data);
newnode->next=top;
top=newnode;
printf("New element inserted\n");
}
}
void display(){
if(top==NULL)
printf("stack Empty\n");
else{
struct Node *temp=top;
printf("Stack elements....\n");
while(temp!=NULL)
{
printf("%d ",temp->data);
temp=temp->next;
}}
printf("\n");
}
void pop(){
if(top==NULL)
printf("stack under flow\n");
else{
struct Node *temp=top;
top=temp->next;
printf("%d deleted ",temp->data);
printf("\n");
free(temp);
}
}
void search(){
    int pos = 1, flag = 0, val;
    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }

    printf("Enter the element to be searched\n");
    scanf("%d", &val);

    struct Node *temp = top;
    while(temp != NULL){
        if(temp->data == val){
            flag = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if(flag == 1)
        printf("Element %d found at position %d \n", val, pos);
    else
        printf("Element not found\n");
}


int main(){
int value ,ch;
while(ch !=5){
printf("Enter your choice\n1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit\n");
scanf("%d",&ch);

switch(ch)
{
	case 1:
	push();
	break;
	case 2:
	pop();
	break;
	case 3:
	display();
	break;
	case 4:
	search();
	break;
	case 5:
	break;
	default:
	printf("invaild input");
}
}
}



