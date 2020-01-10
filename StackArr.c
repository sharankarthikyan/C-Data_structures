#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int st[MAX],top=-1;

void push(int st[],int val)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        st[top]=val;
    }
}

void pop(int st[])
{
    if(top==-1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("The Popped element is %d\n",st[top]);
        top--;
    }

}

void peek(int st[])
{
    if(top==-1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("%d\n",st[top]);
    }
}

void display(int st[])
{
    int i;
    if(top==-1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("Element in stack: ");
        for(i=top;i>=0;i--)
        {
            printf("%d ",st[i]);
        }
        printf("\n");
    }
}

int main()
{
   int choice,val;
   do
   {
       printf("0.EXIT\n");
       printf("1.Push\n");
       printf("2.Pop\n");
       printf("3.Peek\n");
       printf("4.Display\n");
       printf("Enter the Choice: ");
       scanf("%d",&choice);
       switch(choice)
       {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d",&val);
                push(st,val);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                peek(st);
                break;
            case 4:
                display(st);
                break;

       }
   }while(choice!=0);
   return 0;
}
