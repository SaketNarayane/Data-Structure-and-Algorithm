#include<iostream>
#include<cstring>
#define size 100
using namespace std;
union gen
{
	int x;
	char y[10];
	float z;
};
class stack
{
	private:
		int topofstack;
		char a[size];
	public:
		stack();
		void push(char &x);
		void push(int &x);
		void push(float &x)
		void pop();
		void makeempty();
		char top();
		bool isfull();
		bool isempty();
};

stack::stack()
{
	topofstack=-1;
}
bool stack::isfull()
{
	return(topofstack==size-1);
}
bool stack::isempty()
{
	return(topofstack==-1);
}
void stack::makeempty()
{
	topofstack=-1;
}
char stack::top()
{
	if(isempty())
		cout<<"stack is empty";
	else
		return(a[topofstack]);
}
void stack::push(char &x)
{
	if(isfull())
		cout<<"stack is full";
	else
	{
		a[++topofstack]=x;


	}
}
void stack::pop()
{
	if(isempty())
		cout<<"stack is empty";
	else
	{
		topofstack--;
	}
}
int main()
{
	gen g;
	stack s;
	int rno,tag;
	float cgpa;
	char name[10]
	cout<<"What do u want to enter?\n1.rollno\n2.name\n3.cgpa\n"
	cin>>op;
	
	switch(tag)
	{
		case 1:
		{
			cout<<"enter roll no\n";
			cin>>rno;
			g.x=rno;
			push(g.x);
				break;
		}
		case 2:
		{
			cout<<"enter name\n";
			gets(name);
			strcpy(g.y,name);
			push(g.y);
			break;
		}
		case 3:
		{
			cout<<"enter cgpa\n";
			cin>>cgpa;
			g.z=cgpa;
			push(g.z);
			break;
		}
	}
	while(!s.isempty)
	{
		s.top();
		s.pop();
	}
}
