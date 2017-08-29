#include<iostream>
#include<cmath>
#define size 100
#include<cstring>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class stack
{public:
	char s[30];
	int top;
	char & topp();
	char & t2();
	bool isstackfull();
	bool isstackempty();
	void push(char &x);
	void pop();
	stack();
	
};
stack::stack()
{
	top=-1;
}
bool isop(char x)
{
	if((x=='+')||(x=='-')||(x=='*')||(x=='/'))
	return true;
	else
	return false;
}
bool stack::isstackfull()
{ 
   if(top==size-1)
  return true;
  else
  false;
}
bool stack::isstackempty()
{ 
  if(top==-1)
  return true;
  else
  false;	
}
void stack::push(char &x)
{
	if(isstackfull())
	cout<<"it is full\n";
	else
	s[++top]=x;
}
void stack::pop()
{
	if(isstackempty())
	cout<<"it is empty\n";
	else
	top--;
}
char & stack::topp()
{
	return s[top];
}
char & stack::t2()
{
	return s[top-1];
}
int pref(char &x)
{
	if(x=='*'||x=='/')
	return 1;
	else if(x=='+'||x=='-')
	return 2;
	else
	return 0;
}
int main()
{
	stack a;
	cout<<"enter postfix expression:";
	char q[30];
	cin>>q;
	int t=0;
	int l,i,j,c=0;
	l=strlen(q);
	for(i=0;i<l;i++)
	{
		if(isop(q[i]))
		{
			if(pref(q[i])==1)
			{
				if(q[i]=='*')
				t=t + ((a.topp()-'0') * (a.t2()-'0'));
				else
				t=t + ((a.t2()-'0') / (a.topp()-'0'));
				a.pop();
				a.pop();
			}
			else
			if(pref(q[i])==2)
			{
				if(q[i]=='+')
				t=t+ a.topp();
				else
				t=t-a.topp();
			}
			else
			cout<<"\ninvalid operator";
		}
		else
		a.push(q[i]);
	}
	cout<<endl<<t;
	
}
