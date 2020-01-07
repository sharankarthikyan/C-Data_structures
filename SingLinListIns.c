/* //Insert at the beginning
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void insert(int x)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    head=temp;
}

void print()
{
    struct node* temp=head;
    printf("The List is: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    head=NULL;
    printf("Enter length of List: ");
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element: ");
        scanf("%d",&x);
        insert(x);
        print();
    }
    return 0;
} */



#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};


void push(struct node** head_ref,int new_data)
{
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void print(struct node* head_ref)
{
    struct node* temp=head_ref;
    printf("The List is: ");
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
}

int main()
{
    struct node* head=NULL;
    int n,i;
    printf("Enter the length of List: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x;
        printf("Enter Element: ");
        scanf("%d",&x);
        push(&head,x);
        print(head);
        printf("\n");
    }
    return 0;
}
