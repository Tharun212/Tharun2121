#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* left;
    struct node* right;
};

struct node* create(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int key) {
    if (root == NULL) {
        return create(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

struct node* search(struct node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    } else if (root->key > key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

void inorder(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

void preorder(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

struct node* smallest(struct node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* largest(struct node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

int height(struct node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int left = height(root->left);
        int right = height(root->right);
        if (left > right) {
            return (left + 1);
        } else {
            return (right + 1);
        }
    }
}

int main() {
    struct node* root = NULL;
    int choice, key, search_key;
    do {
        printf("1.Insert a key\n");
        printf("2.Search for a key\n");
        printf("3.Inorder Traversal\n");
        printf("4.Preorder Traversal\n");
        printf("5.Postorder Traversal\n");
        printf("6.Find Smallest Node\n");
        printf("7.Find Largest Node\n");
        printf("8.Find Tree Height\n");
        printf("9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &search_key);
                struct node* search_result = search(root, search_key);
                if (search_result == NULL) {
                    printf("%d not found\n", search_key);
                } else {
                    printf("%d found\n", search_key);
                }
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                if (root == NULL) {
                    printf("No key present. Please Try after inserting a key\n");
                    break;
                }
                printf("Smallest node is: %d\n", smallest(root)->key);
                break;
            case 7:
                if (root == NULL) {
                    printf("No key present. Please Try after inserting a key\n");
                    break;
                }
                printf("Largest node is: %d\n", largest(root)->key);
                break;
            case 8:
                printf("Height of tree: %d\n", height(root));
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
        }
    } while (choice != 9);

    return 0;
}

