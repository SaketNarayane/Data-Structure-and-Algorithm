#include<iostream>
#include<cstring>
using namespace std;
struct lnode
{
	char data;
	lnode *next;
};
lnode *H;
void print(lnode *L)
{
	while(L!=NULL)
	{
		cout<<L->data;
		L=L->next;
	}
}
void addend(lnode *L,char k)
{
		while(L->next!=NULL)
		{
			L=L->next;
		}
		lnode *T;
		T=new lnode;
		T->data=k;
		T->next=NULL;
		L->next=T;
		
}

void create(lnode *L)
{
	char a[10];
	int i=1;
	cout<<"enter the original order\n";
	cin.getline(a,10);
	L->data=a[0];
	while(a[i]!='\0')
	{
		addend(L,a[i]);
		i++;
	}
	
}

int chkeq(lnode *L,char *t,int rot)
{
	int l,i=rot,f=1;
	while(L!=H)
	{
		if(L->data==t[i])
		{
			f=1;
		}
		else
		{
			f=0;
			break;
		}
		i=(i+1)%l;
		L=L->next;
	}
	return f;
	
}

int chkrot(lnode *L)
{
	char t[10];
	int l,rot=0,f;
	cout<<"enter the rotated string\n";
	cin.getline(t,10);
	l=strlen(t);
	for(rot=0;rot<l;rot++)
	{
		if(L->data==t[rot])
		{
			f=chkeq(L,t,rot);
		}
		if(f)
		{
			break;
		}
	}
	if(f)
	{
		return rot;
	}
	else
	{
		return -1;
	}
}

 

int main()
{
	lnode *L;
	L=new lnode;
	L->next=NULL;
	H=L;
	int f;
	create(L);
	f=chkrot(L);
	if(f==-1)
	{
		cout<<"it is not rotated order\n";
	}
	else
	{
		cout<<"we will get original sequence from rotated order by rotating it right by -> "<<f<<" positions";
	}	return 0;
}
