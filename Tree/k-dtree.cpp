#include<iostream>
using namespace std;
struct kdnode
{
	kdnode *lchild;
	int data;
	kdnode *rchild;
};
kdnode *temp,*temp2;

void insert(kdnode *&T,int k)
{
	if(T==NULL)
	{
		T=new kdnode;
		T->data=k;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else
	{
		if(k<T->data)
		{
			insert(T->lchild,k);
		}
		else
		{
			insert(T->rchild,k);
		}
	}
}

void del(kdnode *&T,int k)
{
	int t;
//	kdnode *temp;
	if(T!=NULL)
	{
	if(T->data==k)
	{
		if(T->lchild==NULL)
		{
			if(T->rchild==NULL)
			{
				T=NULL;
			}
			else
			{
				T=T->rchild; 
			}
		}
		else
		{
			if(T->rchild==NULL)
			{
				T=T->lchild;
			}
			else
			{
				temp=T;
				temp=temp->rchild;
				while(temp->lchild!=NULL)
				{
					temp=temp->lchild;
				}
				t=temp->data;
				del(temp,t);
				T->data=t;
//								temp=T;
//				T=T->rchild;
//				while(T->lchild!=NULL)
//				{
//					T=T->lchild;
//				}
//			T->lchild=temp->lchild;
//			temp2=
//			while(T->rchild!=NULL)
//			{
//				T=T->rchild;
//			}
//			T->rchild=temp->rchild;
			}
		}
	}
	else
	{
		if(k<T->data)
		{
			del(T->lchild,k);
		}
		else
		{
			del(T->rchild,k);
		}
	}
	}
	else
	{
		cout<<"\nthe number to b deleted aint in d tree\n";
	}
}

/*void create(kdnode *T)
{
	
	int n,i,k;
	cout<<"how many nodes you want to enter?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter node\n";
		cin>>k;
		insert(T,k);
	}
}*/

void  preorder(kdnode *T)
{
//	cout<<"pre order traversal\n";
	if(T!=NULL)
	{
		cout<<T->data;
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void inorder(kdnode *T)
{
//		cout<<"in order traversal\n";
		if(T!=NULL)
	{

		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}

void postorder(kdnode *T)
{
//	cout<<"post order traversal\n";
	if(T!=NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data;
	}
}

int main()
{
	kdnode *T=NULL;
	
	int n,i,k,o;
	cout<<"how many nodes you want to enter?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter node\n";
		cin>>k;
		insert(T,k);
	}
	cout<<"\npre order\n";
	preorder(T);
	cout<<"\ninorder\n";
	inorder(T);
	cout<<"\npost order\n";
	postorder(T);
	cout<<"do you want to delete an element? (1/0)\n";
	cin>>o;
	if(o)
	{
		cout<<"enter the no to b deleted\n";
		cin>>k;
		del(T,k);
	}
	
	
	cout<<"\npre order\n";
	preorder(T);
	cout<<"\ninorder\n";
	inorder(T);
	cout<<"\npost order\n";
	postorder(T);

}
