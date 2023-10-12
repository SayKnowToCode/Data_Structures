// Delete a node from BST
// If leaf node - Delete directly
// If node has only one child adjust link of previous to next
// For 2 children, Max in Left Subtree or Min in Right Subtree

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
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);

    return root;
}

bNode *Max(bNode *root)
{
    if (root == NULL)
        return root;

    else if (root->right == NULL)
        return root;

    else
        return Max(root->right);
}

bNode *Min(bNode *root)
{
    if (root == NULL)
        return root;
    else if (root->left == NULL)
        return root;
    else
    {
        return Min(root->left);
    }
}

bNode *Search(bNode *root, int data)
{
    if (root == NULL)
        return root;

    else if (root->data == data)
        return root;

    else if (data <= root->data)
        return Search(root->left, data);

    else
        return Search(root->right, data);
}

void getPredecessor(bNode *root, int data)
{
    if (root == NULL)
    {
        printf("Tree doesnt exist");
        return;
    }

    bNode *current = Search(root, data);
    if (current == NULL)
    {
        printf("Data doesnt exist in Tree\n");
        return;
    }

    if (data == Min(root)->data)
    {
        printf("Predecessor doesnt exist");
    }

    if (current->left != NULL)
    {
        printf("The succesor = %d\n", Max(current->left)->data);
        return;
    }

    else
    {
        bNode *predecessor = NULL;
        bNode *next = root;
        while (next != current)
        {
            if (current->data >= next->data)
            {
                predecessor = next;
                next = next->right;
            }
            else
                next = next->left;
        }
        printf("The predecessor = %d\n", predecessor->data);
    }
}

void main()
{
    bNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 17);
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 16);
    root = Insert(root, 24);
    root = Insert(root, 12);
    root = Insert(root, 11);
    root = Insert(root, 14);

    getPredecessor(root, 5);
}