#include<iostream>
#include<cstring>
#define size 100
using namespace std;
class stack
{
	public:
		int topofstack;
//		int top2ofstack;
		char a[size];
		int tp;
		stack();
		void push(char &x);
		void pop();
		void makeempty();
		char top();
		bool isfull();
		bool isempty();
		void pref(stack& s,char& x);
//		char top2(int);
};

stack::stack()
{
	topofstack=-1;
//	top2ofstack=topofstack-1;
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
//	top2ofstack=topofstack-1;
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
//		top2ofstack++;

	}
}
void stack::pop()
{
	if(isempty())
		cout<<"stack is empty";
	else
	{
		topofstack--;
//		top2ofstack--;
	}
}
void stack::pref(stack& s,char& x)
{
	
//	cout<<s.top();
		if(topofstack=='*'||topofstack=='/')
		{
			s.push(x);
		}
		else	if(x=='+'||x=='-')
		{
			if(topofstack=='*'||topofstack=='/'||topofstack=='+'||topofstack=='-')
			{
//					temp=s.top();
//					s.pop();
					tp=s.top();
					cout<<tp;
					s.pop();
					s.push(x);
			}

		/*else	if(topofstack=='+',topofstack=='-')
		{
			continue;
		}*/
		}
		else	if(x=='(')
		{
			while(x!=')')
			{
				s.pref(s,x);
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
	g:for(i=0;i<l;i++)
	{
		if((src[i]=='+'||src[i]=='-'||src[i]=='*'||src[i]=='/'||src[i]=='('||src[i]==')')&&src[i]!=')')
		{
			if(s.isfull())
		 {
			s.push(src[i]);
		 }
			if(s.topofstack=='*'||s.topofstack=='/')
		{
			s.push(src[i]);
		}
		else	if(src[i]=='+'||src[i]=='-')
		{
			if(s.topofstack=='*'||s.topofstack=='/'||s.topofstack=='+'||s.topofstack=='-')
			{
//					temp=s.top();
//					s.pop();
					s.tp=s.top();
					cout<<s.tp;
					s.pop();
					s.push(src[i]);
			}

		/*else	if(topofstack=='+',topofstack=='-')
		{
			continue;
		}*/
		}
		else	if(src[i]=='(')
				{
					i++;
					goto g;
				}
	}
		else
			cout<<src[i];
}
	return 0;
}

