#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *pre;
};
struct node*head = 0;

void addToDLL(int _data) {
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
void insertIntoDLL(int whos, int n_data) {
	struct node*new = (struct node*)malloc(sizeof(struct node));
	new->data = n_data;
	new->next = 0; new->pre = 0;
	struct node*temp = head;
	while (temp!=0)
	{
		if (temp->data==whos)
		{
			new->next = temp->next;
			temp->next = new;
			new->pre = temp;
			temp->next->pre = new;
			return;
		}
		temp = temp->next;
	}
}
void reverseList() {
	struct node*temp = head;
	struct node *pre = 0, *cur = 0;
	while (temp!=0)
	{
		cur = temp->next;
		temp->next = pre;
		pre = temp;
		temp = cur;
	}
	head = pre;
}
void showDLL() {
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
	int new;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &data);
		addToDLL(data);
	}
	scanf("%d %d", &data, &new);
	insertIntoDLL(data, new);
	reverseList();
	showDLL();
	return 0;
}