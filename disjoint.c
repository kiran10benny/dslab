#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node*next;
    struct Node*head;
};

struct set{
    struct Node* head;
    struct Node* tail;
};
struct set* sets[100];
int setCount = 0;

void make_set(int x){
    struct Node* new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data=x;
    new_node->head=new_node;
    new_node->next=NULL;
    struct set* new_set= (struct set*)malloc(sizeof(struct set));
    new_set->head=new_node;
    new_set->tail=new_node;
    sets[setCount++]=new_set;   
}
 struct Node* find_set(int x){

    struct Node* temp;
    for (int i=0; i<setCount;i++){
        temp= sets[i]->head;
        while(temp!=NULL){
            if (temp->data == x){
                return temp->head;
            }
            temp=temp->next;

        }
    }
    return NULL;
 }
void union_set(struct Node* x, struct Node* y){
     struct set* setX=NULL;
    struct set* setY=NULL;
    for(int i=0;i<setCount;i++){
        if(sets[i]->head==x){
            setX=sets[i];
        }
        if(sets[i]->head==y){
            setY=sets[i];
        }
    }

    setX->tail->next=y->head;
    setX->tail=setY->tail;

    struct Node*temp=setY->head;
    while(temp!=NULL){
        temp->head=x->head;
        temp=temp->next;
    }

    for (int i = 0; i < setCount; i++) {
        if (sets[i] == setY) {
            for (int j = i; j < setCount - 1; j++)
                sets[j] = sets[j + 1];
            setCount--;
            break;
        }

    }
}
void display(){
    struct Node*temp=NULL;

    for(int i=0; i<setCount;i++){
        printf("{");
        temp=sets[i]->head;
        while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
        }
        printf("}\n");
    }

}

 int main(){
    struct Node* element = NULL;
    struct Node* element1 = NULL;
    struct Node* element2 = NULL;
    int x=-1;
    int y=-1;
    printf("Union-set\n");
    int choice=0;
    printf("Enter the choice:\n");

    while (choice!=-1){
        printf("1. makeset\n2. find\n3. union: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the set: ");
            scanf("%d",&x);
            make_set(x);
            display();
            break;
        case 2:
            printf("Enter the element to search: ");
            scanf("%d",&x);
            struct Node* element=find_set(x);
            if (element==NULL){
                printf("Not found");
            }
            else{
            printf("The representative is %d\n",element->data);
            }
            break;
        case 3:
            printf("Enter the elements to make the union: ");
            scanf("%d %d",&x,&y);
            struct Node* element1=find_set(x);
            struct Node* element2=find_set(y);
            if (element1->data==element2->data){
                printf("Same Disjoin Set\n");
                break;
            }
            else{
                union_set(element1,element2);
            }
            display();
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }
}
