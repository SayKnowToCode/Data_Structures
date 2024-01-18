// Basic Implementation of Binary Search Tree

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
    int balance;
} bNode;

char str[4];
int k;
bNode *temp;

bNode *GetNewNode(int data)
{
    bNode *newNode = (bNode *)malloc(sizeof(bNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->balance = 0;
    return newNode;
}

int Max(int a, int b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else
        return a;
}

int FindHeight(bNode *root)
{
    if (root == NULL)
        return -1;

    return (Max(FindHeight(root->left), FindHeight(root->right)) + 1);
}

bNode *Insert(bNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
        // str[(++k) % 2] = 'L';
    }
    else
    {
        root->right = Insert(root->right, data);
        // str[(++k) % 2] = 'R';
    }
    root->balance = FindHeight(root->left) - FindHeight(root->right);
    return root;
}

bool Search(bNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
    {
        return Search(root->left, data);
    }
    else
    {
        return Search(root->right, data);
    }
}

void InOrder(bNode *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

bNode *CheckImbalance(bNode *root)
{
    if (root == NULL)
        return NULL;

    if ((root->balance == 0) || (root->balance == -1) || (root->balance == 1))
    {
        root = CheckImbalance(root->left);
        if (root != NULL)
            return root;
        else
            return NULL;

        root = CheckImbalance(root->right);
        if (root != NULL)
            return root;
        else
            return NULL;
    }

    else
        return root;
}

int Decision(bNode *root, bNode *temp1, int data)
{
    k = 0;
    while (root != temp1)
    {
        if (data < root->data)
            root = root->left;
        else
            root = root->right;
    }

    while (root->data != data)
    {
        if (data < root->data)
        {
            str[k++] = 'L';
            root = root->left;
        }
        else
        {
            str[k++] = 'L';
            root = root->right;
        }
    }

    if (str[0] == 'L' && str[1] == 'L')
        return 1;
    else
        return 8;
}

bNode *RotateLL(bNode *root)
{
    if (root == temp)
    {
        bNode *tp = root;
        root = root->left;
        tp->left = root->right;
        root->right = tp;
    }

    else
    {
        root->left = RotateLL(root->left);
        root->right = RotateLL(root->right);
    }

    return root;
}

void main()
{
    bNode *root = NULL;
    root = Insert(root, 45);
    root = Insert(root, 36);
    root = Insert(root, 63);
    root = Insert(root, 27);
    root = Insert(root, 39);
    InOrder(root);
    while (true)
    {
        printf("\n-1 to Exit OR Enter data : ");
        int data;
        scanf("%d", &data);
        if (data == -1)
            break;
        if (Search(root, data) == true)
        {
            printf("\nDuplicate data is ignored");
            continue;
        }
        else
        {
            root = Insert(root, data);
            temp = CheckImbalance(root);
            if (temp == NULL)
            {
                printf("\nNo imbalance generated");
                continue;
            }
            else
            {
                int option = Decision(root, temp, data);
                switch (option)
                {
                case 1: // LL Rotation
                {
                    root = RotateLL(root);
                    break;
                }
                default:
                    printf("Case 8");
                }
            }
        }
    }
    InOrder(root);
}