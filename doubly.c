
#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next,*prev;
};
struct Node *head=NULL, *tail=NULL, *temp=NULL;

struct Node *createNode(){
    int val;
    printf("enter the value....");
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&val);
    newnode->data=val;
    newnode->next=newnode->prev=NULL;
    return newnode;
}
void displayA(){
    if(head==NULL){
        printf("empty list");
    }
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void displayD(){
    if(head==NULL){
        printf("empty list");
    }
    temp=tail;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
}
void insertB(){
    struct Node *newnode=createNode();
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    
    }
    printf("Elements in the list .....");
    displayA();
}
void insertE(){
    struct Node *newnode=createNode();
    if(tail==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    
    }
    printf("Elements in the list .....");
    displayA();
}
void insertP(){
    int pos;
    printf("Enter the position ....");
    scanf("%d",&pos);
   
    if(pos==1){
       struct Node *newnode=createNode();
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    
    }
    printf("Elements in the list .....");
    displayA();
  
    }
    else{
       temp=head;
       for(int i=1;i<pos-1&&temp;i++){
           temp=temp->next;
       }
        struct Node *newnode=createNode();
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=NULL){
            temp->next->prev=newnode;
        }
        temp->next=newnode;
    
    }
    printf("Elements in the list .....");
    displayA();
}
void deleteB(){
    if(head==NULL){
        printf("underflow ...");
    }
    else if(head==tail){
        printf("Deleted element is ...%d",head->data);
        free(head);
        head=tail=NULL;
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        printf("Deleted element is ...%d",temp->data);
        free(temp);
    }
}
void deleteE(){
    if(head==NULL){
        printf("underflow ...");
    }
    else if(head==tail){
        printf("Deleted element is ...%d",head->data);
        free(head);
        head=tail=NULL;
    }
    else{
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        printf("Deleted element is ...%d",temp->data);
        free(temp);
    }
}
void deleteP(){
    int pos;
    printf("Enter the position ....");
    scanf("%d",&pos);
   
    if(pos==1){
if(head==NULL){
        printf("underflow ...");
    }
    else if(head==tail){
        printf("Deleted element is ...%d",head->data);
        free(head);
        head=tail=NULL;
    }
   else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        printf("Deleted element is ...%d",temp->data);
        free(temp);
    }
    }
    else{
       temp=head;
       for(int i=1;i<pos&&temp;i++){
           temp=temp->next;
       }
       if(temp->next)
       temp->next->prev=temp->prev;
      if(temp->prev)
       temp->prev->next=temp->next;
       if(temp==tail)
       tail=temp->prev;
       printf("Deleted element is ...%d",temp->data);
       free(temp);
    }
}
void search(){
    int val,pos=1,found=0;
    printf("enter the value to search....");
    scanf("%d",&val);
    if(head==NULL)
    printf("Empty tist");
    temp=head;
    while(temp!=NULL){
        if(temp->data==val){
        printf("Element found at position %d",pos);
        printf("\n");
        found=1;
        break;
        }
            temp=temp->next;
            pos++;
    }
    if(!found)
    printf("element not in list....");
}
int main(){
    int ch;
    while(1){
          printf("\n1: Insert at Start\n2: Insert at End\n3: Insert at Position\n4: Delete from Start\n5: Delete from End\n6: Delete from Position\n7: Search\n8: Display Ascending\n9: Display Descending\n10: Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:insertB();
            break;
            case 2:insertE();
            break;
            case 3:insertP();
            break;
            case 4:deleteB();
            break;
            case 5:deleteE();
            break;
            case 6:deleteP();
            break;
            case 7:search();
            break;
            case 8:displayA();
            break;
            case 9:displayD();
            break;
            case 10:printf("exiting....");
            exit(0);
            
            default:printf("Invalid input....");
        }
    }
}