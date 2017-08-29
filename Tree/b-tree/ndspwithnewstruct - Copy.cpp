#include<iostream>
#include<stack>
#include<queue>
using namespace std;
const int d=2;
struct bnode
{
	int count;
	int data[2*d];
	bnode *child[2*d+1];
};
struct spnode
{
	int count;
	int data[2*d+1];
	bnode *chld[2*d+2];
};

queue<bnode*>q;
stack<bnode*>s;
bnode *X;
int z=0;

void levelorder(bnode *T);

int returnpos(bnode*T,int k)
{
	cout<<"I'm in return position";
	for(int i=0;i<T->count;i++)
	{
		if(T->data[i]==k)
		{
			return i;
		}
	}
	return -3;
}

void add(bnode*&T,int k,int tag);

//void insertnsort(bnode *&T,int k)
//{
//	int flag=0;
//	cout<<"\nI'm in insertnsort\n";
////	if(T->child[1]!=NULL)
////	{
////		cout<<"\nsmall child of 50 are "<<T->child[1]->data[0]<<" "<<T->child[1]->data[1]<<endl;
////	}
//	for(int i=0;i<T->count;i++)
//	{
//		if(k<T->data[i])
//		{
//			for(int j=T->count-1;j>=i;j--)
//			{
//				T->data[j]=T->data[j-1];
//				T->child[j+1]=T->child[j];
//			}
//			T->data[i]=k;
////			T->child[i]=NULL;
////			T->child[i+1]=NULL;
//			flag=1;
//			break;
//		}
//	}
//	if(!flag)
//	{
//		T->data[T->count]=k;
//	}
//	T->count++;
////	cout<<T->data[0]<<endl;
////	if(T->child[1]!=NULL)
////	{
////		cout<<"\nsmall child of 50 are "<<T->child[1]->data[0]<<" "<<T->child[1]->data[1]<<endl;
////	}
//}


void insertnsort(bnode **&T,int k)
{
	int i,j;
	if(k>*T->data[*T->count-1])
	{
		*T->data[*T->count]=k;
		*T->count++;
	}
	else
	{
		for(i=*T->count-1;i>=0;i--)
		{
			if(k<*T->data[i])
			{
				*T->data[i+1]=*T->data[i];
				*T->child[i+2]=*T->child[i+1];
			}
			else
			{
				*T->data[i+1]=k;
				*T->child[i+2]=NULL;
				*T->count++;
				break;
			}
		}
		if(i<0)
		{
			*T->data[i+1]=k;
			*T->count++;
			*T->child[i+2]=NULL;
		}
//		cout<<"\n in insertnsort level order\n";
//		levelorder(*T);
	}

}
void insertnsort(spnode **&T,int k)
{
	int i,j;
	if(k>*T->data[*T->count-1])
	{
		*T->data[*T->count]=k;
		*T->count++;
	}
	else
	{
		for(i=*T->count-1;i>=0;i--)
		{
			if(k<*T->data[i])
			{
				*T->data[i+1]=*T->data[i];
				*T->chld[i+2]=*T->chld[i+1];
			}
			else
			{
				*T->data[i+1]=k;
				*T->chld[i+2]=NULL;
				*T->count++;
				break;
			}
		}
		if(i<0)
		{
			*T->data[i+1]=k;
			*T->count++;
			*T->chld[i+2]=NULL;
		}
//		cout<<"\n in insertnsort level order\n";
//		levelorder(*T);
	}

}

void splitnconnect(bnode **&T,int k)
{
//	z++;
//	if(z==6)
//		return;
	bnode **T1;
	cout<<"\n I'm in splitnconnect\n";
	int parent,i,j,l,flag=0;
	bnode **temp;
//		parent=**T->data[d-1];
		spnode *S;
		S=new spnode;

		S->count=2*d;
		
		for(i=0;i<*T->count;i++)
		{
			S->data[i]=*T->data[i];
			S->chld[i]=*T->child[i];
		}
		S->chld[i]=*T->child[i];
		S->chld[i+1]=NULL;
		insertnsort(&S,k);
		parent=S->data[d];
		
//	cout<<"after splitting, parent is "<<parent<<endl;
		if(!s.empty())
		{
			X=s.top();
			s.pop();
			cout<<"X value is "<<X->data[0];
		}

		add(X,parent,0);
		i=returnpos(X,parent);
		cout<<"\n position of parent is "<<i;
	cout<<"\n X is "<<X->data[0]<<endl;
//	cout<<*T->data[0];

//	if(X->count==1)
//	cout<<*T->data[0]<<*T->data[1];
//	cout<<" "<<X->data[0]<<X->data[1];
		X->child[i]=*T;
//	else
//	{
//				cout<<"\n in splitnconnect, level order is\n";
//		levelorder(*T);
//
//	}
	X->child[i+1]=new bnode;
	cout<<"\n before for loop\n";
	for( j=0;j<d;j++)
	{
		X->child[i]->data[j]=S->data[j];
		X->child[i]->child[j]=S->chld[j];
	}
		X->child[i]->child[j]=S->chld[j];
	for(j+=1,l=0;j<2*d+1;j++,l++)
	{
			X->child[i+1]->data[l]=S->data[j];
			X->child[i+1]->child[l]=S->chld[j];
	}
			X->child[i+1]->child[l]=S->chld[j];
	X->child[i]->count=d;
	X->child[i+1]->count=d;
*T1=X;
	cout<<"\nafter for loop\n";
//	cout<<*T->data[0];
//		cout<<"\n in splitnconnect, level order is\n";
//		levelorder(X);
	cout<<"\nend of spncn... parents are "<<*T1->data[0]<<" "<<*T1->data[1]<<endl;
	cout<<"\n its child are "<<*T1->child[0]->data[0]<<*T1->child[0]->data[1]<<"   "<<*T1->child[1]->data[0]<<*T1->child[1]->data[1]<<endl;
levelorder(*T1);
*T=X;
}

