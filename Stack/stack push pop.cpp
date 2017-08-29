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
	if(isemptystack())
	cout<<"stack is empty";
	else
	topofstack--;
}
int main()
{
long int x; stack binary;
while(binary.isfullstack()!=1)
{
cout<<"Enter the number";
cin>>x;
binary.push(x);
}
cout<<"stack is full now\n";
while(binary.isemptystack()!=1)
{
      cout<<binary.top()<<endl;
      binary.pop();
}
	return 0;
}
