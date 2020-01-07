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
    struct node *ptr;
    printf("Enter -1 to EXIT\n");
    printf("Enter the data: ");
    scanf("%d",&num);
    while(num!=-1)
    {
        struct node* new_node=(struct node*)malloc(sizeof(struct node));
        new_node->data=num;
        if(start==NULL)
        {
            new_node->next=new_node;
            start=new_node;
        }
        else
        {
            ptr=start;
            while(ptr->next!=start)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            new_node->next=start;
        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
};

void display(struct node* start)
{
    struct node* ptr;
    ptr=start;
    printf("The List is: ");
    while(ptr->next!=start)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",ptr->data);
    return;
}

int main()
{
    int choice;
    do{
        printf("0.EXIT\n");
        printf("1.Create List\n");
        printf("2.Insert Beg\n");
        printf("3.Insert End\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            /*case 2:
                start=insert_beg(start);
                break;
            case 3:
                start=insert_end(start);
                break;*/
            case 4:
                display(start);
                break;
        }
    }while(choice!=0);


    return 0;
}
