#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};

struct node* start=NULL;

struct node* create_list(struct node* start)
{
    int num;
    struct node *new_node,*ptr;
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
            new_node->next=NULL;
            ptr->next=new_node;
        }
        printf("Enter the data: ");
        scanf("%d",&num);
    }
    return start;
};

struct node* delete_beg(struct node* start)
{
    struct node* ptr;
    ptr=start;
    start=start->next;
    free(ptr);
    return start;
};

struct node* delete_end(struct node* start)
{
    struct node *ptr,*preptr;
    ptr=start;
    preptr=ptr;
    while(ptr->next!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=NULL;
    free(ptr);
    return start;
};

struct node* delete_after(struct node* start)
{
    int x;
    struct node *ptr,*preptr;
    printf("Enter the value after the data to delete: ");
    scanf("%d",&x);
    ptr=start;
    preptr=ptr;
    while(preptr->data!=x)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
    return start;
};

void removeDuplicates(struct node* start)
{
    /* Pointer to traverse the linked list */
    struct node* cur=start;

    /* Pointer to store the next pointer of a node to be deleted*/
    struct node* next_next;

    /* do nothing if the list is empty */
    if (cur == NULL)
        return;

    /* Traverse the list till last node */
    while (cur->next != NULL)
    {
        /* Compare current node with next node */
        if (cur->data == cur->next->data)
        {
            /* The sequence of steps is important*/
            next_next = cur->next->next;
            free(cur->next);
            cur->next = next_next;
        }
        else /* This is tricky: only advance if no deletion */
        {
            cur = cur->next;
        }
    }
    return;
}

struct node* length(struct node* start)
{
    int count=0;
    struct node* ptr=start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    printf("%d\n",count);
};



void display(struct node* start)
{
    struct node* ptr;
    ptr=start;
    printf("The List is: ");
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
        printf("1.Create List\n");
        printf("2.Delete Beg\n");
        printf("3.Delete End\n");
        printf("4.Delete After\n");
        printf("6.Display\n");
        printf("7.Length\n");
        printf("8.Remove Duplicates\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            case 2:
                start=delete_beg(start);
                break;
            case 3:
                start=delete_end(start);
                break;
            case 4:
                start=delete_after(start);
                break;
            case 6:
                display(start);
                break;
            case 7:
                length(start);
                break;
            case 8:
                removeDuplicates(start);
                break;
        }
    }while(choice!=0);

    return 0;
}
