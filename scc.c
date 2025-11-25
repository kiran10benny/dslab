#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* graph[MAX];
Node* revGraph[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}


void addEdge(Node* adj[], int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}


void dfs1(int v) {
    visited[v] = 1;

    Node* temp = graph[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs1(temp->vertex);
        temp = temp->next;
    }

    stack[++top] = v;
}

void dfs2(int v) {
    printf("%d ", v);
    visited[v] = 1;

    Node* temp = revGraph[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            dfs2(temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);


    for (int i = 0; i < V; i++) {
        graph[i] = NULL;
        revGraph[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter edges :\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
        addEdge(revGraph, v, u);
    }


    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);


    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("\nStrongly Connected Components:\n");


    while (top != -1) {
        int v = stack[top--];

        if (!visited[v]) {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}
