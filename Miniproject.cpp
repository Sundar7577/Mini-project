#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *front=0;
struct node *rear=0;

void enqueue()
{
	struct node *newnode;
	int num;
	printf("Enter the value you want to insert\n");
	scanf("%d",&num);
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = num;
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
	else if(front == rear)
	{
		printf(" %d",front->data);
		front = front->next;
		free(temp);
		front =rear = 0;
	}
	else
	{
		printf(" %d",front->data);
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
			printf("%d\t",temp->data);
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
		printf("1-Enqueue Operation\n");
		printf("3-Display\n");
		printf("4-Check whether the queue is empty or not\n");
		printf("5-Exit\n");
		printf("6-Turn of\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			
			case 2:
				display();
				break;
			case 3:
				isEmpty();
				break;
			case 4:
				exit(0);
			case 5:
				show();
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}