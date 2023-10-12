#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int size = 0;
int k = 0;

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
        ++size;

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

void InOrder(node *root, int size, int A[size])
{
    if (root == NULL)
        return;

    InOrder(root->left, size, A);
    printf("%d ", root->data);
    A[k++] = root->data;
    InOrder(root->right, size, A);
}

node *MirrorImage(node *root)
{
    if (root == NULL)
        return root;

    MirrorImage(root->left);
    MirrorImage(root->right);

    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    root1 = createTree();
    int A[size];
    size = 0;
    root2 = createTree();
    int B[size];

    if (sizeof(A) != sizeof(B))
    {
        printf("Trees cannot be mirror image as they differ in size");
        return 0;
    }

    printf("The first tree is : ");
    InOrder(root1, size, A);
    k = 0;

    // printf("\n");
    // root1 = MirrorImage(root1);
    // printf("The mirror image of root1 is : ");
    // InOrder(root1, size, A);
    // k = 0;

    printf("\n");
    printf("The second tree is : ");
    InOrder(root2, size, B);
    k = 0;
    printf("\n");

    int i = 0, j = size - 1;

    // for (int count = 0; count < size; count++)
    // {
    //     printf("%d ", A[count]);
    // }
    // printf("\n");

    // for (int count = 0; count < size; count++)
    // {
    //     printf("%d ", B[count]);
    // }
    // printf("\n");

    for (; i < size; i++, j--)
    {
        if (A[i] != B[j])
        {
            printf("\nTrees are not mirror \n");
            return 0;
        }
    }
    printf("\nTrees are mirror");
    return 0;
}