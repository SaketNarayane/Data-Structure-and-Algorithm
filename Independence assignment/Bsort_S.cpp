#include<iostream>
using namespace std;
#define size 100

int n;
class stack
{
	private:
		int topofstack;
		int a[size];
	public:
		stack()
		{
			topofstack=-1;
		};
		int isempty()
		{
			if(topofstack==-1)
				return 1;
			else
				return 0;	
		};
		int isfull()
		{
			if(topofstack==size-1)
				return 1;
			else
				return 0;
		};
		void push(int k)
		{
			if(isfull())
				cout<<"stack is full\n";
			else
				a[++topofstack]=k;
		};
		int pop()
		{
			int t;
			if(isempty())
			{
				cout<<"stack is empty\n";
				return -1;
			}
			else
			{
//			cout<<a[topofstack];
			t=a[topofstack];
			topofstack--;
			return t;
			}
		};
		int create()
		{
			int i,k;
			cout<<"How many elements you want to sort?\n";
			cin>>n;
			for(i=0;i<n;i++)
			{
				cout<<"enter elements\n";
				cin>>k;
				push(k);
			}
			return n;
		};
//		void print()
//		{
//			cout<<"the sorted order is\n";
//			while(!isempty())
//			{
//				cout<<pop();
//			}
//		};
};

//		void transfer(stack &s1,stack &s2)
//		{
//			while(!s1.isempty())
//			{
//				cout<<s1.pop();
//				s2.push(s1.pop());
//			}
//		};
		

int main()
{
	stack s1,s2;
	int k1,k2,n,i,j,f;
	n=s1.create();
	for(i=0;i<n;i++)
	{
		f=0;
		k1=s1.pop();
		for(j=i+1;j<n;j++)
		{
			if(f)
			{
				k1=s1.pop();
			}
			else
			{
				k2=s1.pop();
			}
			if(k1<k2)
			{
				s2.push(k1);
				f=1;
			}
			else
			{
				s2.push(k2);
				f=0;
			}


		}
			if(f)
			{
				s2.push(k2);
			}
			else
			{
				s2.push(k1);
			}
						while(!s2.isempty())
			{
				s1.push(s2.pop());
			}
//		transfer(s1,s2);
	}
	cout<<"sorted array is \n";
//	s1.push(3);
	while(!s1.isempty())
	{
//		cout<<"gdfhgf";
		n=s1.pop();
		cout<<n<<" ";
	}
//	s1.print();
	return 0;
}
