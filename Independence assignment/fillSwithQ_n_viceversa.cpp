#include<iostream>
using namespace std;
#define size 100
#define sizeq 100

int n;
class stack
{
	private:
		int topofstack;
		int a[size];
	public:
		stack()
		{
			topofstack=-1;
		};
		int issempty()
		{
			if(topofstack==-1)
				return 1;
			else
				return 0;	
		};
		int issfull()
		{
			if(topofstack==size-1)
				return 1;
			else
				return 0;
		};
		void push(int k)
		{
			if(issfull())
				cout<<"stack is full\n";
			else
				a[++topofstack]=k;
		};
		int pop()
		{
			if(issempty())
			{
				cout<<"stack is empty\n";
				return -1;
			}
			else
			{
			int t=a[topofstack];
			topofstack--;
			return t;
			}
		};
		int create()
		{
			int i,k;
			cout<<"How many elements you want to enter in stack to transfer in queue?\n";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"enter elements\n";
				cin>>k;
				push(k);
			}
			return n;
		};
};


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
	int i,k;
	cout<<"how many nos you want to enter in queue to transfer it in stack?\n";
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

void transfer(stack &s,queue &Q,int ch)
{
	int t;
	if(ch==1)
	{
		while(!s.issempty())
		{
		t=s.pop();
		cout<<t<<" ";
		enqueue(Q,t);
		}
		print(Q,n);
	}
	else
	{	
	if(ch==2)
	{
		while(isempty(Q))
		{
		t=dequeue(Q);
		s.push(t);
		}
	}
	cout<<"elements in stack are\n";

	while(!s.issempty())
	{
		t=s.pop();
		cout<<t<<" ";
	}
	}
}


void choose(stack &s,queue &Q)
{
	int ch;
	cout<<"\nwhat do you want to do?\n1.fill stack with queue\n2.fill queue with stack\n";
	cin>>ch;
	switch(ch)
	{
		case 1:{
			n=s.create();
			cout<<"the elements in stack are\n";
			transfer(s,Q,ch);
			break;
		}
		case 2:{
			n=create(Q);
			print(Q,n);
			transfer(s,Q,ch);
			break;
		}
	}
}


int main()
{
	stack s;
	queue Q;
	choose(s,Q);
	return 0;
}
