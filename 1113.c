#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node*head = 0;

void addToSLL(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
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

void delLocation(int _loc) {
	struct node*temp = head, *before;
	if (_loc==1)
	{
		head = head->next;
		free(temp);
		return;
	}
	for (int i = 1; i < _loc-1; i++)
	{
		temp = temp->next;
	}
	before = temp->next;
	temp->next = temp->next->next;
	free(before);
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
	int loc;

	scanf("%d",&num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToSLL(data);
	}
	scanf("%d", &loc);
	if (num>=loc)
	{
		delLocation(loc);
	}
	showSLL();
	return 0;
}