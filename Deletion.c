//LinkedList
/* In this repositry we will know about the Deletion of nodes in Linked List.
Case 1. Delete Head
Case 2. Delete at index
Case 3. Delete at end
Case 4. DeleteNode.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* Insert(struct node* head, int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head=newnode;
		return head;
	}
	
	struct node* current = head;
	
	while(current->next!=NULL)
	{
		current=current->next;
	}
	current->next=newnode;
	return head;
}

struct node* DeleteHead(struct node* head)
{
	struct node* ptr = head;
	head=head->next;
	free(ptr);
	return head;
}

struct node* DeleteFromIndex(struct node* head, int index)
{
	struct node* p = head;
	int i;
	while(i!=index-1) {
		p = p->next;
		i++;
	}
	struct node* q = p->next;
	p->next = q->next;
	free(q);
	return head;
}

struct node* DeleteLast(struct node* head)
{
	struct node* p = head;
	struct node* q = head->next;
	int i;
	while(q->next!=NULL)
	{
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	free(q);
	return head;
}

struct node* DeleteNode(struct node* head, int value)
{
	struct node* p = head;
	struct node* q = head->next;
	int i;
	while(q->data!=value && q->next!=NULL)
	{
		p = p->next;
		q = q->next;
	}
	
	if(q->data == value)
	{
		p->next = q->next;
		free(q);
	}
	return head;
}

void printList(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	printf("\n");
}

int main()
{
	struct node* head = NULL;
	
	int n, i, value, value2;
	
	printf("Enter the no. of value you need to enter: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&value);
		head = Insert(head, value);
	}
	
	printf("\nLinked list before deletion: ");
	printList(head);
	
	head = DeleteHead(head);
	
	int index;
	printf("\nEnter the index value of the node you want to delete: ");
	scanf("%d",&index);
	
	head = DeleteFromIndex(head, index);
	head = DeleteLast(head);
	
	printf("\nEnter the node value you want to delete: ");
	scanf("%d",&value2);
	
	head = DeleteNode(head,value2);
	
	printf("\nLinked list after deletion: ");
	printList(head);
}
