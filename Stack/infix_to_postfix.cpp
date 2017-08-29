#include<iostream>
#include<cstring>
#define size 100
using namespace std;
class stack
{
	private:
		int topofstack;
		int top2ofstack;
		char a[size];
		char temp;
	public:
		stack();
		void push(char &x);
		void pop();
		void makeempty();
		char top();
		bool isfull();
		bool isempty();
		void pref(stack& s,char& x);
		char top2(int);
};

stack::stack()
{
	topofstack=-1;
	top2ofstack=topofstack-1;
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
	top2ofstack=topofstack-1;
}
char stack::top()
{
	if(isempty())
		cout<<"stack is empty";
	else
		return(a[topofstack]);
}
//char stack::top2(int topofstack)
//{
//	return(a[top2ofstack]);
//}
void stack::push(char &x)
{
	if(isfull())
		cout<<"stack is full";
	else
	{
		a[++topofstack]=x;
		top2ofstack++;

	}
}
void stack::pop()
{
	if(isempty())
		cout<<"stack is empty";
	else
	{
		topofstack--;
		top2ofstack--;
	}
}
void stack::pref(stack& s,char& x)
{
	
//	cout<<s.top();
	if(topofstack>0)
	{
		if(topofstack=='*'||topofstack=='/')
		{
			s.push(x);
		}
		else	if(topofstack=='+'||topofstack=='-')
		{
			if(top2ofstack=='*'||top2ofstack=='/')
			{
					temp=s.top();
					s.pop();
					cout<<s.top();
					s.pop();
					s.push(temp);
			}
			else
				s.push(x);
		/*else	if(topofstack=='+',topofstack=='-')
		{
			continue;
		}*/
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
//			s.push(src[i]);
//			cout<<s.top();
//			if(src[i]=='+'||src[i]=='-')
//			{
				s.pref(s,src[i]);
//			}
		}
		else
			cout<<src[i];
	}
	return 0;
}
