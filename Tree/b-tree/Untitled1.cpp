#include<iostream>
using namespace std;
struct node
{
	int data;
};
int main()
{
	node **T=new node *;
	(*T)->data=1;
	cout<<(*T)->data;
	return 0;
}






