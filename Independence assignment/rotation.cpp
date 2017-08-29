#include<iostream>
#include<cstring>
using namespace std;
struct lnode
{
	char data;
	lnode *next;
};
lnode *H;
void addend(lnode *L,char k)
{
	L=H;
	if(H==NULL)
	{
		L=new lnode;
		L->data=k;
		H=L;
	}
	else
	{
		while(L->next==NULL)
		{
			L=L->next;
		}
		L=new lnode;
		L->data=k;
		L->next=NULL;
	}
}

void create(lnode *L)
{
	char a[10];
	int i=0;
	L=H;
	cout<<"enter the original order\n";
	gets(a);
	while(a[i]!='\0')
	{
		addend(L,a[i]);
	}
	while(L->next!=NULL)
	{
		L=L->next;
	}
	L->next=H;
}

int chkeq(lnode *L,char *t,int rot)
{
	L=H;
	int l,i=rot,f=1;
	while(L->next!=H)
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
	L=H;
	char t[10];
	int l,rot=0,f;
	cout<<"enter the rotated string\n";
	gets(t);
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
	int f;
	create(L);
	f=chkrot(L);
	if(f==-1)
	{
		cout<<"it is not rotated order\n";
	}
	else
	{
		cout<<"we will get original sequence from rotated order by rotating it by ->  "<<f<<"  positions";
	}
	return 0;
}
