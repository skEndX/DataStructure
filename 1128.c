#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
	struct node*pre;
};
struct node*head = 0;
void addToDLL(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->pre = new->next = 0;
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
void delFromDLL(int _data) {
	struct node*temp = head;
	while (temp->next!=0)
	{
		while (head->data==_data)
		{
			head = head->next;
			free(temp);
			temp = head;
			if (temp==0) return;
		}
		if (temp->data==_data)
		{
			temp->pre->next = temp->next;
			temp->next->pre = temp->pre;
			free(temp);
			temp = head;
		}
		temp = temp->next;
		if (temp==0) return;
	}
	if (temp->next==0)
	{
		if (temp->data==_data)
		{
			temp->pre->next = 0;
			free(temp);
			return;
		}
		return;
	}
}
void showDLL() {
	struct node*temp = head;
	if (head==0)
	{
		printf("-999");
	}
	while (temp!=0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
int main() {
	int num;
	int data;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToDLL(data);
	}
	scanf("%d", &data);
	delFromDLL(data);
	showDLL();
	return 0;
}