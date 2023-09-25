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

void InOrder(bNode *root)
{
    if(root == NULL) return;
    
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void MirrorImage(bNode *root)
{
    if (root == NULL) return;
    
    MirrorImage(root->left);
    MirrorImage(root->right);
    
    bNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void main()
{
    bNode *root = NULL;
    root = Insert(root,15);
    root = Insert(root,20);
    root = Insert(root,10);
    root = Insert(root,25);
    root = Insert(root,8);
    root = Insert(root,12);
    InOrder(root);
    MirrorImage(root);
    printf("\n");
    InOrder(root);
}