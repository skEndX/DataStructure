#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node *head = 0;

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

void reverseList(){
	struct node *temp = head;
	struct node *prev = 0, *cur = 0;

	while (temp != 0)
	{
		cur = temp->next;
		temp->next = prev;
		prev = temp;
		temp = cur;
	}
	head = prev;
}

void showSLL() {
	struct node*temp = head;
	while (temp->next!=0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);
}

int main() {
	int data;
	int num;
	
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToSLL(data);
	}
	reverseList();
	showSLL();
	return 0;
}