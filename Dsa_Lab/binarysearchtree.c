#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

struct TreeNode* search(struct TreeNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 50);

    printf("Inorder traversal of BST: ");
    inorderTraversal(root);
    printf("\n");

    int key = 10;
    struct TreeNode* result = search(root, key);
    if (result != NULL) {
        printf("%d found in the BST\n", key);
    } else {
        printf("%d not found in the BST\n", key);
    }

    key = 80;
    result = search(root, key);
    if (result != NULL) {
        printf("%d found in the BST\n", key);
    } else {
        printf("%d not found in the BST\n", key);
    }

    return 0;
}

