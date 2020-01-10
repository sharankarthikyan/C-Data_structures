#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* top=NULL;

struct node* push(struct node* top)
{
    int val;
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to push: ");
    scanf("%d",&val);
    new_node->data=val;
    if(top==NULL)
    {
        new_node->next=top;
        top=new_node;
    }
    else
    {
        new_node->next=top;
        top=new_node;
    }
    return top;
};

struct node* pop(struct node* top)
{
    struct node* ptr=top;
    if(top==NULL)
    {
        printf("Stack overflow\n");
    }
    else
    {
        top=top->next;
        printf("The value being deleted is %d\n",ptr->data);
        free(ptr);
    }
    return top;
};

struct node* peek(struct node* top)
{
    if(top==NULL)
    {
        printf("Stack Empty");
    }
    else
    {
        printf("The element in the top is %d\n",top->data);
    }
    return top;
};

void display(struct node* top)
{
    struct node* ptr=top;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}


int main()
{
    int choice;
    do
    {
        printf("0.EXIT\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("Enter Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top=push(top);
                break;
            case 2:
                top=pop(top);
                break;
            case 3:
                top=peek(top);
                break;
            case 4:
                display(top);
                break;
        }
    }while(choice!=0);
    return 0;
}
