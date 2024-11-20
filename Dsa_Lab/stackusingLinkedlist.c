#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void linkedListTraversal(struct Node *ptr) {
    printf("Stack: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int isEmpty(struct Node *top) {
    return (top == NULL);
}

int isFull(struct Node *top) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    int isFull = (p == NULL);
    free(p);
    return isFull;
}

struct Node *push(struct Node *top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
    } else {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        if (n == NULL) {
            printf("Memory allocation failed.\n");
            return top;
        }
        n->data = x;
        n->next = top;
        top = n;
        printf("Pushed element: %d\n", x);
        return top;
    }
}

int pop(struct Node **top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        struct Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main() {
    int choice, element;

    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                top = push(top, element);
                break;
            case 2:
                element = pop(&top);
                if (element != -1) {
                    printf("Popped element is %d\n", element);
                }
                break;
            case 3:
                linkedListTraversal(top);
                break;
            case 4:
                printf("Exiting program.\n");
                // Free memory for the entire stack
                while (top != NULL) {
                    struct Node *temp = top;
                    top = top->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
