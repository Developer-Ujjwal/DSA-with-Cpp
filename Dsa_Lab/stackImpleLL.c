#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Linked list utility function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        // Memory allocation failed
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(struct Node* stack) {
    return stack == NULL;
}

// Function to push elements onto the stack
void push(struct Node** stack, int data) {
    struct Node* newNode = createNode(data);
    if (newNode) {
        newNode->next = *stack;
        *stack = newNode;
    } else {
        printf("Stack Overflow!\n");
    }
}

// Function to pop an element from the stack
int pop(struct Node** stack) {
    if (isEmpty(*stack)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    struct Node* temp = *stack;
    int poppedData = temp->data;
    *stack = (*stack)->next;
    free(temp);
    return poppedData;
}

// Function to peek at the top element of the stack
int peek(struct Node* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->data;
}


int main() {
    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("Stack: ");
    while (!isEmpty(stack)) {
        printf("%d ", peek(stack));
        pop(&stack);
    }
    printf("\n");

    return 0;
}
