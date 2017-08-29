#include<iostream>
#include<cmath>
//#define size 100
using namespace std;
class stack
{
	private:
		int topofstack;
		long int a[size];
		public:
			stack();
			bool isemptystack() const;
			bool isfullstack() const;
			long int & top() ;
			void makeEmpty();
			void push(long int&x);
			void pop();
};
stack::stack()
{
	topofstack=-1;	
}
bool stack::isemptystack() const
{
	return(topofstack==-1);
}
bool stack::isfullstack() const
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
long int dec;long int rem; stack binary;
cout<<"Enter the number";
cin>>dec;
while(dec!=0)
{
	rem=dec%2;
	binary.push(rem);
	dec=dec/2;
}
cout<<"Equivalent binary number is:\n";

while(binary.isemptystack()!=1)
{
      cout<<binary.top();
      binary.pop();
}
	return 0;
}
