#include<iostream>
#include<stdlib.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	struct node *next;
	
};
struct node *rear=0;
struct node  *front=0;
void enqueue()
{
	struct node *newnode;
	string name;
	cout<<"Enter the value you want to insert\n";
	getline(cin,name);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=stoi(name);
	newnode->next = 0;
	if(front==0 && rear ==0)
	{
		front=rear;
		rear=newnode;
	}
	else
	{
		rear->next = newnode;
		rear = newnode;
	}
}
void dequeue()
{
	struct node *temp;
	temp = front;
	if(front==0 && rear==0)
	{
		cout<<"Queue is empty\n";
	}
	else if(front == rear)
	{
		cout<<"Dequeued element is "<<front->data;
		front = front->next;
		free(temp);
		front =rear = 0;
	}
	else
	{
		cout<<"Dequeued element is "<<front->data;
		front = front->next;
		free(temp);
	}
}
void display()
{
	struct node * temp;
	if(front==0 && rear == 0)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		temp = front;
		cout<<"Your Queue is:\n";
		while(temp!=0)
		{
			cout<<"\t",temp->data;
			temp = temp->next;
		}
	}}
	void isEmpty()
{
	if(front==0 && rear ==0)
	{
		cout<<"Queue is empty\n";
	}
	else
	{
		cout<<"Queue is not empty\n";
	}
}

int main()
{
	
	int choice;
	while(1)
	{
		printf("\n\tEnter the choice:\n");
		printf("1-Enqueue Operation\n");
		printf("2-Dequeue Operation\n");
		printf("3-Display\n");
		printf("4-To check whether the queue is empty or not\n");
		printf("5-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				isEmpty();
				break;
			case 5:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}

