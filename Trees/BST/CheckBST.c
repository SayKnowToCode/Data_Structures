// To Check if a BinaryTree is a BST or not

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

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

bool isSubtreeLesser(bNode *root,int value)
{
    if(root == NULL) return true;

    if((root->data <= value) && (isSubtreeLesser(root->left,value)) && (isSubtreeLesser(root->right,value)))
        return true;
    else
        return false;
}

bool isSubtreeGreater(bNode *root,int value)
{
    if(root == NULL) return true;

    if((root->data > value) && (isSubtreeGreater(root->left,value)) && (isSubtreeGreater(root->right,value)))
        return true;
    else
        return false;
}

bool isBST(bNode *root)
{
    if(root == NULL) return true;

    if(isSubtreeLesser(root->left,root->data) && isSubtreeGreater(root->right,root->data) && isBST(root->left) && isBST(root->right))
        return true;
    else
        return false;
}

bool isBST_Util(bNode *root,int minVal, int maxVal)
{
    if(root == NULL) return true;

    if((root->data > minVal) && (root->data < maxVal) && isBST_Util(root->left,minVal,root->data) 
    && isBST_Util(root->right,root->data,maxVal)) return true;

    else return false;
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

    printf("%d\n",isBST(root));
    printf("%d\n",isBST_Util(root,INT_MIN,INT_MAX));
}