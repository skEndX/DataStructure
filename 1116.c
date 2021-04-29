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
	struct node*temp = head;

	if (head==0)
	{
		head = new;
		return;
	}
	else
	{
		while (temp->next!=0)
		{
			temp = temp->next;
		}
		temp->next = new;
		return;
	}
}

void insertIntoSLL(int whos, int n_data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = n_data;
	new->next = 0;
	struct node *temp = head;
	if (temp->data == whos)
	{
		new->next = head;
		head = new;
		return;
	}
	while (1)
	{
		if (temp->next==0)
		{
			temp->next = new;
			return;
		}
		if (temp->next->data==whos)
		{
			new->next = temp->next;	
			temp->next = new;	
			return;
		}
		temp = temp->next;
	}
}

void showSLL() {
	struct node*temp = head;
	while (temp!=0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}

int main() {
	int num;
	int data;
	int new;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToSLL(data);
	}
	scanf("%d %d", &data, &new);
	insertIntoSLL(data, new);
	showSLL();
	return 0;
}