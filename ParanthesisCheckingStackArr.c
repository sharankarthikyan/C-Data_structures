#include <stdio.h>
#include <string.h>
#define MAX 10
int st[MAX],top=-1;

void push(char a)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        st[top]=a;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("Stack Empty\n");
    }
    else
    {
        char temp=st[top];
        top--;
        return temp;
    }
}

int main()
{
    int i,flag=1;
    char exp[MAX],temp;
    printf("Enter the expression: ");
    gets(exp);
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(exp[i]);
        }
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
        {
            if(top==-1)
            {
                flag=0;
            }
            else
            {
                temp=pop();
                if(exp[i]==')' && (temp=='{' || temp=='['))
                    flag=0;
                if(exp[i]=='}' && (temp=='(' || temp=='['))
                    flag=0;
                if(exp[i]==']' && (temp=='(' || temp=='{'))
                    flag=0;
            }
        }
    }
    if(flag)
    {
        printf("Valid Expression\n");
    }
    else
    {
        printf("Invalid Expression\n");
    }
    return 0;
}
