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

bnode * add(bnode*T,int k,int tag);

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


bnode * insertnsort(bnode *T3,int k)
{
	int i,j;
	if(k>T3->data[T3->count-1])
	{
		T3->data[T3->count]=k;
		T3->count++;
	}
	else
	{
		for(i=T3->count-1;i>=0;i--)
		{
			if(k<T3->data[i])
			{
				T3->data[i+1]=T3->data[i];
				T3->child[i+2]=T3->child[i+1];
			}
			else
			{
				T3->data[i+1]=k;
				T3->child[i+2]=NULL;
				T3->count++;
				break;
			}
		}
		if(i<0)
		{
			T3->data[i+1]=k;
			T3->count++;
			T3->child[i+2]=NULL;
		}
//		cout<<"\n in insertnsort level order\n";
//		levelorder(T3);
	}
return T3;
}

bnode* splitnconnect(bnode *T4,int k)
{
//	z++;
//	if(z==6)
//		return;
	bnode *T1;
	cout<<"\n I'm in splitnconnect\n";
	int parent,i,j,l,flag=0;
	bnode *temp;
	if(k<T4->data[d-1])
	{
		parent=T4->data[d-1];

		T4->data[d-1]=k;
	}
	else
	{
		if(k>T4->data[d])
		{
			parent=T4->data[d];
			T4->data[d]=k;
		}
		else
		{
			parent=k;
		}
	}

//	cout<<"after splitting, parent is "<<parent<<endl;
		if(!s.empty())
		{
			X=s.top();
			s.pop();
			cout<<"X value is "<<X->data[0];
		}

		X=add(X,parent,0);
		i=returnpos(X,parent);
		cout<<"\n position of parent is "<<i;
//	cout<<"\n X is "<<X->data[0]<<endl;
//	cout<<T4->data[0];

//	if(X->count==1)
//	cout<<T4->data[0]<<T4->data[1];
//	cout<<" "<<X->data[0]<<X->data[1];
		X->child[i]=T4;
//	else
//	{
//				cout<<"\n in splitnconnect, level order is\n";
//		levelorder(T4);
//
//	}
	X->child[i+1]=new bnode;
//	cout<<"\n before for loop\n";
	for( j=d, l=0;j<2*d;j++,l++)
	{
		X->child[i+1]->data[l]=X->child[i]->data[j];
	}
		
	X->child[i]->count=d;
	X->child[i+1]->count=d;
T4=X;
//	cout<<"\nafter for loop\n";
//	cout<<T4->data[0];
//		cout<<"\n in splitnconnect, level order is\n";
//		levelorder(X);
	cout<<"\nend of spncn... parents are "<<T4->data[0]<<" "<<T4->data[1]<<endl;
	cout<<"\n its child are "<<T4->child[0]->data[0]<<T4->child[0]->data[1]<<"   "<<T4->child[1]->data[0]<<T4->child[1]->data[1]<<endl;
	return T4;
}

bnode * add(bnode *T2,int k,int tag)
{
	int i;
	if(tag==1)
	{
		if(T2==NULL)
		{
			T2=new bnode;
			T2->data[0]=k;
			T2->count=1;
			for(i=0;i<=2*d+1;i++)
			{
				T2->child[i]=NULL;
			}
		}
		else
		{
			if(T2->child[0]==NULL)
			{
				if(T2->count!=2*d)
				{
					T2=insertnsort(T2,k);
//					cout<<T2->data[1];
				}
				else
				{
					T2=splitnconnect(T2,k);
					levelorder(T2);
					cout<<"\nafter spncn... parents are "<<T2->data[0]<<" "<<T2->data[1]<<endl;
	cout<<"\n its child are "<<T2->child[0]->data[0]<<T2->child[0]->data[1]<<"   "<<T2->child[1]->data[0]<<T2->child[1]->data[1]<<endl;
				}
			}
			else
			{
				for(i=0;i<T2->count;i++)
				{
					if(k<T2->data [i])
					{
						if(T2->child[i]!=NULL)
							s.push(T2);
						cout<<"\npushed node is "<<s.top()->data[0];
						T2->child[i]=add(T2->child[i],k,1);
						break;
					}
					else
					{
						if(k>T2->data[i]&&k<T2->data[i+1])
						{
						if(T2->child[i]!=NULL)
							s.push(T2);
						cout<<"\npushed node is "<<s.top()->data[0];
						T2->child[i+1]=add(T2->child[i+1],k,1);
						break;
						}
					}
				}
			}
		}
	}
	else
	{
		if(T2==NULL)
		{
			T2=new bnode;
			T2->data[0]=k;
			T2->count=1;
			for(i=0;i<=2*d+1;i++)
			{
				T2->child[i]=NULL;
			}
		}
		else
		{
				if(T2->count!=2*d)
				{
					T2=insertnsort(T2,k);
//					cout<<T2->data[1];
				}
				else
				{
					T2=splitnconnect(T2,k);
//					levelorder(T2);
//					cout<<"\nafter spncn "<<T2->data[0]<<endl;
				}
		}
	}
	return T2;
}
bnode * create(bnode *T1)
{
	int k;
//	bnode *T1;
//	T1=T;
	while(k!=-99)
	{
		cout<<"enter the numbers\n(-99 to terminate)\n";
		cin>>k;
		if(k!=-99)
		{
			X=NULL;
			T1=add(T1,k,1);
			cout<<"\nin create"<<endl;
			levelorder(T1);
			while(!s.empty())
			{
				s.pop();
				cout<<"\nstack is flushed\n";				
			}
		}
	}
	return T1;
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
			if(z==25)
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
//	bnode *T1;
	T=create(T);
	cout<<"\nI'm out of create\n";
//	cout<<T->data[1]<<" "<<" "<<T->child[0]->data[0];
	levelorder(T);
//	inorder(T);
	if(T->child[0]==NULL)
	cout<<"\nI screwed up here\n";
//	cout<<T->child[0]->data[0];
	return 0;
}
