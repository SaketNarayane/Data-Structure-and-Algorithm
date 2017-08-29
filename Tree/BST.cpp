#include<bits/stdc++.h>
using namespace std;
struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
bstnode *temp,*temp2;

void insert(bstnode *&T,int k)
{
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

void  preorder(bstnode *T)
{
//	cout<<"pre order traversal\n";
	if(T!=NULL)
	{
		cout<<T->data;
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void inorder(bstnode *T)
{
//		cout<<"in order traversal\n";
		if(T!=NULL)
	{

		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}

void postorder(bstnode *T)
{
//	cout<<"post order traversal\n";
	if(T!=NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data;
	}
}

vector<vector<int> > trav(bstnode * A)
{
	stack<bstnode *> s;
queue<bstnode *> q;
bstnode *T = A;
bstnode* X;
X->data =-99;
q.push(T);
q.push(X);
vector<vector < int> > ans;
vector<int> t;
int i=1;
while(!q.empty())
{
	T=q.front();
	q.pop();
	while(T->data!=-99)
	{
		
		if(i&1)
		{
			if(T->lchild !=NULL)
			s.push(T->lchild);
			if(T->rchild !=NULL)
			s.push(T->rchild);
		}
		else
		{
			t.push_back(T->data);
			q.push(T);
		}
		T=q.front();
		q.pop();
	}
	i++;
	
	while(!s.empty())
	{
		t.push_back(s.top()->data);
		q.push(s.top());
		s.pop();
	}
	q.push(X);
	ans.push_back(t);
	t.clear();
	q.pop();
}
return ans;
}

int main()
{
	bstnode *T=NULL;
	
	int n,i,k,o;
	cout<<"how many nodes you want to enter?\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"enter node\n";
		cin>>k;
		insert(T,k);
	}
	
	vector< vector< int> > ans;
	
	ans=trav(T);
	return 0;
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
