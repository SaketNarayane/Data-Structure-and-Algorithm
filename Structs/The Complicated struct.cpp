#include<iostream>
using namespace std;
union studdata
{
	char coursename[10];
	int rollno;
};
struct field
{
	int tag;
	studdata type;
	field* next;
	field* down;
	field()
	{
		next=NULL;
		down=NULL;
	}
};
	field* HS;
	field* HC;
void printcourse()
{
	field* citr=HC;
	field* n,*d,*sn;
	while(citr!=NULL)
	{
		d=citr;
		cout<<"\ncourse name ''"<<citr->type.coursename<<"'' and students who registered it are\n"<<endl;
		while(d->down->tag!=1)
		{
			sn=d->down;
			while(sn->tag!=2)
			sn=sn->next;
			cout<<sn->type.rollno<<endl;
			d=d->down;
		}
		citr=citr->next;
    }
}
void showS()
{
	field* sitr=HS;
	field* n,*d,*cd;
	while(sitr!=NULL)
	{
		n=sitr;
		cout<<"\nRegistered course of "<<sitr->type.rollno<<endl;
		while(n->next->tag!=2)
		{
			cd=n->next->down;
			while(cd->tag!=1)
			cd=cd->down;
			cout<<cd->type.coursename<<endl;
			n=n->next;
		}
		sitr=sitr->down;
	}
}
void student()
{
	field* citr=HC;
	int i=0;
	while(citr!=NULL)
	{
		cout<<i+1<<"."<<citr->type.coursename<<endl;
		i++;citr=citr->next;
	}
	int r,j[i],n,k,m,f=0;char ch;field *ritr,*stud;
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
	    field* t=new field;
	    	t->tag=2;
	    	t->type.rollno=r;
	    	t->next=NULL;
	    	t->down=NULL;
	    	
	   citr=HC;m=1;
	    if(f==0)
	    {
	    	HS=t;
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
	    			field* rr=new field;
	    			rr->tag=3;
	    			rr->next=NULL;
	    			rr->down=NULL;
	    			if(citr->down==NULL)
	    			citr->down=rr;
	    			else
	    			{
	    				field* cour=citr;
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
	    citr=HC;
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
	field* T=new field;
	T->tag=1;
	cout<<"enter course name\n";
	cin>>T->type.coursename;
	T->next=NULL;
	T->down=NULL;
	HC=T;
	field* itr=T;
	for (int i=1;i<n;i++)
	{
			field* T=new field;
	T->tag=1;
	cout<<"enter course name\n";
	cin>>T->type.coursename;
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
	printcourse();
	return 0;
}
