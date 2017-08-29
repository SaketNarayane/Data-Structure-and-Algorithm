#include<iostream>
#include<stack>

using namespace std;
stack<int>s;
struct vertex
{
	int visited=0;
};

struct numbering
{
	int c;
};

int n;

void DFT(int **M,vertex V[],int i)
{
	int j;
	V[i].visited=1;
	for(j=1;j<n+1;j++)
	{
		if(M[i][j]>0)
		{
			if(V[j].visited==0)
			{
				q.push(j);
				DFT(M,V,j);
			}
		
		}
	}
}

int retmaxunvis(vertex V[],numbering C[])
{
	int i,max,f=0;
	for(i=1;i<n+1;i++)
	{
		if(V[i].visited==0)
		{
			if(!f)
			{
				max=C[i].c;
				f=1;
			}
			else
			{
				if(C[i].c>max)
				{
					max=C[i].c;
				}
			}
		}
	}
	return max;
}

int main()
{
	vertex *V;
	numbering *C;
	int **M,**R,i,j,w,k=1;
	cout<<"\n enter the number of vertices\n";
	cin>>n;
	M=new int*[n+1];
	R=new int*[n+1];
	V=new vertex[n+1];
	C=new numbering[n+1];
	for(i=0;i<=n+1;i++)
	{
		M[i]=new int[n+1];
		R[i]=new int[n+1];
	}
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			M[i][j]=0;
			R[i][j]=0;
		}
	}

	for(i=1;i<n+1;i++)
	{
		j=0;
		while(j!=-99)
		{
			cout<<"\nenter connections of "<<i<<" (-99 to terminate)\n";
			cin>>j;
			if(j!=-99)
			{
//				cin>>w;
				M[i][j]=1;
				R[j][i]=1;
			}
		}
//		cout<<i<<endl;
	}
	j=0;
	for(i=1;i<n+1;i++)
	{
		M[i][j]=i;
		M[j][i]=i;
	}
	M[0][0]=0;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<n+1;j++)
		{
			cout<<M[i][j]<<" ";
		}
		cout<<endl;
	}
	
	while(k!=n+1)
	{
		s.push(k);
		DFT(M,V,k);
		while(!s.empty())
		{
			C[k].c=s.top();
			s.pop();
			k++;
		}
	}
	
	for(i=1;i<n+1;i++)
	{
		V[i].visited=0;
	}
	
	for(i=1;i<n+1;i++)
	{
		cout<<i<<" "<<C[i].c<<endl;
	}
	k=n;
	while(k!=0)
	{
//		
//		for(i=1;i<n+1;i++)
//		{
//			if(C[i].c==k)
//			{
//				break;
//			}
//		}
		i=retmaxunvis(V,C);
		s.push(i);
		DFT(R,V,i);
		cout<<"{ ";
		while(!s.empty())
		{
			cout<<s.top()<<" ";
			s.pop();
			k--;
		}
		cout<<" }"<<endl;
	}
	
	
	
	return 0;
}