void add(bnode **&T,int k,int tag)
{
	int i;
	if(tag==1)
	{
		if(*T==NULL)
		{
			*T=new bnode;
			*T->data[0]=k;
			*T->count=1;
			for(i=0;i<=2*d+1;i++)
			{
				*T->child[i]=NULL;
			}
		}
		else
		{
			if(*T->child[0]==NULL)
			{
				if(*T->count!=2*d)
				{
					insertnsort(T,k);
//					cout<<*T->data[1];
				}
				else
				{
					splitnconnect(*T,k);
					cout<<"\nafter spncn... parents are "<<*T->data[0]<<" "<<*T->data[1]<<endl;
				}
			}
			else
			{
				for(i=0;i<*T->count;i++)
				{
					if(k<*T->data [i])
					{
						if(*T->child[i]!=NULL)
							s.push(*T);
						cout<<"\npushed node is "<<s.top()->data[0];
						add(*T->child[i],k,1);
						break;
					}
					else
					{
						if(k>*T->data[i]&&k<*T->data[i+1])
						{
						if(*T->child[i]!=NULL)
							s.push(*T);
						cout<<"\npushed node is "<<s.top()->data[0];
						add(*T->child[i+1],k,1);
						break;
						}
					}
				}
			}
		}
	}
	else
	{
		if(*T==NULL)
		{
			*T=new bnode;
			*T->data[0]=k;
			*T->count=1;
			for(i=0;i<=2*d+1;i++)
			{
				*T->child[i]=NULL;
			}
		}
		else
		{
				if(*T->count!=2*d)
				{
					insertnsort(*T,k);
//					cout<<*T->data[1];
				}
				else
				{
					splitnconnect(*T,k);
					cout<<"\nafter spncn "<<*T->data[0]<<endl;
				}
		}
	}
}
void create(bnode **&T)
{
	int k;
	while(k!=-99)
	{
		cout<<"enter the numbers\n(-99 to terminate)\n";
		cin>>k;
		if(k!=-99)
		{
			X=NULL;
			add(T,k,1);
			cout<<endl;
			levelorder(*T);
			while(!s.empty())
			{
				s.pop();
				cout<<"\nstack is flushed\n";				
			}
		}
	}
}

//void levelorder(bnode *T)
//{
//	int i;
//	if(T!=NULL)
//	{
//		for(i=0;i<T->count;i++)
//		{
//			cout<<T->data[i]<<" ";
//		}
//		cout<<"    ";
//		for(i=0;i<=T->count;i++)
//		{
//			levelorder(T->child[i]);
//		}
//	}
//}

void levelorder(bnode *T)
{
	int i;
	bnode *temp,*P;
	temp=new bnode;
	for(i=0;i<2*d;i++)
	{
		temp->data[i]=-99;
		temp->child[i]=NULL;
	}
	temp->child[i]=NULL;
	q.push(T);
	q.push(temp);

	
	while(!q.empty())
	{
		P=q.front();
		q.pop();
		if(q.empty())
		{
			break;
		}
		if(P->data[0]!=-99)
		{
			z++;
			if(z==30)
				return;
//			cout<<"\ncount is "<<P->count<<endl;
			for(i=0;i<P->count;i++)
			{
				cout<<P->data[i]<<" ";
				if(P->child[i]!=NULL)
				{
					q.push(P->child[i]);
				}
			}
			cout<<"    ";
			if(P->child[i]!=NULL)
			{
				q.push(P->child[i]);
			}
		}
		else
		{
			cout<<endl;
			q.push(temp);
		}	
	}
}

void inorder(bnode *T)
{
	static int i=0;
	if(T!=NULL)
	{
		while(i<T->count)
		{
			inorder(T->child[i]);
			cout<<T->data[i]<<" ";
			i++;
		}
			inorder(T->child[i]);
	}
}


int main()
{
	bnode *T=NULL;
	create(&T);
	cout<<"\nI'm out of create\n";
//	cout<<T->data[1]<<" "<<" "<<T->child[0]->data[0];
	levelorder(T);
//	inorder(T);
	if(T->child[0]==NULL)
	cout<<"\nI screwed up here\n";
//	cout<<T->child[0]->data[0];
	return 0;
}
