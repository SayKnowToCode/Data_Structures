#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct bstNode
{
    char data;
    struct bstNode *left;
    struct bstNode *right;
} Node;

typedef struct
{
    int top;
    unsigned size;
    Node **A;
} Stack;

Node *GetNewNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}

bool isOperand(char ch)
{
    if (ch >= '1' && ch <= '9')
        return true;
    return false;
}

int performCalc(int op1, char oprt, int op2)
{
    switch (oprt)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        return op1 / op2;
    }
    return 0;
}

Stack *createStack(unsigned size)
{
    Stack *S = (Stack *)malloc(sizeof(Stack));
    S->top = -1;
    S->size = size;
    S->A = (Node **)malloc(S->size * sizeof(Node *));
    return S;
}

bool isEmpty(Stack *S)
{
    if (S->top == -1)
        return true;
    return false;
}

bool isFull(Stack *S)
{
    if (S->top == (S->size) - 1)
        return true;
    return false;
}

void Push(Stack *S, Node *data)
{
    if (isFull(S))
    {
        printf("Error : Stack Overflow");
        return;
        // S->size = S->size * 2;
        // S->A = (int *)realloc(S->A, (S->size)*sizeof(int));
    }
    S->A[++(S->top)] = data;
}

void Pop(Stack *S)
{
    if (isEmpty(S))
    {
        printf("Error : Stack Underflow");
        return;
    }
    --(S->top);
}

Node *Top(Stack *S)
{
    return S->A[S->top];
}

typedef struct
{
    int top;
    unsigned size;
    int *A;
} intStack;

intStack *createintStack(unsigned size)
{
    intStack *S = (intStack *)malloc(sizeof(intStack));
    S->top = -1;
    S->A = (int *)malloc(size * sizeof(int));
    return S;
}

bool isIntFull(intStack *S)
{
    if (S->top == S->size - 1)
        return true;
    return false;
}

bool isIntEmpty(intStack *S)
{
    if (S->top == -1)
        return true;
    return false;
}

void intPush(intStack *S, int data)
{
    if (isIntFull(S))
    {
        printf("intStack Overflow !!");
        return;

        // S->size = S->size * 2;
        // S->A = (int *)realloc(S->A, S->size * sizeof(int));
    }
    S->A[++(S->top)] = data;
}

void intPop(intStack *S)
{
    if (isIntEmpty(S))
    {
        printf("intStack Underflow !!");
        return;
    }
    --(S->top);
}

int intTop(intStack *S)
{
    return S->A[S->top];
}

int Evaluate(char *str)
{
    printf("\nEnter size of intstack you desire : ");
    unsigned size;
    scanf("%u", &size);
    intStack *S = createintStack(size);

    int i = 0;
    while (i != '\n')
    {
        i++;
    }

    while (i >= 0)
    {
        if (isOperand(str[i]))
        {
            intPush(S, (int)(str[i] - '0'));
            i--;
        }

        else if (isOperator(str[i]))
        {
            int op1 = intTop(S);
            intPop(S);
            int op2 = intTop(S);
            intPop(S);
            intPush(S, performCalc(op1, str[i], op2));
            i--;
        }

        else
            i--;
    }

    int k = intTop(S);
    intPop(S);
    free(S);
    return k;
}

Node *Prefix(char *str)
{
    int i = 0;
    while (i != '\n')
    {
        i++;
    }
    Stack *S = createStack(i);

    while (i >= 0)
    {
        if (isOperator(str[i]))
        {
            Node *root2 = GetNewNode(str[i]);
            root2->left = Top(S);
            Pop(S);
            root2->right = Top(S);
            Pop(S);
            Push(S, root2);
        }
        else
        {
            Node *root1 = GetNewNode(str[i]);
            Push(S, root1);
        }
        i--;
    }
    return Top(S);
}

void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    printf("%c ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    printf("%c ", root->data);
    InOrder(root->right);
}

int main()
{
    printf("Enter prefix expression : ");
    char *str = NULL;
    size_t size = 0;
    getline(&str, &size, stdin);

    Node *root = Prefix(str);
    PreOrder(root);
    printf("\n");
    InOrder(root);
    printf("The evaluation is : %d", Evaluate(str));

    return 0;
}