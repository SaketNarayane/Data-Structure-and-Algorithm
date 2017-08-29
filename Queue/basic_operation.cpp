#include<iostream>
using namespace std;
#define size 50
struct queue
{
	int front;
	int rear;
	int element[size];
};

void initiate(queue &Q)
{
	Q.front=-1;
	Q.rear=-1;
}

int isfull(queue &Q)
{
	if((Q.rear+1)%size==Q.front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isempty(queue &Q)
{
	if(Q.front==-1)
	{
		return 1;
	}
	else
		return 0;
}

void enqueue(queue &Q,int k)
{
	if(isfull(Q))
	{
		cout<<"the queue is full\n";
	}
	else
	{
		if(isempty(Q))
		{
			Q.front=0;
			Q.rear=0;
		}
		else
		{
			Q.rear=(Q.rear+1)%size;
		}
		Q.element[Q.rear]=k;
	}
}

int dequeue(queue &Q)
{
	int t;
	if(isempty(Q))
	{
		cout<<"the queue is empty\n";
	}
	
	else
	{
		if(Q.front==Q.rear)
		{
			t=Q.element[Q.front];
			initiate(Q);
		}
		else
		{
			t=Q.element[Q.front];
			Q.front=(Q.front+1)%size;
		}
	}
	return t;
}

void create(queue &Q)
{
	int n,i,k;
	cout<<"how many nos you want to enter in queue?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter the number\n";
		cin>>k;
		enqueue(Q,k);
	}
}

void print(queue &Q)
{
	int r;
	cout<<"the elements in queue are\n";
	while(!isempty(Q))
	{
		r=dequeue(Q);
		cout<<r<<" ";
	}
}

void choose(queue &Q)
{
	int ch,k;
	char m;
	cout<<"which operation you want to perform?\n1.enqueue\n2.dequeue\n3.print\n";
	cin>>ch;
	while(m=='y')
	{
	
	switch(ch)
	{
		case 1:{ cout<<"enter the number you want to enqueue\n";
			cin>>k;
			enqueue(Q,k);
			print(Q);
			break;
		}
		case 2:{
			k=dequeue(Q);
			cout<<k<<" is dequeued\n";
			print(Q);
			break;
		}
		case 3:{print(Q);
			break;
		}
		
	}
	cout<<"want do more operations?\n";
	cin>>m;
	}
}

int main()
{
	queue Q;
	initiate(Q);
	create(Q);
	choose(Q);
	return 0;
}
