#include<iostream>
#include<cmath>
#define size 10
using namespace std;
class stack
{
	private:
		int topofstack;
		long int a[size];
		public:
			stack();
			bool isemptystack();
			bool isfullstack();
			long int & top() ;
			void makeEmpty();
			void push(long int&x);
			void pop();
};
stack::stack()
{
	topofstack=-1;	
}
bool stack::isemptystack()
{
	return(topofstack==-1);
}
bool stack::isfullstack()
{
	return (topofstack==(size-1));
}
void stack::makeEmpty()
{
	topofstack=-1;
}
void stack::push(long int &x)
{
	if(isfullstack())
	cout<<"Size is full";
	else
	a[++topofstack]=x;
}
long int & stack::top()
{
	if(isemptystack())
	cout<<"stack is empty";
	else
	return a[topofstack];
}
void stack::pop()
{
	int x;
	if(isemptystack())
	cout<<"stack is empty";
	else
	topofstack--;
}
int main()
{
long int x; stack binary;
cout<<"Enter the number";
cin>>x;
int i=0,rem;
long int num[20];
while(x>0)
{
	num[i]=x%10;
	i++;
	x = x/10;
binary.push(num[i]);
}
int f=0;
i=0;
while(!binary.isemptystack())
{
      if(binary.top()==num[i])
      {
      	f=0;
	  }
  		else
  		{
  			f=1;
  			break;
  		}
      binary.pop();
      i++;
}
  if(f==0)
  {
  	cout<<"it is not palindrome";
  }
  else
  {
  	cout<<"it is a palindrome";
  }
	return 0;
}
