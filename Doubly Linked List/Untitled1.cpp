#include<iostream>
using namespace std;

struct dnode
{
	int data;
	dnode *right;
	dnode *left;
};

dnode *H;

void addend(dnode *D,int k)
{
	D=H;
	if(D=NULL)
	{
		D=new Dnode;
		D->left=NULL;
		D->right=NULL;
		D->data=k;
	}
	else
		while(D->right!=NULL)
		{
			D=D->right;
		}
		D=new dnode;
		D->data=k;
		D->next=NULL;
}

int main()
{
	dnode *D;
	int n,i,k;
	cout<<"enter number of nodes\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter no\n";
		cin>>k;
		addend(D,k);
	}
	return 0;
}
