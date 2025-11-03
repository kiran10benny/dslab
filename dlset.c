#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for each element node
typedef struct Node {
    int data;
    struct Node* next;
    struct Set* set; // pointer to the set it belongs to
} Node;

// Structure for a set
typedef struct Set {
    Node* head;    // pointer to first element
    Node* tail;    // pointer to last element for easy union
} Set;

Node* nodes[100]; // store pointers to all nodes for quick access
int n;            // number of elements

// Function to create a new set with a single element
Set* makeSet(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Set* newSet = (Set*)malloc(sizeof(Set));
    newSet->head = newNode;
    newSet->tail = newNode;

    newNode->set = newSet;

    return newSet;
}

// Function to find the representative of the set for a node
int findSet(Node* node) {
    return node->set->head->data; // representative is the head element
}

// Union two sets using linked list
void unionSets(Node* node1, Node* node2) {
    Set* set1 = node1->set;
    Set* set2 = node2->set;

    if (set1 == set2) {
        printf("Elements %d and %d are already in the same set.\n", node1->data, node2->data);
        return;
    }

    // append set2's list to set1
    set1->tail->next = set2->head;
    set1->tail = set2->tail;

    // update set pointer of all nodes in set2
    Node* temp = set2->head;
    while (temp != NULL) {
        temp->set = set1;
        temp = temp->next;
    }

    printf("Sets containing %d and %d have been united.\n", node1->data, node2->data);
}

// Display all sets
void display(Node* allNodes[], int n) {
    int printed[100] = {0};
    printf("\nDisjoint Sets:\n");

    for (int i = 0; i < n; i++) {
        Set* set = allNodes[i]->set;
        if (!printed[set->head->data]) {
            printf("{ ");
            Node* temp = set->head;
            while (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("}\n");
            printed[set->head->data] = 1;
        }
    }
}

int main() {
    int choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    Set* sets[100]; // store sets
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        sets[i] = makeSet(val);
        nodes[i] = sets[i]->head;
    }

    while (1) {
        printf("\n====== DISJOINT SET MENU ======\n");
        printf("1. Union two sets\n");
        printf("2. Find representative of an element\n");
        printf("3. Display all disjoint sets\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);

                Node* nodeX = NULL;
                Node* nodeY = NULL;
                for (int i = 0; i < n; i++) {
                    if (nodes[i]->data == x) nodeX = nodes[i];
                    if (nodes[i]->data == y) nodeY = nodes[i];
                }

                if (nodeX && nodeY) unionSets(nodeX, nodeY);
                else printf("One or both elements not found!\n");
                break;

            case 2:
                printf("Enter element to find representative: ");
                scanf("%d", &x);

                Node* node = NULL;
                for (int i = 0; i < n; i++) {
                    if (nodes[i]->data == x) node = nodes[i];
                }

                if (node) printf("Representative of %d is %d\n", x, findSet(node));
                else printf("Element %d not found!\n", x);
                break;

            case 3:
                display(nodes, n);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
