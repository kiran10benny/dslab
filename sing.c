#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head,*temp;
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d  ",temp->data);
        temp=temp->next;
    }
}
void insert_b()
{
   struct Node* newnode = malloc(sizeof(struct Node));
   printf("Enter the element   ");
   scanf("%d",&newnode->data);
   newnode->next=head;
   head=newnode;
   printf("Elements are ....");
   display();
   printf("\n");
}
void insert_e(){
    struct Node* newnode = malloc(sizeof(struct Node));
   printf("Enter the element   ");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   if(head==NULL){
       head=newnode;
       return;
   }
   temp=head;
   while(temp->next!=NULL)
   {
       temp=temp->next;
   }
   temp->next=newnode;
     printf("Elements are ....");
   display();
   printf("\n");
}

void main(){
    int ch;
    while(ch!=5)
    {
        printf("Enter your choice \n 1.insertb\n2.insertE\n3.insert at a position\n4.deleteB\n5.deleteE\n6.delete pos\7.display\n8.exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:insert_b();
            break;
            case 2:insert_e();
            break;
            case 3:display();
            break;
        }
    }
}