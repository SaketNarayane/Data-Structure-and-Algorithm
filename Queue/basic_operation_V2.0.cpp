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
		return -1;
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

int create(queue &Q)
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
	return n;
}

void print(queue &Q,int no)
{
	int r,i;
	cout<<"the elements in queue are\n";
	for(i=0;i<no;i++)
	{
		r=dequeue(Q);
		enqueue(Q,r);
		cout<<r<<" ";
	}
}

void choose(queue &Q,int no)
{
	int ch,k;
	char m='y';
	
	while(m=='y')
	{
	cout<<"\nwhich operation you want to perform?\n1.enqueue\n2.dequeue\n3.print\n";
	cin>>ch;
	switch(ch)
	{
		case 1:{ cout<<"enter the number you want to enqueue\n";
			cin>>k;
			enqueue(Q,k);
			no++;
			print(Q,no);
			break;
		}
		case 2:{
			k=dequeue(Q);
			cout<<k<<" is dequeued\n";
			no--;
			print(Q,no);
			break;
		}
		case 3:{print(Q,no);
			break;
		}
		
	}
	cout<<"\nwant do more operations?\n";
	cin>>m;
	}
}

int main()
{
	int no;
	queue Q;
	initiate(Q);
	no=create(Q);
	choose(Q,no);
	return 0;
}
