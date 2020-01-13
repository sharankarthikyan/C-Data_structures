#include <stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;

void insert(int queue[])
{
    int num;
    printf("Enter -1 to EXIT\n");
    printf("Enter Data: ");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(rear==MAX-1)
        {
            printf("Overflow\n");
        }
        else if(front == -1 && rear == -1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        queue[rear]=num;
        printf("Enter Data: ");
        scanf("%d",&num);
    }
}

void deleteVal(int queue[])
{
    if(front==-1 || front>rear)
    {
        printf("Empty\n");
    }
    else
    {
        printf("The element deleted is %d\n",queue[front]);
        front++;
        if(front>rear)
            front=rear=-1;
    }
}

void peek(int queue[])
{
    if(front==-1 && front>rear)
    {
        printf("Empty\n");
    }
    else
    {
        printf("The first element in queue is %d\n",queue[front]);
    }
}

void display(int queue[])
{
    int i;
    if(front==-1 || front>rear)
    {
        printf("Empty\n");
    }
    else
    {
        printf("The Queue is: ");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }

}

int main()
{
    int choice;
    do
    {
        printf("0. EXIT\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("Enter your Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert(queue);
                break;
            case 2:
                deleteVal(queue);
                break;
            case 3:
                peek(queue);
                break;
            case 4:
                display(queue);
                break;
        }
    }while(choice!=0);
    return 0;
}
