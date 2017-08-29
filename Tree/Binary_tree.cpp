#include<iostream>
using namespace std;
struct bnode
{
	int data;
	bnode *left;
	bnode *right;
};
class btree
{
		bnode *T;
		int count;
		bnode *gettree(bnode *,int);
		bnode *mirror(bnode *);
		void inordertrav(bnode *);
		void preordertrav(bnode *);
		void postordertrav(bnode *);
	public:
		void insert(int);
		void inorder();
		void postorder();
		void preorder();
		btree()
		{
			int count=0;
			T=NULL;
		}
};

void btree::insert(int x)
{
	T=gettree(T,x);
}
void btree::inorder()
{
	inordertrav(T);
}

void btree::preorder()
{
	preordertrav(T);
}

void btree::postorder()
{
	postordertrav(T);
}


bnode *btree::gettree(bnode *T,int x)
{
	if(T==NULL)
	{
		T=new bnode;
		T->left=T->right=NULL;
		T->data=x;
		count++;
	}
	else
		if(count%2==0)
			T->left=gettree(T->left,x);
		else
			T->right=gettree(T->right,x);
		return(T);
}

void btree::inordertrav(bnode *T)
{
	if(T!=NULL)
	{
		inordertrav(T->left);
		cout<<endl<<T->data;
		inordertrav(T->right);
	}
}

void btree::preordertrav(bnode *T)
{
	if(T!=NULL)
	{
		cout<<endl<<T->data;
		preordertrav(T->left);
		preordertrav(T->right);
	}
}

void btree::postordertrav(bnode *T)
{
	if(T!=NULL)
	{
		preordertrav(T->left);
		preordertrav(T->right);
		cout<<endl<<T->data;
	}
}

int main()
{
	btree T;
	int data,i;
	for(i=0;i<7;i++)
	{
		cout<<"enter data\n";
		cin>>data;
		T.insert(data);
	}
	cout<<"\ninorder traversing :\n";
	T.inorder();
		cout<<"\npreorder traversing :\n";
	T.preorder();
		cout<<"\npostorder traversing :\n";
	T.postorder();
	return 0;
}
