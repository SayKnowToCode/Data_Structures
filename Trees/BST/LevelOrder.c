// Implementing Level Order Traversal 

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct bstNode
{
    int data;
    struct bstNode *left;
    struct bstNode *right;
}bNode;

typedef struct 
{
    int front;
    int rear;
    unsigned size;
    bNode **A;
}Queue;

Queue *createQueue(unsigned size)
{
    Queue *Q = (Queue*)malloc(sizeof(Queue));
    Q->front = Q->rear = -1;
    Q->size = size;
    Q->A = (bNode **)malloc(sizeof(bNode) * Q->size);
    return Q;
}

bool isFull(Queue *Q)
{
    if(Q->rear == Q->size-1) return true;
    return false;  
}

bool isEmpty(Queue *Q)
{
    if(Q->front == -1) return true;
    return false;  
}

void Enqueue(Queue *Q,bNode *data)
{
    if(isFull(Q))
    {
        printf("Queue full");
        return;
    }
    else if(isEmpty(Q))
    {
        Q->front = Q->rear = 0;
        Q->A[(Q->rear)] = data;
        return;
    }
    Q->A[++(Q->rear)] = data;
}

void Dequeue(Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue empty");
        return;
    }
    ++(Q->front);
}

bNode *Peek(Queue *Q)
{
    return Q->A[Q->front];
}

bNode *GetNewNode(bNode *root,int data)
{
    bNode *newNode = (bNode*)malloc(sizeof(bNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bNode *Insert(bNode *root,int data)
{
    if(root == NULL) root = GetNewNode(root,data);
    else if (data <= root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right,data);
    
    return root;
}

void LevelOrder(bNode *root)
{
    if(root == NULL)
    {
        printf("Tree does not exist");
        return;
    }
    Queue *Q = createQueue(10);  
    Enqueue(Q,root);
    while (!isEmpty(Q))
    {     
        if(root->left != NULL) Enqueue(Q,root->left);
        if(root->right != NULL) Enqueue(Q,root->right);      
        printf("%d ",Peek(Q)->data);
        Dequeue(Q);   
        root = Peek(Q);   
    }
    free(Q);  
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

    LevelOrder(root);
}