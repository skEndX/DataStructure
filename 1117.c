#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node*next;
};
struct node*head1 = 0;
struct node*head2 = 0;

void addToSLL1(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = 0;
	struct node*temp = head1;
	if (head1==0)
	{
		head1 = new;
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
void addToSLL2(int _data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = _data;
	new->next = 0;
	struct node*temp = head2;
	if (head2 == 0)
	{
		head2 = new;
		return;
	}
	else
	{
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new;
		return;
	}
}
int compare() {
	struct node*temp1 = head1, *temp2 = head2;
	int cnt = 0;
	while (1)
	{
		if (temp1==0)
		{
			return cnt;
		}
		while (1)
		{
			if (temp2==0)
			{
				temp2 = head2;
				break;
			}
			if (temp1->data==temp2->data)
			{
				cnt++;
				temp2 = head2;
				break;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
int main() {
	int num;
	int data;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToSLL1(data);
	}
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToSLL2(data);
	}
	printf("%d",compare());
}