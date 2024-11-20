#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; 
        return newNode;
    }
    struct Node *current = head;
    while (current->next != head) {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return newNode;
}
struct Node *deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }
    if (head->next == head) { 
        free(head);
        return NULL;
    }
    struct Node *current = head;
    while (current->next->next != head) {
        current = current->next;
    }
    struct Node *temp = current->next;
    current->next = head;
    free(temp);
    return head;
}

void printCircularList(struct Node *head) {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }
    struct Node *current = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf(" (Head)\n");
}

void freeCircularList(struct Node *head) {
    if (head == NULL) {
        return;
    }
    struct Node *current = head;
    while (current->next != head) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(head);
}

int main() {
    struct Node *head = NULL;
    int choice, data;

    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Display Circular List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                head = deleteFromEnd(head);
                printf("Deleted node from the end.\n");
                break;
            case 3:
                printCircularList(head);
                break;
            case 4:
                printf("Exiting program.\n");
                freeCircularList(head);
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

