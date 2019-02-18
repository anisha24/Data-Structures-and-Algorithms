#include<stdio.h>

struct Queue
{
    int front,back;
    int a[10];
};

bool isEmpty(struct Queue *s)
{
    if(s->front == -1 && s->back == -1)
        return true;
    else
        return false;    
}

bool isFull(struct Queue *s)
{
    if(s->back == 9)
        return true;
    else
        return false;    
}

int size(struct Queue *s)
{
    if(isEmpty(s))
        return 0;
    return (s->back - s->front + 1);
}

void push(struct Queue *s, int item)
{
    if(isFull(s))
        printf("Queue is full. Cannot perform push operation on a full queue.\n");
    else
    {
        if(isEmpty(s))
        {
            s->a[++(s->back)] = item;
            s->front = 0;
        }
        else
            s->a[++(s->back)] = item;    
    }  
}

int pop(struct Queue *s)
{
    if(isEmpty(s))
    {
        printf("Queue is empty. Cannot perform pop operation on an empty queue.\n");
        return -1000;
    }
    else
    {
        int retval =  s->a[s->front++];
        if(s->front> s->back)
            s->front = s->back = -1;
        return retval; 
    } 
}

void display(struct Queue *s)
{
    int i, t = size(s);
    if(isEmpty(s))
        printf("Empty queue\n");
    else
    {
        printf("The elements in the queue are:\n");
        for(int i= s->front;i<=s->back;i++)
        {
            if(i == s->front)
                printf("| %d | <- front\n",s->a[i]);
            else if(i == s->back)
                printf("| %d | <- back\n",s->a[i]);
            else
                printf("| %d |\n",s->a[i]);
        }
    }
}

int front(struct Queue *s)
{
    if(isEmpty(s))
    {
        printf("Queue is empty. There is no element at the front of the empty queue.\n");
        return -1000;
    }
    else
    {
        return s->a[s->front];
    }
}

int main()
{
    struct Queue s;
    s.front = s.back = -1;
    int ch,ele,pele,tele,siz;
    while(true)
    {
        printf("\n\n\n1.Push an element to the queue\n2.Pop an element fron the queue\n3.Display the front element of the queue\n4.Display the elements of the queue\n5.Display the size of the queue\n6.Exit\n");
        scanf("%d",&ch);
        if(ch == 1)
        {
            printf("Enter element to be pushed into the queue\n");
            scanf("%d",&ele);
            push(&s,ele);
        }
        else if(ch == 2)
        {
            pele = pop(&s);
            if(pele == -1000)
                continue;
            else
                printf("The popped element from the queue is : %d\n",pele);
        }
        else if(ch == 3)
        {
            tele = front(&s);
            if(tele == -1000)
                continue;
            else
                printf("The front element of the queue is : %d\n",tele);
        }
        else if(ch == 4)
            display(&s);
        else if(ch == 5)
        {
            siz = size(&s);
            if(siz == 0)
                printf("Empty queue\n");
            else
                printf("The size of the queue is : %d\n",siz);
        }
        else if(ch == 6)
            break;
    }
    return 0;
}
