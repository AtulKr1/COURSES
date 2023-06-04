#include <stdio.h>
#include <malloc.h>

struct tree
{
    int key;
    struct tree *left, *right;
};

struct stack
{
    struct tree *data;
    struct stack *next;
};
int stackSize = 0;

void stackPush(struct stack **top, struct tree *x)
{
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    ptr->data = x;
    
    if(top == NULL)
        ptr->next = NULL;
    else
        ptr->next = *top;
    
    (*top) = ptr;

    stackSize++;
}

struct tree *stackPop(struct stack **top)
{
    struct tree *x = (*top)->data;
    struct stack *ptr = *top;
    (*top) = (*top)->next;
    free(ptr);

    stackSize--;
    return x;
}

struct tree *newNode(int item)
{
    struct tree *temp = (struct tree *)malloc(sizeof(struct tree));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct tree *root)
{
    struct stack *top = NULL;
    int flag = 1;

    while(flag)
    {
        if(root)
        {
            stackPush(&top, root);
            root = root->left;
        }
        else
        {
            if(stackSize)
            {
                root = stackPop(&top);
                printf("%d ", root->key);
                root = root->right;
            }
            else
                flag = 0;
        }
    }
}

void preorder(struct tree *root)
{
    struct stack *top = NULL;
    int flag = 1;

    while(flag)
    {
        if(root)
        {
            stackPush(&top, root);
            printf("%d ", root->key);
            root = root->left;
        }
        else
        {
            if(stackSize)
            {
                root = stackPop(&top);
                root = root->right;
            }
            else
                flag = 0;
        }
    }
}

void postorder(struct tree *root)
{
    struct stack *top = NULL;
    int flag = 1;

    while(flag)
    {
        if(root)
        {
            stackPush(&top, root);
            root = root->left;
        }
        else
        {
            if(stackSize)
            {
                root = stackPop(&top);
                root = root->right;
                printf("%d ", root->key);
            }
            else
                flag = 0;
        }
    }
}

struct tree *insert(struct tree *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    struct tree *root = NULL;
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

    printf("\nInorder traversal:\n");
    inorder(root);
    printf("\nPreorder traversal:\n");
    preorder(root);
    printf("\nPostorder traversal:\n");
    postorder(root);

    return 0;
}