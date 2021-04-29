#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *pre;
};
struct node*head = 0;

void addToSLL(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = new->pre= 0;
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
		new->pre = temp;
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
	int data;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToSLL(data);
	}
	showSLL();
	return 0;
}