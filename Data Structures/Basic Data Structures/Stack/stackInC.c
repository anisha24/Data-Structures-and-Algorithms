#include<stdio.h>

struct Stack 
{
    int top;
    int a[10];
};

bool isEmpty(struct Stack *s)
{
    if(s->top == -1)
        return true;
    else
        return false;    
}

bool isFull(struct Stack *s)
{
    if(s->top == 9)
        return true;
    else
        return false;    
}

int size(struct Stack *s)
{
    return (s->top+1);
}

void push(struct Stack *s, int item)
{
    if(isFull(s))
        printf("Stack is full. Cannot perform push operation on a full stack.\n");
    else
        s->a[++(s->top)] = item;
}

int pop(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty. Cannot perform pop operation on an empty stack.\n");
        return -1000;
    }
    else
        return s->a[s->top--];
}

void display(struct Stack *s)
{
    int i, t = size(s);
    if(isEmpty(s))
        printf("Empty stack\n");
    else
    {
        printf("The elements in the stack are:\n");
        for(int i= t-1;i>=0;i--)
        {
            if(i == (t-1))
                printf("| %d | <- top\n",s->a[i]);
            else
                printf("| %d |\n",s->a[i]);
        }
        printf("------\n");
    }
    
}

int top(struct Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty. There is no element at the top of the empty stack.\n");
        return -1000;
    }
    else
    {
        return s->a[s->top];
    }
}

int main()
{
    struct Stack s;
    s.top = -1;
    int ch,ele,pele,tele,siz;
    while(true)
    {
        printf("\n\n\n1.Push an element to the stack\n2.Pop an element fron the stack\n3.Display the top element of the stack\n4.Display the elements of the stack\n5.Display the size of the stack\n6.Exit\n");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Enter element to be pushed into the stack\n");
            scanf("%d",&ele);
            push(&s,ele);
        }
        else if(ch == 2)
        {
            pele = pop(&s);
            if(pele == -1000)
                continue;
            else
                printf("The popped element from the stack is : %d\n",pele);
        }
        else if(ch == 3)
        {
            tele = top(&s);
            if(tele == -1000)
                continue;
            else
                printf("The top element of the stack is : %d\n",tele);
        }
        else if(ch == 4)
            display(&s);
        else if(ch == 5)
        {
            siz = size(&s);
            if(siz == 0)
                printf("Empty stack\n");
            else
                printf("The size of the stack is : %d\n",siz);
        }
        else if(ch == 6)
            break;
    }
    return 0;
}
