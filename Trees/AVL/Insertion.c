// Code to handle all cases

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
    int balance;
} bNode;

char str[3];
int k = 0;
bNode *temp = NULL;

bNode *GetNewNode(int data)
{
    bNode *newNode = (bNode *)malloc(sizeof(bNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->balance = 0;
    return newNode;
}

int Max(int a, int b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else
        return a;
}

int FindHeight(bNode *root)
{
    if (root == NULL)
        return -1;

    return (Max(FindHeight(root->left), FindHeight(root->right)) + 1);
}

void fillString(bNode *root)
{
    if (root->balance > 1 || root->balance < -1)
    {
        if (root->left != NULL)
        {
            if (root->left->balance == 1)
            {
                str[0] = 'L';
                str[1] = 'L';
            }

            else if (root->left->balance == -1)
            {
                str[0] = 'L';
                str[1] = 'R';
            }
        }

        if (root->right != NULL)
        {
            if (root->right->balance == -1)
            {
                str[0] = 'R';
                str[1] = 'R';
            }

            else if (root->right->balance == 1)
            {
                str[0] = 'R';
                str[1] = 'L';
            }
        }
    }
}

bNode *Insert(bNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        str[2] = '\0';
    }

    else if (data == root->data)
        printf("No duplicates allowed");

    else if (data < root->data)
    {
        // if (k >= 2)
        // {
        //     str[0] = str[1];
        //     str[1] = 'L';
        //     k++;
        // }
        // else
        // {
        //     str[(k++) % 2] = 'L';
        // }

        root->left = Insert(root->left, data);
    }

    else
    {
        // if (k >= 2)
        // {
        //     str[0] = str[1];
        //     str[1] = 'R';
        // }
        // else
        // {
        //     str[(k++) % 2] = 'R';
        // }

        root->right = Insert(root->right, data);
    }

    root->balance = FindHeight(root->left) - FindHeight(root->right);
    fillString(root);
    return root;
}

bNode *InsertUtil(bNode *root, int data)
{
    k = 0;
    root = Insert(root, data);
}

void PreOrder(bNode *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(bNode *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

bNode *CheckImbalance(bNode *root, int value)
{
    if (root == NULL)
        return NULL;

    if ((root->balance == 0) || (root->balance == -1) || (root->balance == 1))
    {
        if (value < root->data)
        {
            root = CheckImbalance(root->left, value);
            if (root != NULL)
                return root;
            else
                return NULL;
        }

        else
        {
            root = CheckImbalance(root->right, value);
            if (root != NULL)
                return root;
            else
                return NULL;
        }
    }

    else
    {
        bNode *imbalance = NULL;
        while (root->balance > 1 || root->balance < -1)
        {
            if (value < root->data)
            {
                imbalance = root;
                root = root->left;
            }
            else
            {
                imbalance = root;
                root = root->right;
            }
        }
        return imbalance;
    }
}

int Decision()
{
    if (str[0] == 'L' && str[1] == 'L')
        return 1;

    else if (str[0] == 'R' && str[1] == 'R')
        return 2;

    else if (str[0] == 'L' && str[1] == 'R')
        return 3;

    else if (str[0] == 'R' && str[1] == 'L')
        return 4;
}

bNode *RotateLL(bNode *root, int value)
{
    if (root == temp)
    {
        bNode *tp = root;
        root = root->left;
        tp->left = root->right;
        root->right = tp;
    }

    else
    {
        if (value < root->data)
            root->left = RotateLL(root->left, value);
        else
            root->right = RotateLL(root->right, value);
    }
    root->balance = FindHeight(root->left) - FindHeight(root->right);
    return root;
}

bNode *RotateRR(bNode *root, int value)
{
    if (root == temp)
    {
        bNode *tp = root;
        root = root->right;
        tp->right = root->left;
        root->left = tp;
    }

    else
    {
        if (value < root->data)
            root->left = RotateRR(root->left, value);
        else
            root->right = RotateRR(root->right, value);
    }
    root->balance = FindHeight(root->left) - FindHeight(root->right);
    return root;
}

bNode *RotateLR(bNode *root, int value)
{
    if (root == temp)
    {
        bNode *tp = root;
        bNode *tp1 = root->left->right;
        bNode *tp2 = root->left;
        tp->left = tp1->right;
        tp2->right = tp1->left;
        tp1->left = tp2;
        tp1->right = tp;
        root = tp1;
    }

    else
    {
        if (value < root->data)
            root->left = RotateLR(root->left, value);
        else
            root->right = RotateLR(root->right, value);
    }
    root->balance = FindHeight(root->left) - FindHeight(root->right);
    return root;
}

bNode *RotateRL(bNode *root, int value)
{
    if (root == temp)
    {
        bNode *tp = root;
        bNode *tp1 = root->right->left;
        bNode *tp2 = root->right;
        tp->right = tp1->left;
        tp2->left = tp1->right;
        tp1->left = tp;
        tp1->right = tp2;
        root = tp1;
    }

    else
    {
        if (value < root->data)
            root->left = RotateRL(root->left, value);
        else
            root->right = RotateRL(root->right, value);
    }
    root->balance = FindHeight(root->left) - FindHeight(root->right);
    return root;
}

void findBalance(bNode *root)
{
    if (root == NULL)
        return;

    root->balance = FindHeight(root->left) - FindHeight(root->right);
    findBalance(root->left);
    findBalance(root->right);
}

int main()
{
    bNode *root = NULL;
    while (true)
    {
        printf("\nPress -1 to Exit OR Enter data (+ve integers only) : ");
        int value;
        scanf("%d", &value);

        if (value == -1)
        {
            break;
        }

        root = InsertUtil(root, value);
        printf("Insertion completed\n");
        int flag = 0;
        while (true)
        {
            findBalance(root);
            temp = CheckImbalance(root, value);
            if (temp != NULL)
            {
                printf("%d %d \n", temp->data, temp->balance);
                printf("%s\n", str);
                fillString(temp);
            }

            if (temp == NULL)
            {
                if (flag == 0)
                {
                    printf("\nNo imbalance generated");
                    printf("\n");
                    PreOrder(root);
                    printf("\n");
                    InOrder(root);
                    printf("\n");
                }
                break;
            }

            else
            {
                switch (Decision())
                {
                case 1: // LL Rotation
                {
                    root = RotateLL(root, value);
                    printf("LL Rotation");
                    break;
                }
                case 2: // RR Rotation
                {
                    root = RotateRR(root, value);
                    printf("RR Rotation");
                    break;
                }
                case 3: // LR Rotation
                {
                    root = RotateLR(root, value);
                    printf("LR Rotation");
                    break;
                }
                case 4: // RL Rotation
                {
                    root = RotateRL(root, value);
                    printf("RL Rotation");
                    break;
                }
                }
                printf("\n");
                PreOrder(root);
                printf("\n");
                InOrder(root);
                printf("\n");
                flag++;
            }
        }
    }
    return 0;
}
