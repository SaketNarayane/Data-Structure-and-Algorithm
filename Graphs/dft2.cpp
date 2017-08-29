#include<iostream>
using namespace std;

void DFT(int a)
{
	if(l[a]->next!=NULL)
	{
		if(V[l[a]->data]->vis==0)
		{
			cout<<(l[a]->data);
			V[l[a]->data]->vis=1;
			count
		}
		if(V[l[a]->data]->next->vis==0)
		DFT(l[a]->next->data);
		l[a]=l[a]->next;
	}
}
