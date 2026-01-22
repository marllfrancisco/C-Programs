// Unbalanced Binary Search Tree (BST) implementation in C
// no rotations or balancing, no main function

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
    int key;
    struct BSTNode *left, *right;
} BSTNode;

// Create node
BSTNode* bst_newNode(int key) {
    BSTNode* n = malloc(sizeof(BSTNode));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

// Insert (unbalanced)
BSTNode* bst_insert(BSTNode* root, int key) {
    if (root == NULL) return bst_newNode(key);

    if (key < root->key)
        root->left = bst_insert(root->left, key);
    else if (key > root->key)
        root->right = bst_insert(root->right, key);

    return root;
}

// Search
BSTNode* bst_search(BSTNode* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return bst_search(root->left, key);
    return bst_search(root->right, key);
}

// Find smallest
BSTNode* bst_min(BSTNode* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Delete
BSTNode* bst_delete(BSTNode* root, int key) {
    if (!root) return NULL;

    if (key < root->key) {
        root->left = bst_delete(root->left, key);
    } else if (key > root->key) {
        root->right = bst_delete(root->right, key);
    } else {
        if (!root->left) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (!root->right) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = bst_min(root->right);
        root->key = temp->key;
        root->right = bst_delete(root->right, temp->key);
    }

    return root;
}
