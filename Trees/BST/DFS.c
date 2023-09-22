// Implementing all three Depth First Search Traversal

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

void PreOrder(bNode *root)
{
    if(root == NULL) return;
    
    printf("%d ",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(bNode *root)
{
    if(root == NULL) return;
    
    InOrder(root->left);
    printf("%d ",root->data);
    InOrder(root->right);
}

void PostOrder(bNode *root)
{
    if(root == NULL) return;
    
    PostOrder(root->left); 
    PostOrder(root->right);
    printf("%d ",root->data);
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

    printf("Enter your choice : \n");
    int ch;
    printf("1 for PreOrder\n");
    printf("2 for InOrder\n");
    printf("3 for PostOrder\n");
    scanf("%d",&ch);
    
    switch (ch)
    {
        case 1:
        {
            PreOrder(root);
            printf("\n");
        }
        case 2:
        {
            InOrder(root);
            printf("\n");
        }
        case 3:
        {
            PostOrder(root);
            printf("\n");
        }
    }
}