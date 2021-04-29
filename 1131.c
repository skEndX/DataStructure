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
	struct node*temp = head;
	if (head==0)
	{
		head = new;
		return;
	}
	while (temp->next!=0)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->pre = temp;
}
int side(int _data) {
	struct node*temp = head;
	while (1)
	{
		if (temp->data == _data)
		{
			printf("-999 ");
			if (temp->next==0)
			{
				printf("-999");
				return;
			}
			printf("%d", temp->next->next->data);
			return;
		}temp = temp->next;
		if (temp->data == _data)
		{
			printf("-999 ");
			printf("%d", temp->next->next->data);
			return;
		}
		while (temp->next->next != 0 )
		{
			if (temp->data == _data)
			{
				printf("%d ", temp->pre->pre->data);
				printf("%d ", temp->next->next->data);
				return;
			}temp = temp->next;
		}
		if (temp->data == _data)
		{
			printf("%d ", temp->pre->pre->data);
			printf("-999");
			return;
		}temp = temp->next;
		if (temp->data == _data)
		{
			printf("%d ", temp->pre->pre->data);
			printf("-999");
			return;
		}
		if (temp->next==0)
		{
			printf("-999");
			return;
		}
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