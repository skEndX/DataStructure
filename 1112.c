#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node*head = 0;

void addToSLL(int _data) {
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = 0;

	if (head==0)
	{
		head = new;
		return;
	}
	else
	{
		struct node*temp = head;
		while (temp->next!=0)
		{
			temp = temp->next;
		}
		temp->next = new;
		return;
	}
}

int delFromSLL(int _data) {
	struct node*temp = head;
	struct node*before = head;

	if (temp->data == _data)
	{
		head = head->next;
		return;
	}
	while (1)
	{
		temp = temp->next;
		if (temp->data==_data)
		{
			before->next = temp->next;
			break;
		}
		before = before->next;
		if (temp->next==0)
		{
			return;
		}
	}
	free(temp);
	return;
}
	
void showSLL() {
	struct node*temp = head;
	while (temp!=0)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main() {
	int num;
	int data;

	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d",&data);
		addToSLL(data);
	}
	scanf("%d",&data);
	delFromSLL(data);
	showSLL();
	return 0;
}