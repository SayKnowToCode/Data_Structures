#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct node
{
    char c;
    struct node *lchild;
    struct node *rchild;
};
struct stack
{
    struct node *tree;
    struct stack *nxt;
};
struct int_stack
{
    int data;
    struct int_stack *next;
};
void pushh(struct int_stack **t, int data)
{
    struct int_stack *q = (struct int_stack *)malloc(sizeof(struct int_stack));
    q->data = data;
    q->next = *t;
    *t = q;
}
int popp(struct int_stack **t)
{
    if (*t != NULL)
    {
        int temp = (*t)->data;
        *t = (*t)->next;
        return temp;
    }
    return 0;
}
void push(struct stack **t, struct node *p)
{
    struct stack *q = (struct stack *)malloc(sizeof(struct stack));
    q->tree = p;
    q->nxt = *t;
    *t = q;
}
struct node *pop(struct stack **t)
{
    if (*t != NULL)
    {
        struct node *p = (*t)->tree;
        struct stack *temp = *t;
        *t = (*t)->nxt;
        free(temp);
        return p;
    }
    return NULL;
}
void inorder(struct node *t)
{
    if (t != NULL)
    {
        inorder(t->lchild);
        printf("%c ", t->c);
        inorder(t->rchild);
    }
}
int isInt(char data)
{
    return isdigit(data);
}
int val(char data)
{
    return data - '0';
}
int main()
{
    printf("Enter an Expression: \n");
    char str[30];
    scanf("%s", str);
    int ind = strlen(str);
    char temp[30];
    strcpy(temp, str);
    ind--;
    struct stack *st = NULL;
    struct node *p;
    while (ind != -1)
    {
        p = (struct node *)malloc(sizeof(struct node));
        if (str[ind] == '+' || str[ind] == '-' || str[ind] == '*' || str[ind] == '/')
        {
            p->c = str[ind];
            p->lchild = pop(&st);
            p->rchild = pop(&st);
            push(&st, p);
        }
        else
        {
            p->c = str[ind];
            p->lchild = p->rchild = NULL;
            push(&st, p);
        }
        ind--;
    }
    struct node *root = pop(&st);
    inorder(root);
    ind = strlen(temp);
    ind--;
    struct int_stack *s = NULL;
    int a, b;
    while (ind != -1)
    {
        if (isInt(temp[ind]) == 1)
        {
            pushh(&s, val(temp[ind]));
        }
        else if (temp[ind] == '+' || temp[ind] == '-' || temp[ind] == '*' ||
                 temp[ind] == '/')
        {
            a = popp(&s);
            b = popp(&s);
            switch (temp[ind])
            {
            case '+':
                a = a + b;
                break;
            case '-':
                a = b - a;
                break;
            case '*':
                a = a * b;
                break;
            case '/':
                a = a / b;
                break;
            }
            pushh(&s, a);
        }
        ind--;
    }
    printf("\n ans : %d ", popp(&s));
    return 0;
}
