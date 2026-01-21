// This is combined AVL Tree and Unbalanced Binary Search Tree (BST) implementation in C
// from AVL Tree Default.c and Unbalanced BST.c
// with main function
// with Data Generator (line 26-40)
// with Benchmarking functions (line 248-286)
// with additional trivial function avl_search (line 301-308)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// AVL Tree implementation
typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left, *right;
} AVLNode;

// Create node
AVLNode* avl_newNode(int key) {
    AVLNode* n = malloc(sizeof(AVLNode));
    n->key = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// Generate test data
void generate_random(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (n * 10);
}

void generate_sorted(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void generate_reverse(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = n - i;
}

// Height
int height(AVLNode* n) {
    return n ? n->height : 0;
}

// Max
int max(int a, int b) {
    return a > b ? a : b;
}

// Balance factor
int getBalance(AVLNode* n) {
    if (!n) return 0;
    return height(n->left) - height(n->right);
}

// Right rotation
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert with balancing
AVLNode* avl_insert(AVLNode* node, int key) {
    if (!node) return avl_newNode(key);

    if (key < node->key)
        node->left = avl_insert(node->left, key);
    else if (key > node->key)
        node->right = avl_insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rotateRight(node);

    // RR
    if (balance < -1 && key > node->right->key)
        return rotateLeft(node);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Get minimum
AVLNode* avl_min(AVLNode* root) {
    while (root->left) root = root->left;
    return root;
}

// Delete with balancing
AVLNode* avl_delete(AVLNode* root, int key) {
    if (!root) return root;

    if (key < root->key)
        root->left = avl_delete(root->left, key);
    else if (key > root->key)
        root->right = avl_delete(root->right, key);
    else {
        if (!root->left || !root->right) {
            AVLNode *temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = avl_min(root->right);
            root->key = temp->key;
            root->right = avl_delete(root->right, temp->key);
        }
    }

    if (!root) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    // Rebalance cases
    if (balance > 1 && getBalance(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

// Unbalanced Binary Search Tree (BST) implementation in C
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

// Benchmarking functions (insert, search, delete)
double now() {
    return (double)clock() / CLOCKS_PER_SEC;
}

// You must add this trivial function
AVLNode* avl_search(AVLNode* root, int key) { //function to search a key in AVL tree
    if (root == NULL || root->key == key) return root; //if root is null or key found, return root
    if (key < root->key) return avl_search(root->left, key); //search in left subtree if key is smaller than root's key
    return avl_search(root->right, key); //search in right subtree otherwise
}

void benchmark(const char *label, int *data, int n) {
    BSTNode *bst = NULL;
    AVLNode *avl = NULL;

    printf("\n=== %s Dataset (%d items) ===\n", label, n);

    // ---------------- INSERT ----------------
    double t1 = now();
    for (int i = 0; i < n; i++)
        bst = bst_insert(bst, data[i]);
    double t2 = now();

    double t3 = now();
    for (int i = 0; i < n; i++)
        avl = avl_insert(avl, data[i]);
    double t4 = now();

    printf("Insert: BST = %.6f sec | AVL = %.6f sec\n", t2 - t1, t4 - t3);

    // ---------------- SEARCH ----------------
    t1 = now();
    for (int i = 0; i < n; i++)
        bst_search(bst, data[i]);
    t2 = now();

    t3 = now();
    for (int i = 0; i < n; i++)
        avl_search(avl, data[i]); // You must add this trivial function
    t4 = now();

    printf("Search: BST = %.6f sec | AVL = %.6f sec\n", t2 - t1, t4 - t3);

    // ---------------- DELETE ----------------
    t1 = now();
    for (int i = 0; i < n; i++)
        bst = bst_delete(bst, data[i]);
    t2 = now();

    t3 = now();
    for (int i = 0; i < n; i++)
        avl = avl_delete(avl, data[i]);
    t4 = now();

    printf("Delete: BST = %.6f sec | AVL = %.6f sec\n", t2 - t1, t4 - t3);
}

//
int main() {
    srand(time(NULL));

    int n = 30000; // adjust depending on your laptop
    int *arr = malloc(sizeof(int) * n);

    generate_random(arr, n);
    benchmark("Random", arr, n);

    generate_sorted(arr, n);
    benchmark("Sorted", arr, n);

    generate_reverse(arr, n);
    benchmark("Reverse-sorted", arr, n);

    free(arr);
    return 0;
}
