// Find Minimum and Maximum element in BST
// Leftmost element is smallest while rightmost is largest

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
}bNode;

bNode *GetNewNode(int data)
{
    bNode *newNode = (bNode*)malloc(sizeof(bNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bNode *Insert(bNode *root,int data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

int Min(bNode *root)
{
    if(root==NULL) return -1;
    else if(root->left == NULL) return root->data;
    else { return Min(root->left); }    
}

int Max(bNode *root)
{
    if(root==NULL) return -1;
    else if(root->right == NULL) return root->data;
    else { return Max(root->right); }    
}

void main()
{
    bNode *root = NULL;
    root = Insert(root,15);
    root = Insert(root,17);
    root = Insert(root,10);
    root = Insert(root,5);
    root = Insert(root,16);
    root = Insert(root,24);
    root = Insert(root,12);
    root = Insert(root,11);
    root = Insert(root,14);
    
    if(Min(root) == -1)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Minimum element = %d\n",Min(root));
    }

    if(Max(root) == -1)
    {
        printf("Tree is empty\n");
    }
    else
    {
        printf("Maximum element = %d\n",Max(root));
    }
}