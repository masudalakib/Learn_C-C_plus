#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

int main() {
    struct Node* head = NULL;


    int value;
    printf("Enter a value : ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->prev = NULL;
        newNode->next = NULL;
        head = newNode;
    } else {
        newNode->next = head; //new node current head
        head->prev = newNode; // Current head previous
        head = newNode;
    }

    // Delete
    printf("Enter a value to delete: ");
    scanf("%d", &value);

    struct Node* current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found in list.\n");
    } else {
        if (current->prev == NULL) { // Deleting head
            head = current->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        } else if (current->next == NULL) { // Deleting tail
            current->prev->next = NULL;
        } else { // Deleting  middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        free(current); // delete free memory
    }

    // Search
    printf("Enter a value to search: ");
    scanf("%d", &value);

    current = head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value not found.\n");
    } else {
        printf("Value not found.\n");
    }

    // Traversal
    current = head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Size count
    int count = 0;
    current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    printf("Number of nodes: %d\n", count);

    return 0;
}
