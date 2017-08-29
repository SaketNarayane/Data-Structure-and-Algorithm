#include<iostream>
#include<queue>
using namespace std;
struct vertex
{
	int visited=0;
	int indegree=0;
	int outdegree=0;
};

queue<int>q,q1;

int n,s;

void DFT(int **M,vertex V[],int i)
{
	int j;
	V[i].visited=1;
	V[i].indegree--;
	for(j=1;j<n+1;j++)
	{
		if(M[i][j]>0)
		{
			if(V[j].outdegree==0)
			{
				q.push(j);
				V[i].outdegree--;
				DFT(M,V,j);
			}
		}
	}
}




int main()
{
	int **M,i,j,s;
	cout<<"\n enter the number of vertices\n";
	cin>>n;
	M=new int*[n+1];
	for(i=0;i<=n+1;i++)
	{
		M[i]=new int[n+1];
	}
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			M[i][j]=0;
		}
	}

	for(i=1;i<n+1;i++)
	{
		j=0;
		while(j!=-99)
		{
			cout<<"\nenter connections of "<<i<<" with a vertex (-99 to terminate)\n";
			cin>>j;
			if(j!=-99)
			{
//				cin>>w;
				M[i][j]=1;
				V[i].outdegree++;
				V[j].indegree++;
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
	return 0;
}
