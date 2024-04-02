#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNewNode(int data) {#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct Node {
    int data;
    struct Node* next;
};

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        struct Node* runner = current;

        // Iterate through the list to remove nodes with the same data
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                struct Node* temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }

        current = current->next;
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* last = *head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Example input: 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
    insertEnd(&head, 12);
    insertEnd(&head, 11);
    insertEnd(&head, 12);
    insertEnd(&head, 21);
    insertEnd(&head, 41);
    insertEnd(&head, 43);
    insertEnd(&head, 21);

    printf("Original Linked List: ");
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    printf("Linked List after removing duplicates: ");
    printList(head);

    return 0;
}

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void removeDuplicatesFromLinkedList(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* current = head;
    struct Node* next;

    while (current != NULL) {
        next = current;
        while (next->next != NULL) {
            if (current->data == next->next->data) {
                struct Node* duplicate = next->next;
                next->next = next->next->next;
                free(duplicate);
            } else {
                next = next->next;
            }
        }
        current = current->next;
    }
}


