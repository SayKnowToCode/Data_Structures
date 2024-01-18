// Implementing Deleting a Node through a different approch

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
} bNode;

bNode *GetNewNode(int data)
{
    bNode *newNode = (bNode *)malloc(sizeof(bNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bNode *Insert(bNode *root, int data)
{
    if (root == NULL)
        root = GetNewNode(data);

    else if (data == root->data)
        printf("No duplicates allowed");

    else if (data < root->data)
        root->left = Insert(root->left, data);

    else
        root->right = Insert(root->right, data);

    return root;
}

int typeNode(bNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return 1;
    else if (root->left == NULL || root->right == NULL)
        return 2;
    else if (root->left != NULL && root->right != NULL)
        return 3;
}

int Min(bNode *root)
{
    if (root == NULL)
        return -1;
    else if (root->left == NULL)
        return root->data;
    else
    {
        return Min(root->left);
    }
}

bNode *Delete(bNode *root, int value)
{
    int flag = 0;
    bNode *parent = NULL;
    bNode *current = root;

    if (current == NULL)
    {
        printf("Tree doesnt exist");
        return root;
    }

    if (value == current->data && current->left == NULL && current->right == NULL)
        return NULL;

    while (current != NULL)
    {
        if (value < current->data)
        {
            parent = current;
            current = current->left;
        }

        else if (value > current->data)
        {
            parent = current;
            current = current->right;
        }

        else if (value == current->data)
        {
            flag = 1;
            switch (typeNode(current))
            {
            case 1:
            {
                if (current->data < parent->data)
                    parent->left = NULL;

                else
                    parent->right = NULL;

                free(current);
                current = NULL;
                break;
            }

            case 2:
            {
                if (current->data < parent->data)
                {
                    if (current->left != NULL)
                    {
                        parent->left = current->left;
                    }
                    else
                    {
                        parent->left = current->right;
                    }
                }

                else
                {
                    if (current->left != NULL)
                    {
                        parent->right = current->left;
                    }
                    else
                    {
                        parent->right = current->right;
                    }
                }

                free(current);
                current = NULL;
                break;
            }

            case 3:
            {
                int k = Min(current->right);
                current->data = k;
                current->right = Delete(current->right, k);

                return root;
            }
            }
        }
    }

    if (flag == 0)
    {
        printf("No such node exists \n");
    }

    return root;
}

void InOrder(bNode *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PreOrder(bNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{
    bNode *root = NULL;
    root = Insert(root, 52);
    root = Insert(root, 37);
    root = Insert(root, 44);
    root = Insert(root, 74);
    root = Insert(root, 16);
    root = Insert(root, 28);
    root = Insert(root, 65);
    root = Insert(root, 21);
    root = Insert(root, 91);
    root = Insert(root, 83);

    InOrder(root);
    PreOrder(root);
    printf("\n");
    root = Delete(root, 65);
    InOrder(root);
    printf("\n");
    PreOrder(root);
    printf("\n");
    root = Delete(root, 74);
    InOrder(root);
    printf("\n");
    PreOrder(root);
    printf("\n");
    root = Delete(root, 37);
    InOrder(root);
    printf("\n");
    PreOrder(root);
    printf("\n");

    return 0;
}