#include<stdio.h>
#include<stdlib.h>
struct node{
    int coef;
    int power;
    struct node *next;
};
struct node *p1=NULL;
struct node *p2=NULL;
struct node *result=NULL;
struct node *create(int coef,int power,struct node *head){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*temp;
    newnode->coef=coef;
    newnode->power=power;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=head;
    }
    else
    {
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}
void sum(struct node *ptr1,struct node *ptr2)
{
    while(ptr1!=NULL&&ptr2!=NULL)
    {
        if(ptr1->power>ptr2->power)
        {
            result=create(ptr1->coef,ptr1->power,result);
            ptr1=ptr1->next;
        }
        else if(ptr1->power<ptr2->power)
        {
            result=create(ptr2->coef,ptr2->power,result);
            ptr2=ptr2->next;
        }
        else if(ptr1->power==ptr2->power,result){
            result=create(ptr1->coef+ptr2->coef,ptr1->power,result);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL)
    {
        result=create(ptr1->coef,ptr1->power,result);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL)
    {
        result=create(ptr2->coef,ptr2->power,result);
        ptr2=ptr2->next;
    }
}
void display()
{
    struct node *temp;
    temp=result;
    while(temp!=NULL)
    {
        printf("%dX^%d",temp->coef,temp->power);
        if(temp->next!=NULL)
        printf(" + ");
        temp=temp->next;
    }
}
int main()
{
    int power,val,power1;
    printf("Enter the maximum power of polynomial 1: ");
    scanf("%d",&power);
    for(int i=0;i<=power;i++)
    {
        printf("The coefficient of X^%d: ",power-i);
        scanf("%d",&val);
        if(val!=0)
        {
        p1=create(val,power-i,p1);
        }
    }
    printf("Enter the maximum power of polynomial 2: ");
    scanf("%d",&power1);
    for(int i=0;i<=power1;i++)
    {
        printf("The coefficient of X^%d: ",power1-i);
        scanf("%d",&val);
        if(val!=0)
        {
        p2=create(val,power1-i,p2);
        }
    }
    sum(p1,p2);
    printf("The resultant polynomial is: ");
    display();
}
