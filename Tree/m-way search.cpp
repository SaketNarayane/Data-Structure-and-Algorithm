#include<iostream>
using namespace std;
const int m=6;
struct mstnode
{

    int q[m];
    mstnode *mptr[m+1];

};

mstnode* create(mstnode* T,int k)
{
	mstnode * temp;
    if(T==NULL)
    {

        temp=new mstnode;
        for(int j=0;j<m;j++)
        {
            temp->q[j]=k;
        temp->mptr[j]=NULL;

        }
        temp->mptr[m+1]=NULL;
        return temp;
    }
    else
    {
        for(int i=0;i<m;i++)
        {
            if(k<T->q[i])
           T->mptr[i]= create(T->mptr[i],k);
        else if((k>T->q[i])&&k<T->q[i+1])
           T->mptr[i+1]= create(T->mptr[i+1],k);

		}
            if(k>T->q[m])
                T->mptr[m+1]= create(T->mptr[m+1],k);

		return T;

    }

}

int Search(mstnode*T,int k)
{

     	if(T!=NULL)
 	{
 	    for(int i=0;i<m;i++)
        {

 		if(k==T->q[i])
 		return 1;
 		else if(k<T->q[i])
 		Search(T->mptr[i],k);
 		else if(k>T->q[i]&&k<T->q[i+1])
 		Search(T->mptr[i+1],k);
        }
        if(k>T->q[m])
        Search(T->mptr[m+1],k);
 	}
 	else
 	return 0;

}

int main()
{

int a;
cout<<"Enter the order of search ";
    cin>>a;
mstnode*root;
root=NULL;
int n;

char ch='y';
while(ch=='y')
{

for(int i=0;i<a;i++)
{
cout<<"Enter the values ";
 cin>>n;
root=create(root,n);
cout<<"MORE(y/n)? ";
cin>>ch;
}
}
int h;
cout<<"\nEnter no to be searched ";
cin>>h;
int t=Search(root,h);
if(t==1)
    cout<<"FOUND ";
else
    cout<<"NOT FOUND ";

return 0;

}
