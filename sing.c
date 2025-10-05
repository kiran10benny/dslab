#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *temp;

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_b() {
    struct Node* newnode = malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Elements are: ");
    display();
}

void insert_e() {
    struct Node* newnode = malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    printf("Elements are: ");
    display();
}

void insert_pos() {
    int pos, i;
    struct Node* newnode = malloc(sizeof(struct Node));
    printf("Enter the element: ");
    scanf("%d", &newnode->data);
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        for (i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
    printf("Elements are: ");
    display();
}

void delb() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    temp = head;
    head = head->next;
    printf("Element deleted: %d\n", temp->data);
    free(temp);
}

void dele() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    if (head->next == NULL) {
        printf("Element deleted: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *prev = NULL;
    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("Element deleted: %d\n", temp->data);
    prev->next = NULL;
    free(temp);
}

void del_pos() {
    int pos, i;
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos == 1) {
        temp = head;
        head = head->next;
        printf("Element deleted: %d\n", temp->data);
        free(temp);
        return;
    }
    struct Node *prev = NULL;
    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    prev->next = temp->next;
    printf("Element deleted: %d\n", temp->data);
    free(temp);
}

int main() {
    int ch;
    while (1) {
        printf("\n1.Insert at Beginning\n2.Insert at End\n3.Insert at Position\n4.Delete from Beginning\n5.Delete from End\n6.Delete from Position\n7.Display\n8.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: insert_b(); break;
            case 2: insert_e(); break;
            case 3: insert_pos(); break;
            case 4: delb(); break;
            case 5: dele(); break;
            case 6: del_pos(); break;
            case 7: display(); break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
