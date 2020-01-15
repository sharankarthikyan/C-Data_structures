#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
    int data;
    struct node* next;
};
struct queue
{
    struct node* front;
    struct node* rear;
};
struct queue *q;
struct queue* createqueue()
{
    struct queue* a = (struct Queue*)malloc(sizeof(struct queue));
    a->front=NULL;
    a->rear=NULL;
    return a;
}

struct queue* insert(struct queue* q)
{
    int num;
    struct node* ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    ptr->data=num;
    if(q->front==NULL)
    {
        q->front=ptr;
        q->rear=ptr;
        q->front->next=q->rear->next=NULL;
    }
    else
    {
        q->rear->next=ptr;
        q->rear=ptr;
        q->rear->next=NULL;
    }
    return q;
}

struct queue* deleteVal(struct queue* q)
{
    struct node* ptr;
    ptr=q->front;
    if(q->front==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("The deleted element is %d\n",q->front->data);
        q->front=q->front->next;
        free(ptr);
    }
    return q;
}

void peek(struct queue* q)
{
    if(q->front==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("the element in the front is %d\n",q->front->data);
    }
}

void display(struct queue* q)
{
    struct node* ptr=q->front;
    printf("The Queue is: ");
    if(ptr==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

int main()
{
    int choice;
    q=createqueue();
    printf("%d\n",q->rear);
    do
    {
        printf("0. EXIT\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                q=insert(q);
                break;
            case 2:
                q=deleteVal(q);
                break;
            case 3:
                peek(q);
                break;
            case 4:
                display(q);
                break;
        }
    }while(choice!=0);
    return 0;
}

