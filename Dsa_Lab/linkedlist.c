#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("List elements are: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtIndex(struct Node** head_ref, int index) {
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    if (index == 1) {
        deleteAtBeginning(head_ref);
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 1; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Invalid index. Cannot delete.\n");
        return;
    }
    struct Node* to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

int main() {
    struct Node* head = NULL;

    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    displayList(head);

    deleteAtBeginning(&head);
    displayList(head);

    deleteAtEnd(&head);
    displayList(head);

    insertAtBeginning(&head, 4);
    insertAtEnd(&head, 5);
    insertAtEnd(&head, 6);
    displayList(head);

    deleteAtIndex(&head, 2);
    displayList(head);

    return 0;
}
