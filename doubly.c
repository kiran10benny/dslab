#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next,*prev;
};
struct Node *head=NULL,*temp;

struct Node *createNode(){
int val;
struct Node* newnode = malloc(sizeof(struct Node));
    if (!newnode) {
        printf("Memory allocation failed\n");

                }
printf("Enter  element to be inserted  :  ");
scanf("%d",&val);
newnode->data=val;
newnode->next=newnode->prev=NULL;
return newnode;
}
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    printf("Elements are: ");
    while (temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_b(){
struct Node *newnode=createNode();
if(head==NULL)
head=newnode;
else{
newnode->next=head;
head->prev=newnode;
head-newnode;
}
printf("element inseted at beginning  :)");
}

void insert_e(){
struct Node *newnode=createNode();
if(head==NULL)
head=newnode;

else{
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
newnode->prev=temp;
}
printf("element inserted at end :)");
}
int main() {
    int ch = 0;
    while (ch != 8) {
        printf("\nEnter your choice:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
/*        printf("3. Insert at a position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from a position\n");*/
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: insert_b(); break;
            case 2: insert_e(); break;
            /*case 3: insert_pos(); break;
            case 4: delb(); break;
            case 5: dele(); break;
            case 6: pos(); break;*/
            case 7: display(); break;
            case 8: printf("Exiting...\n"); break;
            default: printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}


