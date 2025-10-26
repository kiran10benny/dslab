#include<stdio.h>
#include<stdlib.h>
#define SIZE 3240

void insert(int s[],int data){
    if(data<SIZE && data>=0)
    s[data]=1;
    else
    printf("out of range...\n");
}

void display(int s[]){
    printf("{");
    for(int i=0;i<SIZE;i++){
    if(s[i]==1)
    printf("%d ",i);
    }
    printf("}");
}
void Union(int s1[],int s2[],int result[]){
    for(int i=0;i<SIZE;i++)
    result[i]=s1[i] | s2[i];
    printf("union is ....");
    display(result);
}
void intersection(int s1[],int s2[],int result[]){
    for(int i=0;i<SIZE;i++)
    result[i]=s1[i] & s2[i];
    printf("intersection  is ....");
    display(result);
}
void diff(int s1[],int s2[],int result[]){
    for(int i=0;i<SIZE;i++)
    result[i]=s1[i] & (~s2[i]);
    printf("differnce  is ....");
    display(result);
}
int main(){
    int ch,n,m,data,i;
    int result[SIZE]={0},s1[SIZE]={0},s2[SIZE]={0};
    while (1) {
        printf("\n----- MENU -----");
        printf("\n1: Read Set 1");
        printf("\n2: Read Set 2");
        printf("\n3: Union of Sets");
        printf("\n4: Intersection of Sets");
        printf("\n5: Difference (Set2 - Set1)");
        printf("\n6: Difference (Set1 - Set2)");
        printf("\n8: Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch){
            case 1:
            printf("\nEnter number of elements in Set 1: ");
                scanf("%d", &n);
                printf("\nEnter %d elements: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &data);
                    insert(s1, data);
                }
                printf("\nSet 1 is: ");
                display(s1);
                break;
            
            case 2:
            printf("\nEnter number of elements in Set 2: ");
                scanf("%d", &m);
                printf("\nEnter %d elements: ", m);
                for (i = 0; i < m; i++) {
                    scanf("%d", &data);
                    insert(s2, data);
                }
                printf("\nSet 2 is: ");
                display(s2);
                break;
            case 3:Union(s1,s2,result); break;
            case 4:intersection(s1,s2,result); break;
            case 5:diff(s2,s1,result); break;
            case 6:diff(s1,s2,result); break;
            case 7:printf("Exiting...\n");
                    exit(0);
            default:printf("invalid choice....\n");
        }
    }
}
