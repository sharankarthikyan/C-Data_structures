#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* start=NULL;

struct node* create_list(struct node* start)
{
    int num;
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    struct node* ptr=start;
    printf("Enter -1 to EXIT\n");
    printf("Enter the data: ");
    scanf("%d",&num);
    while(num!=-1)
    {
        ptr=start;
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }
        else
        {
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            new_node->next=start;
            ptr->next=new_node;
        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
};

void checking(struct node* start)
{
    struct node *slow_ptr,*fast_ptr;
    slow_ptr=start;
    fast_ptr=start;
    while(slow_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr=slow_ptr->next;
        fast_ptr=fast_ptr->next->next;
        if(slow_ptr==fast_ptr)
        {
            printf("Loop\n");
            return;
        }
    }

}

int main()
{
    int choice;
    printf("Now we just create a circular Linked List to make a loop:\n");
    do
    {
        printf("0.EXIT\n");
        printf("1. Create List\n");
        printf("2. Check for Loop\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            case 2:
                checking(start);
                break;
        }
    }while(choice!=0);
    return 0;
}
