#include<iostream>
#define size 30
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
bstnode *temp,*temp2;

class stack
{
	public:
	int topofstack;
	bstnode *a[size];
	
		stack()
		{
			topofstack=-1;
		};
		int isempty()
		{
			if(topofstack==-1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		};
		int isfull()
		{
			if(topofstack==(size-1))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		void push(bstnode *T)
		{
			if(isfull())
			{
				cout<<"stack is full\n";
			}
			else
			{
				a[++topofstack]=T;
			}
		};
		bstnode * pop()
		{
			if(isempty())
			{
				cout<<"stack is empty\n";
			}
			else
			{	
				return a[topofstack--];
			}
		};
};

void insert(bstnode *&T,int k)
{
//	T=head;
	if(T==NULL)
	{
		T=new bstnode;
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

void del(bstnode *&T,int k)
{
	int t;
//	bstnode *temp;
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

/*void create(bstnode *T)
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

//void  preorder(bstnode *T)
//{
//	cout<<"pre order traversal\n";
//	if(T!=NULL)
//	{
//		cout<<T->data;
//		preorder(T->lchild);
//		preorder(T->rchild);
//	}
//}
//
void inorder(bstnode *T)
{

		if(T!=NULL)
	{

		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}

//void postorder(bstnode *T)
//{
//	cout<<"post order traversal\n";
//	if(T!=NULL)
//	{
//		postorder(T->lchild);
//		postorder(T->rchild);
//		cout<<T->data;
//	}
//}

void printleft(bstnode *T)
{
	stack s;
	while(T!=NULL)
	{
		s.push(T);
		T=T->lchild;

	}
	
	while(!s.isempty())
	{
		T=s.pop();
		cout<<T->data<<" ";

	}
}

void printright(bstnode *T)
{
	T=T->rchild;
	while(T!=NULL)
	{
		cout<<T->data<<" ";
		T=T->rchild;
	}
}

void topview(bstnode *T)
{
	printleft(T);
	printright(T);
}

int main()
{
	bstnode *T=NULL;
	int n,i,k;
	cout<<"how many nodes you want to enter?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter node\n";
		cin>>k;
		insert(T,k);
	}
//	cout<<"\npre order\n";
//	preorder(T);
	cout<<"\ninorder\n";
	inorder(T);
//	cout<<"\npost order\n";
//	postorder(T);
//	
//	cout<<"enter the no to b deleted\n";
//	cin>>k;
//	del(T,k);
//	
//	cout<<"\npre order\n";
//	preorder(T);
//	cout<<"\ninorder\n";
//	inorder(T);
//	cout<<"\npost order\n";
//	postorder(T);
	
	cout<<"top view is:\n";
	topview(T);
}
