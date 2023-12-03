#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define NaN INT_MIN
#define ROOT 0
#define LEFT 1
#define RIGHT 2

int top = -1;
int stack[100];

void stack_push(int data) {
    stack[++top] = data;
}

int stack_pop() {
    return stack[top--];
}

typedef struct node_t
{
    int data;
    struct node_t *left;
    struct node_t *right;
} node_t;

node_t *newnode(int data)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}


node_t *maxnode(node_t *root)
{
    if (root != NULL) {
        if (root->right == NULL) {
            return root;
        } else {
            return maxnode(root->right);
        }
    }
    return NULL;
}

node_t *minnode(node_t *root)
{
    if (root != NULL) {
        if (root->left == NULL) {
            return root;
        } else {
            return minnode(root->left);
        }
    }
    return NULL;
}

void printIndent(int level)
{
    for (int i = 1; i < level; i++)
    {
        if (stack[i - 1] == LEFT) {
            printf("│ ");
        }  else {
            printf("  ");
        }
    }
}

void treeContent(int data, int level, int pos)
{
    printIndent(level);

    if (level > 0 && pos != ROOT)
    {
        if (pos == LEFT) {
            printf("├─");
        }
        else if (pos == RIGHT) {
            printf("└─");
        }
    }

    if (data == NaN) {
        printf("null\n");
    } else {
        printf("%d\n", data);
    }
}

void printTree(node_t *root, int level, int pos)
{
    if (root != NULL)
    {
        treeContent(root->data, level, pos);
        stack_push(LEFT);
        printTree(root->left, level + 1, LEFT);
        stack_pop();
        stack_push(RIGHT);
        printTree(root->right, level + 1, RIGHT);
        stack_pop();
    }
    else
    {
        treeContent(NaN, level, pos);
    }
}

void bst_insert(node_t **root, int data)
{
    if (*root == NULL)
    {
        *root = newnode(data);
    }
    else if (data <= (*root)->data)
    {
        bst_insert(&(*root)->left, data);
    }
    else if (data > (*root)->data)
    {
        bst_insert(&(*root)->right, data);
    }
}

node_t *bst_search(node_t *root, int key) {
    if (root != NULL) {
        if (root->data == key) {
            return root;
        } else if (root->data > key) {
            return bst_search(root->left, key);
        } else {
            return bst_search(root->right, key);
        }
    }
    return NULL;
}

node_t *tmp = NULL;

int bst_remove(node_t **root, int key) {
    if (*root != NULL) {

        if ((*root)->data > key) {
            return bst_remove(&(*root)->left, key);
        } else if ((*root)->data < key) {
            return bst_remove(&(*root)->right, key);
        } else {
            node_t *temp = NULL;
            if ((*root)->left == NULL) {
                temp = (*root);
                (*root) = (*root)->right;
                free(temp);
               return key; 
            } else if((*root)->right == NULL) {
                temp = (*root);
                (*root) = (*root)->left;
                free(temp);
                return key;
            } else {
                temp = minnode((*root)->right);
                (*root)->data = temp->data;
                return bst_remove(&(*root)->right, temp->data);
            }
        }
    }
    return NaN;
}

void bst_free(node_t *root) {
    if (root != NULL) {
        bst_free(root->left);
        bst_free(root->right);
        free(root);
    }
}

int main()
{
    system("chcp 65001");
    int list[] = {2, 4, 6, 8, 11, 13, 15, 18};
    int size = sizeof(list) / sizeof(list[0]);
    node_t *root = newnode(10);
    for (int i = 0; i < size; i++)
    {
        bst_insert(&root, list[i]);
    }
    bst_remove(&root, 2);
    bst_remove(&root, 15);
    bst_remove(&root, 18);
    bst_remove(&root, 6);

    printTree(root, 0, ROOT);
    bst_free(root);
    return 0;
}
