#include <stdio.h>
#include <stdlib.h>
struct node
{
int coeff;
int power;
struct node* next;
};
struct node*insert(struct node* head,int coeff,int power)
{
struct node* temp;
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->coeff = coeff;
newnode->power = power;
newnode->next = NULL;
if (head == NULL || power > head->power)
{

newnode->next = head;
head = newnode;
}
else
{
temp = head;
while (temp->next != NULL && temp->next->power<power)
{
temp = temp->next;
}
newnode->next = temp->next;
temp->next = newnode;
}
return head;
}
struct node* create(struct node*head)
{
int i, power;
int coeff;
printf("Enter the maxiumum power of the polynomial: ");
scanf("%d",&power);
for (i = power; i >= 0; i--)
{
printf("Enter the coefficient for power x^%d: ", i);
scanf("%d",&coeff);
if (coeff != 0)

{
head=insert(head, coeff, i);
}
}
return head;
}
void print(struct node* head)
{
if (head == NULL)
{
printf("No Polynomial.");
}
else
{
struct node* temp = head;
while (temp != NULL)
{
printf(" (%dx^%d)", temp->coeff, temp->power);
temp = temp->next;
if (temp != NULL)
{
printf("+");
} else
{
printf("\n");
}

}
}
}
void polyMult(struct node* head1, struct node* head2)
{
struct node* ptr1 = head1;
struct node* ptr2 = head2;
struct node* head3 = NULL;
if (head1 == NULL || head2 == NULL)
{
printf("Zero polynomial\n");
return;
}
while (ptr1 != NULL)
{
while (ptr2 != NULL)
{
head3 = insert(head3, ptr1->coeff * ptr2->coeff, ptr1->power + ptr2->power);
ptr2 = ptr2->next;
}
ptr1 = ptr1->next;
ptr2 = head2;
}
print(head3);
}
int main() {

struct node* head1 = NULL;
struct node* head2 = NULL;
printf("Enter the first polynomial:\n");
head1 = create(head1);
printf("Enter the second polynomial:\n");
head2 = create(head2);
printf("Result of polynomial mulOplicaOon:\n");
polyMult(head1, head2);
return 0;
}
