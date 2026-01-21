// Francisco, Llego - AVL Tree with Operations
#include <stdio.h>
#include <stdlib.h>

typedef struct Node { // node struct
    int n, bf;
    struct Node *left;
    struct Node *right;
} Node;

Node *init_node(int n) { // init the node
    Node *result = malloc(sizeof(Node));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->n = n;
        result->bf = 0;
    }

    return result; // then return the pointer to that node (separate from tree)
}

int get_int(void) { // get in func, DRY purposes
    int n = 0;
    while (1) {
        if (scanf("%d", &n) != 1) {
            printf("\nInvalid input!\n");
            while(getchar() != '\n');
            continue;
        }

        while(getchar() != '\n');
        break;
    }

    return n;
}

int tree_height(Node *root) { // get tree height
    if (root == NULL) return 0;

    int L = tree_height(root->left);
    int R = tree_height(root->right);

    return 1 + (L > R ? L : R);
    // ternary operator, but it's like the bigger one is what to get
}

int bf(Node *root) { // calc balance factor
    int L = tree_height(root->left);
    int R = tree_height(root->right);

    return L - R; 
}

Node* right_rotate(Node* root);
Node* left_rotate(Node* root) { // x is root
    Node* right = root->right; // y is right of x
    Node* temp = right->left; // T2 is left of y
    
    // Perform rotation
    right->left = root;
    root->right = temp;

    // Update balance factors
    root->bf = bf(root);
    right->bf = bf(right);

    return right;
}

Node* right_rotate(Node* root) {
    Node* left = root->left; // y is right of x
    Node* temp = left->right; // T2 is left of y
    
    // Perform rotation
    left->right = root;
    root->left = temp;

    // Update balance factors
    root->bf = bf(root);
    left->bf = bf(left);

    return left;
}

void rotate(Node **root) {
    (*root)->bf = bf(*root); // update bf
    if ((*root)->bf > 1) {
        printf("Left heavy!\n");
        if (bf((*root)->left) < 0) { // for double rotations, it checks for direction changes (left-right rotation)
            (*root)->left = left_rotate((*root)->left);
        }

        *root = right_rotate(*root);
    } else if((*root)->bf < -1) {
        printf("Right heavy!\n");
        if (bf((*root)->right) > 0) { // same here (right-left rotation)
            (*root)->right = right_rotate((*root)->right);
        }

        *root = left_rotate(*root);
    }
}

int push(Node **root, int n) {
    if (*root == NULL) { // if empty part
        *root = init_node(n); // add a node there
        return bf(*root); // return val to caller
    }

    if ((*root)->n > n) { // check direction
        push(&(*root)->left, n); // use recursions for traversal
    } else {
        push(&(*root)->right, n);
    }

    rotate(&(*root));

    return bf(*root); // return current node bf
}

void push_node(Node **root) { // expects a double pointer to edit where that pointer points
    while (1) {
        int n = 0;
        if (*root == NULL) { // check if no tree
            printf("Enter the root number (-1 to exit): ");
            n = get_int();
            if (n == -1) return;

            push(&(*root), n);
        } 

        printf("Enter the number (-1 to exit): "); // get the n for the next node
        n = get_int();
        if (n == -1) return;
        int bf = push(&(*root), n);
    }
}

void print_tree(Node *root, int depth) { // sideways reading
    if (root == NULL) return;

    // right subtree traversal first
    print_tree(root->right, depth + 1);

    // indent based on depth
    for (int i = 0; i < depth; i++)
        printf("\t"); // 3 spaces per level

    // print node after indention
    printf("%d(%d)\n\n", root->n, root->bf);

    // then left subtree traversal
    print_tree(root->left, depth + 1);
}

Node *search_tree(Node *root) { // search function
    int n = get_int();

    Node *current = root;
    // directional traversal (since it's still a BST)
    while (current != NULL && current->n != n) {
        if (n > current->n) {
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return current;
}

Node *inorder_successor(Node *root) { // get in-order successor for deletion
    Node *current = root;
    if (current == NULL) return NULL;
    while (current->left) {
        current = current->left; // root is right of actual root, and we just go left until the end
    }
    return current;
}

// Delete a node and return the new subtree root
Node *pop_node(Node *root, int key) {
    if (!root) return NULL;

    if (key < root->n) {
        root->left = pop_node(root->left, key);
    } else if (key > root->n) {
        root->right = pop_node(root->right, key);
    } else {
        // Node found
        if (!root->left && !root->right) { // leaf
            free(root);
            return NULL;
        } else if (!root->left) { // only right child
            Node *tmp = root->right;
            free(root);
            return tmp;
        } else if (!root->right) { // only left child
            Node *tmp = root->left;
            free(root);
            return tmp;
        } else { // two children
            Node *succ = inorder_successor(root->right);
            root->n = succ->n; // copy successor value
            root->right = pop_node(root->right, succ->n); // delete successor
        }
    }

    // Balance after deletion
    rotate(&root);

    return root;
}

// Wrapper for double-pointer usage
Node *pop(Node **root) {
    if (!root || !(*root)) return NULL;

    int key = get_int();

    *root = pop_node(*root, key);

    return *root;
}

void print_inorder(Node *root) {
    if (root == NULL) return;

    print_inorder(root->left);

    printf("%d ", root->n);

    print_inorder(root->right);
}

void print_preorder(Node *root) {
    if (root == NULL) return;

    printf("%d ", root->n);
    
    print_preorder(root->left);

    print_preorder(root->right);
}

void print_postorder(Node *root) {
    if (root == NULL) return;

    print_postorder(root->left);

    print_postorder(root->right);

    printf("%d ", root->n);
}

void free_tree(Node *root) {
    // post order traversal is the safest way to free up a tree I guess
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void menu(Node **tree) {
    int choice = 0;
    while (1) {
        printf("\nComplete AVL Tree\n\n1. Push a node\n2. Delete a node\n3. Show AVL Tree\n4. Search a node/number\n5. Exit\n\n> ");
        choice = get_int();
        switch (choice) {
            case 1:
                push_node(&(*tree));
                if ((*tree) == NULL) {
                    printf("\nNo inputs detected.");
                    exit(0);
                }
                break;
            case 2:
                printf("\n\nRemove a number: ");
                if (pop(&(*tree)) == NULL) {
                    printf("\nNode not found!");
                }

                break;
            case 3:
                printf("\nComplete AVL Tree: (Read left to right):\n");
                print_tree((*tree), 0);
                if ((*tree) == NULL) {
                    printf("\nNo tree exists!\n");
                    continue;
                }

                printf("\n\nTree height: %d", tree_height((*tree)));
                printf("\nBalance Factor (root): %d", bf((*tree)));

                printf("\n\nPre-Order traversal:\n");
                print_preorder((*tree));
                printf("\n\nIn-Order traversal:\n");
                print_inorder((*tree));
                printf("\n\nPost-Order traversal:\n");
                print_postorder((*tree));

                break;
            case 4:
                printf("\n\nSearch for a node/number: ");
                Node *s = search_tree((*tree));
                if (s == NULL) {
                    printf("\nNode not found!");
                } else {
                    printf("\n%d found!", s->n);
                }
                break;
            case 5:
                printf("\n\nThank you for using this demo of an AVL Tree in C!");
                return;
                break;
            default:
                printf("Option not found!");
        }
        continue;
    }
}

int main(void) {
    Node *tree = NULL;

    menu(&(tree));

    free_tree(tree);

    return 0;
}
