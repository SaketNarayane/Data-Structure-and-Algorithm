#include<iostream>
using namespace std;

int *S,n;

int find(int i)
{
	if(S[i]<=0)
	{
		return i;
	}
	else
	{
		return (find(S[i]));
	}
}

void uniun(int x,int y)
{
	if(S[y]<=0&&S[x]<=0)
	{
		if(S[y]==S[x])
		{
			S[y]=x;
		}
		else
		{
			if(S[x]<S[y])
			{
				S[y]=x;
			}
			else
			{
				S[x]=y;
			}
		}
	}
	else
	{
		if(S[x]<=0)
		{
			S[x]=y;
		}
		else
		{
			uniun(S[x],y);
		}
	}
	S[(find(x))]=-1;
}

void display(int a[])
{
	int i;
	cout<<endl;
	for(i=1;i<=n;i++)
	{
		cout<<i<<" -> "<<a[i]<<endl;
	}
}

int main()
{
	int i,x=0,y;
	cout<<"\n how many elements?\n";
	cin>>n;
	S=new int[n+1];
	for(i=1;i<=n;i++)
	{
		S[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		cout<<"\nenter x and y\n-99 to break\n";
		if(x!=-99)
		{
			cin>>x;
			cin>>y;
			uniun(x,y);	
		}
		
		else
		{
			break;
		}
		display(S);
	}
	return 0;
}
