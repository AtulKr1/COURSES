#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

typedef struct node tree;

tree *newNode(int item)
{
    tree *temp = (tree *)malloc(sizeof(tree));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

tree *insert(tree *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

tree *inSuccessor(tree *node)
{
    tree *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

tree *deleteNode(tree *root, int key)
{
    if (root == NULL)
        return NULL;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            tree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tree *temp = root->left;
            free(root);
            return temp;
        }

        tree *temp = inSuccessor(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the nodes:\n");
    while(n--)
    {
        int temp;
        scanf("%d", &temp);
        root = insert(root, temp);
    }

    printf("Inorder traversal: ");
    inorder(root);

    int key;
    printf("\nEnter the key to delete: ");
    scanf("%d", &key);
    root = deleteNode(root, key);

    printf("\nAfter deleting\n");
    printf("Inorder traversal: ");
    inorder(root);

    return 0;
}