// Basic Implementation of Binary Search Tree

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

bool Search(bNode *root, int data)
{
    if(root==NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) {return Search(root->left,data);}
    else {return Search(root->right,data);}    
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
    if(Search(root,23) == true)
        printf("Elemnt found");
    else
        printf("Element not found");
}