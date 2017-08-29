#include<iostream>
#include<cmath>
#define size 100
#include<cstring>
#include<stdio.h>
#include<conio.h>
using namespace std;
class stack
{public:
	char s[30];
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
bool isop(char x)
{
	if((x=='+')||(x=='-')||(x=='*')||(x=='/')||(x=='(')||(x==')'))
	return true;
	else
	return false;
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
{   char r[30];
    stack a;
	cout<<"enter equation\n";
	gets(r);
	char *q;
	q=strrev(r);
	int i,c=0,l;
	l=strlen(q);
	 for(i=0;i<l;i++)
	{   
	    if(isop(q[i]))
		 {
		 	if(q[i]=='(')
	       {
		    do
		     {
			  cout<<a.topp();
			  a.pop();
		      c--;
			 }while(a.topp()!=')');
			 c--;
			 a.pop(); 
	       }     
		    else
			if(q[i]=='*'||q[i]=='/'||q[i]==')')
			{
				a.push(q[i]);
				c++;
			}
			else
			{   
			    if(a.topp()==')')
			    {
			    	a.push(q[i]);
			    	c++;
			    }
				else if((a.topp()=='*')||(a.topp()=='/'))
				{
					cout<<a.topp();
					a.pop();
					c--;
					a.push(q[i]);
					c++;
				}
				else
				{
				a.push(q[i]); 
				c++;
				}
			}
		}
		else
		cout<<q[i];
	}
	for(i=1;i<=c;i++)
	{
	 cout<<a.topp();
     a.pop();
	}
	return 0;
}
