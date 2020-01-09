#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev,*next;
};

struct node* start=NULL;

struct node* create_list(struct node* start)
{
    int num;
    printf("Enter -1 to EXIT\n");
    printf("Enter the data: ");
    scanf("%d",&num);
    while(num!=-1)
    {
        if(start==NULL)
        {
            struct node* new_node=(struct node*)malloc(sizeof(struct node));
            new_node->next=start;
            new_node->data=num;
            new_node->prev=start;
            start=new_node;
        }
        else
        {
            struct node* new_node=(struct node*)malloc(sizeof(struct node));
            struct node* ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;
            new_node->prev=ptr;
            new_node->data=num;
        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
};

struct node* delete_beg(struct node* start)
{
    struct node *ptr;
    ptr=start;
    start=start->next;
    start->prev=NULL;
    free(ptr);
    return start;
};

void display(struct node* start)
{
    struct node* ptr=start;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
}

int main()
{
    int choice;
    printf("0. EXIT\n");
    printf("1. Create List\n");
    printf("2. Insert Beg\n");
    printf("3. Insert End\n");
    printf("4. Display\n");
    printf("Enter your Choice: ");
    scanf("%d",&choice);
    do
    {
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            case 2:
                start=delete_beg(start);
                break;
            /*case 3:
                start=insert_end(start);
                break;*/
            case 4:
                display(start);
                break;
        }
        printf("Enter your Choice: ");
        scanf("%d",&choice);
    }while(choice!=0);

    return 0;
}
