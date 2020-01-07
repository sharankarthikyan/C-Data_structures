//Insert at the END
/*#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;

void push(int new_data)
{
    struct node* temp=head;
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=NULL;
    if(head==NULL)
    {
        head=new_node;
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    return;
}


void print()
{
    struct node* temp=head;
    printf("The element in list: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int n,i;
    printf("Enter the length of the List: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x;
        printf("Enter the element: ");
        scanf("%d",&x);
        push(x);
        print();
    }

    return 0;
}
*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void push(struct node** head_ref,int new_data)
{
    struct node* temp=(*head_ref);
    struct node* new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=NULL;
    if((*head_ref)==NULL)
    {
        (*head_ref)=new_node;
        return;
    }

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    return;
}


void print(struct node* head_ref)
{
    struct node* temp=head_ref;
    printf("The element in list: ");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    struct node* head=NULL;
    int n,i;
    printf("Enter the length of the List: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int x;
        printf("Enter the element: ");
        scanf("%d",&x);
        push(&head,x);
        print(head);
    }

    return 0;
}
