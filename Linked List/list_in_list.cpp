#include<iostream>
using namespace std;
struct lnode
{
	int data;
	lnode *nexti;
};

struct mnode
{
	int data;
	mnode *next;
	lnode *branch;
};

//void create(lnode *L,int n)
//{
//	int i,k;
//	for(i=0;i<n;i++)
//	{
//		cout<<"enter the numbers\n";
//		cin>>k;
//		if(i==0)
//		{
//			addfront(L,k);
//		}
//		else
//		{
//			addend(L,k);
//		}
//		L->next=new lnode;
//	}
//}

void create(lnode *L)
{
	int i,c=0,n;
	char ch='y';
//	cout<<"enter the no of nodes\n";
//	cin>>n;
	cout<<"enter the nos\n";
//	do
//	{
//	for(i=0;i<n;i++)
//	{
	while(ch!='n')
	{
		cin>>L->data;
		L=L->nexti;
		cout<<"want to enter more?(y/n)\n";
		cin>>ch;
	}
//	}
//	}while(c<n);
}
void print(lnode *L)
{
	while(L->nexti!=NULL)
	{
		cout<<L->data;
		L=L->nexti;
	}
}
int main()
{
	mnode *M,*T;
	int i,rem,n;
	char ch='y';
	T=M;
	for(i=0;i<10;i++)
	{
		M->data=i;
		M=M->next;
	}
	M->next=NULL;
	M=T;
	while(ch!='y')
	{
	cout<<"enter the number\n";
	cin>>n;
	rem=n%10;
	while(M->data!=rem)
		M=M->next;
	if(M->branch==NULL)
	{
	M->branch= new lnode;
	M->branch->data=n;
	}
	else
	{
		while(M->branch->nexti!=NULL)
		{
			M->branch=M->branch->nexti;
		}
		lnode *N;
		N->data=n;
		M->branch->nexti=N;
		N->nexti=NULL;
	}
	cout<<"want to enter more?\n";
	cin>>ch;
	}
	while(M->next!=NULL)
	{
		print(M->branch);
		M=M->next;
	}
return 0;
}

