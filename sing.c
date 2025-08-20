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
void insert_pos(){
    int pos;
        struct Node* newnode = malloc(sizeof(struct Node));
   printf("Enter the element   ");
   scanf("%d",&newnode->data);
   printf("Enter the position\n");
   scanf("%d",&pos);
   if(pos==1){
    newnode->next=head;
    head=newnode;
   }
   temp=head;
   for(int i=1;i<pos-1;i++)
   {
       temp=temp->next;
   }
   newnode->next=temp->next;
   temp->next=newnode;
   
      printf("Elements are ....");
   display();
   printf("\n");
}
void delb(){
    if(head==NULL)
    {
        printf("stack empty\n");
    }
    temp=head;
    head=temp->next;
    printf("element deleted is %d",temp->data);
    printf("\n");
    free(temp);
}
void dele(){
    if(head==NULL)
    printf("Empty\n");
    if(head->next==NULL){
        free(head);
        head=NULL;
    }
    while(temp->next->next!=NULL){
        
    }
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
            case 3:insert_pos();
            break;
            case 4:delb();
            break;
            case 5:dele();
            break;
            case 7:display();
            break;
            case 8:break;
        }
    }
}