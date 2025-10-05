#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push() {
    struct Node *newnode = malloc(sizeof(struct Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
    printf("New element inserted\n");
}

void pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return;
    }
    struct Node *temp = top;
    top = top->next;
    printf("%d deleted\n", temp->data);
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack empty\n");
        return;
    }
    struct Node *temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    int val, pos = 1, found = 0;
    printf("Enter the element to be searched: ");
    scanf("%d", &val);
    struct Node *temp = top;
    while (temp != NULL) {
        if (temp->data == val) {
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (found)
        printf("Element %d found at position %d\n", val, pos);
    else
        printf("Element not found\n");
}

int main() {
    int ch;
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Search\n5. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid input\n");
        }
    }
    return 0;
}
