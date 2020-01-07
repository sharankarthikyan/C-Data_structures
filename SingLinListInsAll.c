#include<stdio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};

struct node* start=NULL;

struct node* create_list(struct node* start)
{
    struct node *new_node, *ptr;
    int num;
    printf("Enter -1 to EXIT\n");
    printf("Enter the data: ");
    scanf("%d",&num);
    while(num != -1)
    {
        new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        ptr=start;
        if(start==NULL)
        {
            new_node->next=start;
            start=new_node;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=NULL;

        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
}

struct node* insert_beg(struct node* start)
{
    int num;
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    new_node->data=num;
    new_node->next=start;
    start=new_node;
    return start;
}

struct node* insert_end(struct node* start)
{
    int num;
    struct node *new_node,*ptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    new_node->data=num;
    new_node->next=NULL;
    ptr=start;
    if(start==NULL)
    {
        start=new_node;
    }
    else
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=new_node;
    }
    return start;
}

struct node* insert_after(struct node* start)
{
    int num,x;
    struct node *new_node,*ptr,*preptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &num);
    printf("Enter the value after which data to be inserted: ");
    scanf("%d",&x);
    new_node->data=num;
    ptr=start;
    preptr=ptr;
    while(preptr->data!=x && preptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(preptr->data==x)
    {
        printf("Found & Inserted\n");
    }
    else
    {
        printf("Not Found & cant inserted\n");
    }
    new_node->next=ptr;
    preptr->next=new_node;
    return start;
}

struct node* insert_before(struct node* start)
{
    int num,x;
    struct node *new_node,*ptr,*preptr;
    new_node=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&num);
    printf("Enter the value before which data to be inserted: ");
    scanf("%d",&x);
    new_node->data=num;
    ptr=start;
    preptr=ptr;
    while(ptr->data!=x && ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    if(ptr->data==x)
    {
        printf("Found & Inserted\n");
    }
    else
    {
        printf("Not Found & cant inserted\n");
    }
    new_node->next=ptr;
    preptr->next=new_node;
    return start;
}

void display(struct node* start)
{
    struct node* ptr=start;
    printf("The List is: ");
    while(ptr!=NULL)
    {
        printf("%d ",ptr -> data);
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
        printf("1.Create List\n");
        printf("2.Insert Beg\n");
        printf("3.Insert End\n");
        printf("4.Insert after\n");
        printf("5.Insert before\n");
        printf("6.Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            case 2:
                start=insert_beg(start);
                break;
            case 3:
                start=insert_end(start);
                break;
            case 4:
                start=insert_after(start);
                break;
            case 5:
                start=insert_before(start);
                break;
            case 6:
                display(start);
                break;
        }
    }while(choice!=0);
}
