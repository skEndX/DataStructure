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
	new->next = new->pre = 0;
	if (head==0)
	{
		head = new;
		return;
	}
	else
	{
		struct node*temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->pre = temp;
	}
}
int side(int _data) {
	struct node*temp = head;
	if (head->data==_data)
	{
		printf("%d ", -999);
		if (temp->next == 0)
		{
			printf("%d", -999);
			return;
		}
		printf("%d", temp->next->data);
		return;
	}
	while (temp->next!= 0)
	{
		if (temp->data==_data)
		{
			printf("%d ", temp->pre->data);
			printf("%d ", temp->next->data);
			return;
		}
		temp = temp->next;
	}
	if (temp->next==0)
	{
		if (temp->data==_data)
		{
			printf("%d ", temp->pre->data);
		}
		printf("%d", -999);
		return;
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
	side(data);
	return 0;
}