#include<stdlib.h>
#include<cstring>
#include<iostream>

using namespace std;
struct node
{
	char data[100];
	struct node *next;
};
struct node *front=0;
struct node *rear=0;

void enqueue()
{
	struct node *newnode;
		newnode=(struct node*)malloc(sizeof(struct node));
	char name[100];

//	gets(name);
	cin>>name;
    //scanf("%s",name);
	strcpy(newnode->data,name);
	newnode->next = 0;
	if(front==0 && rear ==0)
	{
		front=rear=newnode;
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
		printf("Queue is empty\n");
	}
	else if (front == rear)
	{
		printf(" %s",front->data);
		front = front->next;
		free(temp);
		front =rear = 0;
	}
	else
	{
		printf("%s",front->data);
		front = front->next;
		free(temp);
	}
}

void display()
{
	struct node * temp;
	if(front==0 && rear == 0)
	{
		printf("Queue is empty\n");
	}
	else
	{
		temp = front;
		printf("Your Queue is:\n");
		while(temp!=0)
		{
			printf("%s\n",temp->data);
			temp = temp->next;
		}
	}
}

void isEmpty()
{
	if(front==0 && rear ==0)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue is not empty\n");
	}
}


void show()
{
	printf("Please ,now the turn is:");
	dequeue();
	
}

int main()
{
	int choice;
	while(1)
	{
		printf("\n\tEnter the choice:\n");
		printf("1-Please register your name in queue\n");
		printf("2-if you have already taken services you can remove your name\n");
		printf("3-Display your name to check your name in the list \n");
		printf("4-To check whether the queue is empty or not\n");
		printf("5-Check whose turn is now\n");
		printf("6-Exit\n");
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
				show();
				break;
			case 6:
				
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}
