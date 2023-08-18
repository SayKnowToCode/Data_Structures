#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to push a node onto the stack
void push(struct Node** stackTop, struct Node* newNode) {
    newNode->next = *stackTop;
    *stackTop = newNode;
}

// Function to pop a node from the stack
struct Node* pop(struct Node** stackTop) {
    if (*stackTop == NULL) {
        return NULL; // Stack is empty
    }
    struct Node* poppedNode = *stackTop;
    *stackTop = (*stackTop)->next;
    return poppedNode;
}

// Function to reverse a linked list using a stack
void reverseLinkedList(struct Node** head) {
    if (*head == NULL) {
        return; // Empty list
    }

    struct Node* stackTop = NULL;
    struct Node* current = *head;

    while (current != NULL) {
        struct Node* nextNode = current->next;
        push(&stackTop, current);
        current = nextNode;
    }

    *head = NULL;
    while (stackTop != NULL) {
        struct Node* poppedNode = pop(&stackTop);
        if (*head == NULL) {
            *head = poppedNode;
            current = *head;
        } else {
            current->next = poppedNode;
            current = current->next;
        }
    }
    current->next = NULL;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    for (int i = 1; i <= 5; ++i) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    printf("Original linked list: ");
    printList(head);

    reverseLinkedList(&head);

    printf("Reversed linked list: ");
    printList(head);

    // Free allocated memory
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
