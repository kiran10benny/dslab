#include <stdio.h>

#define MAX 100

int parent[MAX];
int elements[MAX];
int n;

// Function to find the index of a given element in the array
int findIndex(int x) {
    for (int i = 0; i < n; i++) {
        if (elements[i] == x)
            return i;
    }
    return -1; // not found
}

// ------------------ MAKE-SET operation ------------------
void makeSet() {
    for (int i = 0; i < n; i++) {
        parent[i] = i; // each element is its own parent
    }
    printf("All sets have been initialized.\n");
}

// ------------------ FIND-SET operation ------------------
int findSet(int i) {
    if (parent[i] != i) {
        parent[i] = findSet(parent[i]); // path compression
    }
    return parent[i];
}

// ------------------ UNION operation ------------------
void unionSets(int x, int y) {
    int idxX = findIndex(x);
    int idxY = findIndex(y);

    if (idxX == -1 || idxY == -1) {
        printf("One or both elements not found!\n");
        return;
    }

    int rootX = findSet(idxX);
    int rootY = findSet(idxY);

    if (rootX == rootY) {
        printf("Elements %d and %d are already in the same set.\n", x, y);
    } else {
        parent[rootY] = rootX;
        printf("Sets containing %d and %d have been united.\n", x, y);
    }
}

// ------------------ FIND REPRESENTATIVE BY ELEMENT VALUE ------------------
void findRepresentative(int x) {
    int idx = findIndex(x);
    if (idx == -1) {
        printf("Element %d not found!\n", x);
        return;
    }

    int repIndex = findSet(idx);
    printf("Representative of %d is %d\n", x, elements[repIndex]);
}

// ------------------ DISPLAY FUNCTION (Show sets) ------------------
void display() {
    int printed[MAX] = {0}; // To mark representatives already printed

    printf("\nDisjoint Sets:\n");
    for (int i = 0; i < n; i++) {
        int rep = findSet(i); // find representative index
        if (!printed[rep]) {
            printf("{ ");
            for (int j = 0; j < n; j++) {
                if (findSet(j) == rep) {
                    printf("%d ", elements[j]);
                }
            }
            printf("}\n");
            printed[rep] = 1; // mark this representative as printed
        }
    }
}

// ------------------ MAIN FUNCTION ------------------
int main() {
    int choice, x, y;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &elements[i]);
    }

    makeSet(); // initialize sets

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
                unionSets(x, y);
                break;

            case 2:
                printf("Enter element to find representative: ");
                scanf("%d", &x);
                findRepresentative(x);
                break;

            case 3:
                display();
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
