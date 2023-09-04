// Delete a node from BST
// If leaf node - Delete directly
// If node has only one child adjust link of previous to next
// For 2 children, Max in Left Subtree or Min in Right Subtree

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
    if(root == NULL) root = GetNewNode(data);
    else if(data <= root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right,data);
    
    return root;
}

int Min(bNode *root)
{
    if(root==NULL) return -1;
    else if(root->left == NULL) return root->data;
    else { return Min(root->left); }    
}

int MaxHeight(int a,int b)
{
    if(a>b) return a;
    else if (b>a) return b;
    else return a;   
}

int FindHeight(bNode *root)
{
    if(root == NULL)
        return -1;
    
    return (MaxHeight(FindHeight(root->left),FindHeight(root->right))+1);
}

bool Search(bNode *root, int data)
{
    if(root==NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) {return Search(root->left,data);}
    else {return Search(root->right,data);}    
}

int typeNode(bNode *root)
{
    if(root->left == NULL && root->right == NULL)
        return 1;
    else if (root->left == NULL || root->right == NULL)
        return 2;
    else if(root->left != NULL && root->right != NULL)
        return 3;   
}

bNode *Delete_Util(bNode *root,int data)
{
    if(root == NULL) return root;
    else if(data < root->data) root->left = Delete_Util(root->left,data);
    else if(data > root->data) root->right = Delete_Util(root->right,data);

    else
    {
        switch (typeNode(root))
        {
            case 1:
            {
                free(root);
                return NULL;
            }

            case 2:
            {
                bNode *temp;
                if(root->left != NULL)
                {
                    temp = root->left;
                    free(root);
                    return temp;
                }
                else
                {
                    temp = root->right;
                    free(root);
                    return temp;
                }
            }

            case 3:
            {
                int c = Min(root->right);
                root->data = c;
                root->right = Delete_Util(root->right,c);
                return root;
            }
        }
    }
    return root;
}

bNode *Delete(bNode *root, int data)
{
    if(root == NULL) 
    {
        printf("Tree doesnt exist");
        return root;
    }

    if(Search(root,data) == false) 
    {
        printf("Element is not a part of tree");
        return root;
    }

    root = Delete_Util(root,data);
    return root;
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
    printf("%d\n",FindHeight(root));
    root = Delete(root,10);
    printf("%d\n",FindHeight(root));
    root = Delete(root,14);
    printf("%d\n",FindHeight(root));
    return;
}