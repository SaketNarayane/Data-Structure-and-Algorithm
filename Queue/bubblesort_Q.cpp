#include<iostream>
using namespace std;
#define size 5
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
	int i,k;
	for(i=0;i<5;i++)
	{
		cout<<"enter the number to be sorted\n";
		cin>>k;
		enqueue(Q,k);
	}
}

void print(queue &Q)
{
	int r,i;
	cout<<"\nthe elements in queue are\n";
	for(i=0;i<5;i++)
	{
		r=dequeue(Q);
		enqueue(Q,r);
		cout<<r<<" ";
	}
}

void bsort(queue &Q)
{
	int i,j,k1,k2,k,f;
//	f1=Q.front;
//	r1=Q.rear;
	for(i=0;i<4;i++)
	{
		f=1;
		k1=dequeue(Q);
		for(j=0;j<5-i-1;j++)
		{	
			if(f)
			{
				k2=dequeue(Q);
			}
			else
			{
				k1=dequeue(Q);
			}
			if(k1>k2)
			{
				enqueue(Q,k2);
//				k2=dequeue(Q);
//				r1=(r1+1)%size;
//				if(j==(5-i-1))
//				{
					f=1;
//				}
			}
			else
			{
				enqueue(Q,k1);
//				k1=dequeue(Q);
//				r1=(r1+1)%size;
//				if(j==(5-i-1))
//				{
					f=0;
//				}
			}
//			cout<<" at "<<j;
//			print(Q);
		}
		if(j<5)
		{
			if(f==1)
			{
				enqueue(Q,k1);
			}
			else
			{
				enqueue(Q,k2);
			}
			while(j<4)
			{
				k=dequeue(Q);
				enqueue(Q,k);
				j++;
			}
		}
//		cout<<"\n after"<<i;
//		print(Q);
	}
}

int main()
{
	queue Q;
	initiate(Q);
	create(Q);
	print(Q);
	cout<<"\nafter sorting ";
	bsort(Q);
	print(Q);
	return 0;
}
