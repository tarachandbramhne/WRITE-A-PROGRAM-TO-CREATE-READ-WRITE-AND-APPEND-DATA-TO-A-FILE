/*DELIVERABLE: A MODULAR AND EFFICIENT LINKED LIST IMPLEMENTATION.
*/
#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void traverseList(struct Node* head);
void freeList(struct Node* head);

int main() {
    struct Node* head = NULL;  // Start with an empty list

    // Insert at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    printf("List after insertions at the beginning: ");
    traverseList(head);

    // Insert at the end
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    printf("List after insertions at the end: ");
    traverseList(head);

    // Delete node with value 20
    deleteNode(&head, 20);
    printf("List after deleting node with value 20: ");
    traverseList(head);

    // Free memory and clean up
    freeList(head);

    return 0;
}

// Function to create a new node with a specific value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);  // Exit the program if memory allocation fails
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;  // Make the new node point to the current head
    *head = newNode;  // Update head to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, the new node becomes the head
        return;
    }
    
    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;  // Insert the new node at the end
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // Move head to the next node
        free(temp);  // Free memory of the old head node
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key was not found
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);  // Free the node's memory
}

// Function to traverse and print the list
void traverseList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // Free memory of the current node
    }
}
