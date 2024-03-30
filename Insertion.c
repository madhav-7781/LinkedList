//LinkedList
/*In this Repository we will know about all the cases of Insertion in Linked List
Case 1. Insertion in beginning.
Case 2. Insertion at index value.
Case 3. Insertion at end.
Case 4. Insertion after a node.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* InsertValue(struct node* head, int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	
	if(head==NULL)
	{
		head = newnode;
		return head;
	}
	
	struct node* current = head;
	
	while(current->next!=NULL)
	{
		current = current->next;
	}
	current->next = newnode;
	return head;
}

struct node* InsertAtBeginning(struct node* head, int data)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=head;
	return ptr;
}

struct node* InsertAtIndex(struct node* head, int index, int data)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	
	struct node* p = head;
	
	int i = 0;
	
	while(i!=index-1)
	{
		p = p->next;
		i++;
	}
	ptr->next = p->next;
	p->next = ptr;
	return head;
}

struct node* InsertAtEnd(struct node* head, int data)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	
	struct node* p = head;
	
	while(p->next!=NULL)
	{
		p = p->next;
	}
	p->next = ptr;
	ptr->next=NULL;
	return head;
}

struct node* InsertAfterNode(struct node* head, struct node* prevnode, int data)
{
	struct node* ptr = (struct node*)malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = prevnode->next;
	prevnode->next = ptr;
	return head;
}

void printList(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main()
{
	struct node* head = NULL;
	
	int n, value, i, index, value2, value3, value4;
	
	printf("Enter the no. of value you need to enter: ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&value);
		head = InsertValue(head, value);
	}
	
	printf("List before insertion: ");
	printList(head);
	
	printf("\n\nEnter the value you need to enter at the begin: ");
	scanf("%d",&value2);
	
	head = InsertAtBeginning(head, value2);
	
	printf("\n\nEnter the index value where you need to enter the value with the value: ");
	scanf("%d %d",&index, &value3);
	
	head = InsertAtIndex(head, index, value3);
	
	printf("\n\nEnter the value you need to enter at the end: ");
	scanf("%d",&value4);
	
	head = InsertAtEnd(head, value4);

	printf("\nEnter the data of the node after which you need to insert a new node: ");
    	scanf("%d", &target);
    	printf("\nEnter the value you need to enter: ");
    	scanf("%d", &val5);
    	struct node* temp = head;
    	while (temp != NULL && temp->data != target) {
        	temp = temp->next;
    	}
    	if (temp != NULL) {
        	head = InsertAfterNode(head, temp, val5);
    	} else {
        	printf("Node with data %d not found!\n", target);
    	}
	
	printf("\n\nList after Insertion: ");
	printList(head);
}
