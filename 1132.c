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
int total_showDLL() {
	struct node*temp = head;
	int data_cnt = 0,cnt=0;
	int i = 0;
	while (temp!=0)
	{
		temp = temp->next;
		cnt++;
	}
	temp = head;
	for ( i = 1;i<= cnt; i++)
	{
		while (temp != 0)
		{
			if (temp->data == i)
			{
				data_cnt++;
			}
			temp = temp->next;
		}
		if (data_cnt>0)
		{
			printf("%d %d ", i, data_cnt);
			data_cnt = 0;
		}
		temp = head;
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
	total_showDLL();
	return 0;
}