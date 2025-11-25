#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
typedef struct Node{
    int data;
    struct Node*next;
}Node;

Node* adj_list[MAX];
bool visited[MAX];

int vertex_count=0;
Node* create_node(int vertix){

    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data=vertix;
    new_node->next=NULL;
    return new_node;
}

void add_vertex(){
    if(vertex_count<MAX){
        adj_list[vertex_count]=NULL;
        printf("Vertex %d added.\n", vertex_count);
        vertex_count++;

    }
    else{
        printf("Maximum number of vertices reached.\n");

    }
}

void add_edge(int start, int end){
    if(start>=vertex_count||end>= vertex_count){
        printf("invalid Vertex.\n");
        return; 
    }
    Node* new_node=create_node(end);
    new_node->next= adj_list[start];
    adj_list[start]=new_node;
    printf("Edge added between %d and %d.\n", start,end);

}

void bfs(int start){
    if(start>vertex_count){
        printf("vertex invalid");
        return;
    }
    for (int i=0;i<vertex_count;i++){
        visited[i]=false;
    }
    int queue[MAX],front=0,rear=0;
    visited[start]=true;
    queue[rear++]=start;

    printf("bfs traversal: ");
    while(front<rear){
        int vertex=queue[front++];
        printf("%d ", vertex);

        Node* adj = adj_list[vertex];
        while(adj!=NULL){
            if(!visited[adj->data]){
                visited[adj->data]=true;
                queue[rear++]=adj->data;
            }
            adj= adj->next;
        }

    }
    printf("\n");
}

void dfs_recursion(int vertex){
    visited[vertex]= true;
    printf("%d ", vertex);
    Node* adj = adj_list[vertex];
    while (adj!= NULL){
        if(!visited[adj->data]){
            dfs_recursion(adj->data);
        }
        adj= adj->next;
    }
}

void dfs(int start){
    printf("DEBUG: start=%d, vertex_count=%d\n", start, vertex_count);
    if (start >= vertex_count) {
        printf("Invalid start vertex.\n");
        return;
    }

    for (int i=0;i< vertex_count; i++){
        visited[i]=false;
    }

    printf("DFS: ");
    dfs_recursion(start);
    printf("\n");
}

void topo_sort_recursion(int vertex, int stack[],int *top){

    visited[vertex]= true;
    Node* adj = adj_list[vertex];
    while(adj!= NULL){
        if(!visited[adj->data]){
            topo_sort_recursion(adj->data,stack,top);
        }
        adj=adj->next;
    }
    stack[(*top)++]=vertex;
}

void topological_sort(){
    for (int i=0;i<vertex_count;i++){
        visited[i]=false;
    }

int stack[MAX],top=0;
for (int i=0;i<vertex_count;i++){
    if(!visited[i]){
        topo_sort_recursion(i,stack,&top);
    }
}
printf("Topological Sort: ");
while(top>0){
    printf("%d ",stack[--top]);

}
    printf("\n");
}

int main() {
    int choice, start, end, vertex;
    do {
        printf("\n1. Add Vertex\n2. Add Edge\n3. BFS\n4. DFS\n5. Topological Sort\n6.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_vertex();
                break;
            case 2:
                printf("Enter start and end vertex: ");
                scanf("%d %d", &start, &end);
                add_edge(start, end);
                break;
            case 3:
                printf("Enter starting vertex for BFS: ");
                scanf("%d", &vertex);
                bfs(vertex);
                break;
            case 4:
                printf("Enter starting vertex for DFS: ");
                scanf("%d", &vertex);
                dfs(vertex);
                break;
            case 5:
                topological_sort();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
