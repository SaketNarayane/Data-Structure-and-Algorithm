#include<iostream>
using namespace std;
struct dnode
{
	int data;
	dnode *right;
	dnode *left;
};

struct mnode
{
	int data;
	mnode *next;
	dnode *branch;
};
dnode *HD;
mnode *HM;

void addend(dnode *D,mnode *M,int k)
{
	
	D=HD;
	if(HD==NULL)
	{
		D=new dnode;
		D->left=M->branch;
		D->right=NULL;
		D->data=k;
		HD=D;
	}
	else
	{
		while(D->right!=NULL)
		{
			D=D->right;
		}
		dnode *T;
		T=new dnode;
		T->data=k;
		D->right=T;
		T->right=NULL;
		T->left=D;
//		cout<<"D->data is"<<D->data;
	}
}

void createm(mnode *M)
{
	int i;
	M=HM;
	for(i=0;i<10;i++)
	{
		M->data=i;
		M=M->next;
	}
	M->next=NULL;
}

void buckets(mnode *M,dnode *D)
{
	M=HM;
	D=HD;
	int rem,n;
	char ch='y';
	while(ch!='y')
	{
	cout<<"enter the number\n";
	cin>>n;
	rem=n%10;
	while(M->data!=rem)
		M=M->next;
	addend(M->branch,M,n);
	cout<<"want to enter more?\n";
	cin>>ch;
	}
}

void print(mnode *M,dnode *D)
{
	M=HM;
	D=HD;
	while(M->next!=NULL)
	{
		cout<<M->data<<"  ";
		while(D->right!=NULL)
		{
			cout<<D->data<<" ";
			D=D->right;
		}
		cout<<endl;
		M=M->next;
	}
}

int main()
{
	mnode *M;
	dnode*D;
	createm(M);
//	addend(M,D,k);
	buckets(M,D);
	print(M,D);
return 0;
}

