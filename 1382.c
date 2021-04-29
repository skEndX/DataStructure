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
		if (temp->data==_data)return;
		while (temp->next!=0)
		{
			temp = temp->next;
			if (temp->data==_data)return;
		}
		temp->next = new;
		return;
	}
}
void reverseList() {
	struct node*temp = head;
	struct node*pre=0, *cur=0;
	while (temp!=0)
	{
		cur = temp->next;
		temp->next = pre;
		pre = temp;
		temp = cur;
	}
	head = pre;
}
void showSLL() {
	struct node*temp = head;
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main() {
	int data;

	while (1)
	{
		scanf("%d", &data);
		if (data<0)
		{
			reverseList();
			showSLL();
			break;
		}
		addToSLL(data);
	}
}