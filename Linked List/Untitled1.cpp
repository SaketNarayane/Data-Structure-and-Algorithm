#include<iostream>
using namespace std;
union us
{
	char cn[10];
	int rn;
};
struct F
{
	int tag;
	us type;
	F* next;
	F* down;
	F()
	{
		next=NULL;
		down=NULL;
	}
};
	F* shead;
	F* chead;
void showC()
{
	F* citr=chead;
	F* n,*d,*sn;
	while(citr!=NULL)
	{
		d=citr;
		cout<<"\ncourse name ''"<<citr->type.cn<<"'' and students who registered it are\n"<<endl;
		while(d->down->tag!=1)
		{
			sn=d->down;
			while(sn->tag!=2)
			sn=sn->next;
			cout<<sn->type.rn<<endl;
			d=d->down;
		}
		citr=citr->next;
    }
}
void showS()
{
	F* sitr=shead;
	F* n,*d,*cd;
	while(sitr!=NULL)
	{
		n=sitr;
		cout<<"\nRegistered course of "<<sitr->type.rn<<endl;
		while(n->next->tag!=2)
		{
			cd=n->next->down;
			while(cd->tag!=1)
			cd=cd->down;
			cout<<cd->type.cn<<endl;
			n=n->next;
		}
		sitr=sitr->down;
	}
}
void student()
{
	F* citr=chead;
	int i=0;
	while(citr!=NULL)
	{
		cout<<i+1<<"."<<citr->type.cn<<endl;
		i++;citr=citr->next;
	}
	int r,j[i],n,k,m,f=0;char ch;F *ritr,*stud;
	do
	{
		cout<<"enter student roll no\t\t";
		cin>>r;
		cout<<"HOw many courses u want to register\t\t";
		cin>>n;
		cout<<"enter the course numbers one by one which u want to register:\n";
		for(k=0;k<n;k++)
		{
			cin>>j[k];
		}
	    for(m=0;m<n;m++)
	    {
	    	for(k=0;k<n-m-1;k++)
	    	{
	    		if(j[k]>j[k+1])
				{
					j[k]=j[k]+j[k+1];
					j[k+1]=j[k]-j[k+1];
					j[k]=j[k]-j[k+1];
				}
	    	}
	    }
	    F* t=new F;
	    	t->tag=2;
	    	t->type.rn=r;
	    	t->next=NULL;
	    	t->down=NULL;
	    	
	   citr=chead;m=1;
	    if(f==0)
	    {
	    	shead=t;
	    	f=1;
	    	ritr=t;
	    	stud=t;
	    }
	    else
	    {
	    	stud->down=t;
	    	stud=t;
	    }
	    k=0;ritr=stud;
	    	while(citr!=NULL&&k<n)
	    	{
	    		if(m==j[k])
	    		{
	    			F* rr=new F;
	    			rr->tag=3;
	    			rr->next=NULL;
	    			rr->down=NULL;
	    			if(citr->down==NULL)
	    			citr->down=rr;
	    			else
	    			{
	    				F* cour=citr;
	    				while(cour->down!=NULL)
	    				{
	    					cour=cour->down;
	    				}
	    				cour->down=rr;
	    			}
	    			ritr->next=rr;
	    			k++;
	    			ritr=rr;
	    		}
	    		m++;citr=citr->next;
	    	}
	    	ritr->next=stud;
	    	cout<<"exit y or n";
	    	cin>>ch;
	    }while(ch=='n'||ch=='N');
	    citr=chead;
	    while(citr!=NULL)
	    {
	    	ritr=citr;
	    	while(ritr->down!=NULL)
	    	ritr=ritr->down;
	    	ritr->down=citr;
	    	citr=citr->next;
	    }
}
void courses()
{
	int n;
	cout<<"How many courses:";
	cin>>n;
	F* T=new F;
	T->tag=1;
	cout<<"enter course name\n";
	cin>>T->type.cn;
	T->next=NULL;
	T->down=NULL;
	chead=T;
	F* itr=T;
	for (int i=1;i<n;i++)
	{
			F* T=new F;
	T->tag=1;
	cout<<"enter course name\n";
	cin>>T->type.cn;
	T->next=NULL;
	T->down=NULL;
	itr->next=T;
	itr=T;
	}
}
int main()
{
	courses();
	student();
	showS();
	showC();
	return 0;
}
