#include<iostream>
#include<cstring>
#define size 100
using namespace std;
class stack
{
	private:
		int topofstack;
		char a[size];
		int tp;
	public:
		stack();
		void push(char &x);
		void pop();
		void makeempty();
		char top();
		bool isfull();
		bool isempty();
		void pref(stack& s,char& x);
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
void stack::pref(stack& s,char& x)
{	
	if(topofstack>0)
	{
		if(topofstack=='*'||topofstack=='/')
		{
			s.push(x);
		}
		else	if(x=='+'||x=='-')
		{
			if(topofstack=='*'||topofstack=='/'||topofstack=='+'||topofstack=='-')
			{
					tp=s.top();
					cout<<tp;
					s.pop();
					s.push(x);
			}
		}
		else	if(x=='(')
		{
			while(x!=')')
			{
				s.pref(s,x);
			}
		}
	}
}
int main()
{
	stack s;
	char src[50];
	int i,l;
	cout<<"enter the expression\n";
	cin.getline(src,50);
	l=strlen(src);
	for(i=0;i<l;i++)
	{
		if(src[i]=='+'||src[i]=='-'||src[i]=='*'||src[i]=='/'||src[i]=='('||src[i]==')')
		{
				s.pref(s,src[i]);
		}
		else
			cout<<src[i];
	}

return 0;
}
