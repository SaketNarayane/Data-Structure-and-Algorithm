#include<iostream>
#include<cmath>
#define size 100
#include<string.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
class stack
{public:
	char s[10];
	int top;
	char & topp();
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
bool stack::isstackfull()
{ 
  return(top==size-1);
}
bool stack::isstackempty()
{
  return(top==-1);	
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

int main()
{
	stack a;
	int i,j,c=0;
	char r[10],p[10],q[10];
	cout<<"enter string\n";
	gets(r);
	size=strlen(r);
	for(i=0;i<size;i++)
	{
		a.push(r[i]);
	}
	for(i=0;i<size/2;i++)
	{
		q[i]=a.topp();
		a.pop();
	}
	for(i=0;i<size/2;i++)
	{
		if(q[i]==r[i])
		c++;
	}
	if(c==size/2)
	cout<<"\nit's pallindrome";
	else
	cout<<"\nit's not pallindrome";
	 	
}
