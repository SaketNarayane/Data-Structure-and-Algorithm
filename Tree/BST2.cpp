#include<iostream>
#include<queue>
using namespace std;

struct bstnode
{
	bstnode *lchild;
	int data;
	bstnode *rchild;
};
queue<bstnode*>q;
bstnode *temp,*temp2;

//struct queue
//{
//	bstnode *dat[size];
//	int front;
//	int rear;
//};
//
//void initiate(queue &Q)
//{
//	Q.front=-1;
//	Q.rear=-1;
//}
//
//int isqempty(queue Q)
//{
//	if(Q.front==-1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int isqfull(queue Q)
//{
//	if((Q.rear%size+1)==Q.front)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//void enqueue(queue &Q,bstnode *T)
//{
//	if(isqfull(Q))
//	{
//		cout<<"\nqueue is full\n";
//	}
//	else
//	{
//		if(isqempty(Q))
//		{
//			Q.front=0;
//			Q.rear=0;
//		}
//		else
//		{
//			Q.rear=(Q.rear+1)%size;
//		}
//		Q.dat[Q.rear]=T;
//	}
//}
//
//bstnode *dequeue(queue &Q)
//{
//	cout<<"\n *in dequeue funtion* \n";
//	bstnode *t;
////	t=new bstnode;
//	if(isqempty(Q))
//	{
//		cout<<"\nqueue is empty\n";
//		return NULL;
//	}
//
//	else
//	{
//		if(Q.front==Q.rear)
//		{
//			cout<<"\n*in if*\n";
//			t=Q.dat[Q.front];
//			initiate(Q);
//			cout<<"\n*front*\n"<<Q.front<<endl;
//			cout<<"\n*rear*\n"<<Q.rear<<endl;
//
//		}
//		else
//		{
//			cout<<"\n*in else*\n";
//			cout<<"\n*before*\n";
//			cout<<" front "<<Q.front;
//		//	t= new bstnode;
//			
//			t=Q.dat[0];
////			cout<<"\nQ.data "<<Q.dat[Q.front]->data;
//			Q.front=(Q.front+1)%size;
//			cout<<" \n*after*\n";
//			cout<<" front "<<Q.front;
//		}
//	}
//	cout<<"\n temp data is \n";
//	cout<<t->data;
//	return t;
//}

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

int min(bstnode *t)
{
	if(t->lchild==NULL)
		return t->data;
	else
		min(t->lchild);
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
				t=min(T->rchild);
				T->data=t;
				del(T->rchild,t);
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
		cout<<T->data<<" ";
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
		cout<<T->data<<" ";
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
		cout<<T->data<<" ";
	}
}

void levelorder(bstnode *T)
{
//	queue Q;
	bstnode *temp,*X;
	temp=new bstnode;
	temp->data=-1;
	temp->lchild=NULL;
	temp->rchild=NULL;
//	cout<<"\n *before enqueue* \n";
	q.push(T);
	q.push(temp);
//	cout<<"\n*after enqueue*\n";
//	cout<<"  d  "<<Q.rear;
	while(!q.empty())
	{
		
//		cout<<"\n*not empty*\n";
		X=q.front();
		q.pop();
		if(q.empty())
			break;
//		cout<<"\n data of dequeued element is \n"<<X->data;
		if(X->data!=-1)
		{
			cout<<X->data<<"\t";
			if(X->lchild!=NULL)
				q.push(X->lchild);
			if(X->rchild!=NULL)
				q.push(X->rchild);
		}
		else
		{
			cout<<endl;
			q.push(temp);
//			if(q.front==Q.rear)
//				break;
		}
	}
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
	cout<<"\npre order\n";
	preorder(T);
	cout<<"\ninorder\n";
	inorder(T);
	cout<<"\npost order\n";
	postorder(T);
	
	cout<<"enter the no to b deleted\n";
	cin>>k;
	del(T,k);
	
	cout<<"\npre order\n";
	preorder(T);
	cout<<"\ninorder\n";
	inorder(T);
	cout<<"\npost order\n";
	postorder(T);
	
	cout<<"\n\nlevel order\n";
	levelorder(T);
	return 0;
}
