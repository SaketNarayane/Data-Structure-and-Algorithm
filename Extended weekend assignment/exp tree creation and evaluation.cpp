#include<iostream>
#include<cstdlib>
#include<cctype>
#include<stdlib.h>
using namespace std;

struct etnode
{
	etnode*lchild;

	char data;
		etnode*rchild;
};

class stack
{
	etnode* item[50];
	public:
		void push(etnode*);
		int top;
		etnode* pop();
		int empty();
		int full();
		stack()
		{
			top=-1;
		}
};

int stack::full()
{
	if(top==49)
	return 1;
	else
	return 0;
}
int stack::empty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
void stack::push(etnode*T)
{
     if(!full())
	   item[++top]=T;
	   else
	   cout<<"Stack Overflow........\n";
}
etnode* stack::pop()
{
	int s;
	if(empty())
	NULL;
	else
	{
	return item [top--];
	}
}


etnode *create(char a,stack s)
{
    etnode*T;
    T=new etnode;
        T->data=a;
    if (isdigit(a))
        s.push(T);
    //T=new etnode;
    //T->data=a;
    else
    {
       // etnode*T=new etnode;
        //T->data=a;
        if(!s.empty())
        {
            T->rchild=new etnode;
            etnode*p=s.pop();
            T->rchild->data=p->data;
        }

        if(!s.empty())
        {
            T->lchild=new etnode;
            etnode*p=s.pop();
            T->lchild->data=p->data;
        }
        s.push(T);
    }

    return T;

}


float evaluate(etnode*T)
{
    float t1,t2;
    if(T!=NULL)
    {
        if(isdigit(T->data))
            return (T->data-48);
        else
        {

            t1=evaluate(T->lchild);

            t2=evaluate(T->rchild);
        }
    }

    switch(T->data)
    {
    case '+':
        return t1+t2;
        break;
    case'-':
        return t1-t2;
        break;
    case'*':
        return t1*t2;
        break;
    case'/':
        return t1/t2;
        break;
    }

}

int main()
{
    stack s;
    cout<<"Enter postfix expression ";
    char a[10];
    cin>>a;
    etnode *root;
    root=NULL;
    for(int i=0;i<10;i++)
    root=create(a[i],s);

    float ans;
    ans=evaluate(root);
    cout<<"Answer is \n";
    cout<<ans;
    return 0;

}

