#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *left, *right;
} node;

node *createTree()
{
    int choice;
    printf("\nIf you entered function by mistake, Press 0 to exit for which the return type is Null");
    printf("\nPress 1 to continue");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        return NULL;
    }

    else
    {
        node *temp = (node *)malloc(sizeof(node));
        int data1, data2;
        printf("\nEnter the data:");
        scanf("%d", &data1);
        temp->data = data1;

        printf("\nIs there a left child for Node with value %d ?? (Press 1 for Yes and 0 for No) : ", data1);
        scanf("%d", &data2);
        if (data2 == 0)
            temp->left = NULL;
        else
            temp->left = createTree();

        printf("\nIs there a right child for Node with value %d ?? (Press 1 for Yes and 0 for No) : ", data1);
        scanf("%d", &data2);
        if (data2 == 0)
            temp->right = NULL;
        else
            temp->right = createTree();

        return temp;
    }
}

void InOrder(node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void MirrorImage(node *root)
{
    if (root == NULL)
        return;

    MirrorImage(root->left);
    MirrorImage(root->right);

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

bool areIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;

    return ((root1->data == root2->data) && (areIdentical(root1->left, root2->left)) && (areIdentical(root1->right, root2->right)));
}

int main()
{
    node *root1 = createTree();
    node *root2 = createTree();
    InOrder(root1);
    printf("\n");
    InOrder(root2);
    printf("\n");
    MirrorImage(root1);
    MirrorImage(root2);
    InOrder(root1);
    printf("\n");
    InOrder(root2);
    printf("\n");
    MirrorImage(root1);
    MirrorImage(root2);
    printf("\n");
    printf("%d", areIdentical(root1, root2));
    return 0;
}