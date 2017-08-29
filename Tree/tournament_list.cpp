#include<iostream>
using namespace std;
struct lnode
{
    int num;
    lnode * next;
};
struct tnode
{
    lnode * data;
    tnode * lchild;
    tnode * rchild;
};
struct node
{
    tnode * data;
    node * next;
};
class queue
{
    public:
    node * head;
    lnode * head1;
    int is_empty()
    {
        if(head==NULL)
            return 1;
        else
            return 0;
    }
    void push( tnode * );
     tnode * pop();
     void push(int);
     //void popint(lnode * &);
    queue()
    {
        head=new node;
        head=NULL;
        head1=new lnode;
        head1=NULL;
    }
};
void queue::push(tnode * k)
{
    node * T;
    T=new node;
    T->data=k;
    T->next=this->head;
    this->head=T;
}
void queue::push(int k)
{
    lnode * T;
    T=new lnode;
    T->num=k;
    T->next=this->head1;
    this->head1=T;
}
tnode * queue::pop()
{   if(is_empty())
{   cout<<"underflow";
    return NULL;}
    else
    { tnode * temp;
    temp=new tnode;
    node * T=new node;
    T=this->head;
    temp=this->head->data;
    this->head=this->head->next;
    delete T;
    return temp;
    }
}
void popint(lnode * & T)
{
    if(T->next==NULL)
        T->num=INT_MAX;
    else
    {
        T=T->next;
    }
}
class tournament
{
    tnode * root;
    int call;
    int is_leaf(tnode *);
    int remove(tnode *,int);
    void insert(queue&,lnode * & );
    tnode * create(lnode * &);
    lnode *  torsort(tnode *);
    void inorder(tnode *);
public:
    tournament()
    {
        root=new tnode;
        call=0;
    }
    void interface();
};
tnode * tournament::create(lnode * & a)
{
    tnode * T;
    T=new tnode;
    T->lchild=NULL;
    T->rchild=NULL;
        T->data=a;
        return T;
}
void tournament::insert(queue & Q,lnode * &a)
{tnode *T,*L,*R,*Y,*Z;
T=new tnode;
L=new tnode;
R=new tnode;
Z=new tnode;
     call++;
     T=create(a);
     Q.push(T);
     if(call%2==0)
     {
         L=Q.pop();
         R=Q.pop();
         Y=new tnode;
         Y->lchild=L;
         Y->rchild=R;
         Q.push(Y);
         if(call>2)
         {
             L=Q.pop();
             R=Q.pop();
             Z->lchild=L;
             Z->rchild=R;
             root=Z;
             Q.push(Z);
         }
     }
}
int tournament::is_leaf(tnode * T)
{
 if((T->lchild)==NULL&&(T->rchild==NULL))
        return 1;
 else
    return 0;
}
lnode * tournament::torsort(tnode * T)
{ lnode * num1,*num2;
num1=new lnode;
num2=new lnode;
   if((is_leaf(T->lchild))&&(is_leaf(T->rchild)))
   {
       if(((T->lchild->data)->num)>=(T->rchild->data->num))
        return (T->rchild->data);
       else
       return  T->lchild->data;
   }
   else
   {
    num1=torsort(T->lchild);
   num2=torsort(T->rchild);
   if((num1->num)>=(num2->num))
    T->data=num2;
   else
    T->data=num1;
   }
   return T->data;
}
int tournament::remove(tnode * T,int num1)
{
    if(T==NULL)
    {
    return 0;
    }
    if(is_leaf(T))
    {
        if(T->data->num==num1)
      {
          popint(T->data);
      return 1;}
      else
        return 0;
    }
    else
    {if(remove(T->lchild,num1))
    return 1;
    else if(remove(T->rchild,num1))
        return 1;
    }
}
/*void tournament::inorder(tnode * T)
{
    if(T==NULL)
        { return ;
        }
    else
    {
        inorder(T->lchild);
        cout<<T->data<<"   ";
        inorder(T->rchild);
    }
}*/
void tournament::interface()
{queue Q; int a,i=0,b;
cout<<"how many linklist u want";
cin>>b;
queue *Q1;
lnode * am;
am=new lnode;
if(b%2==1)
Q1=new queue[b+1];
else
Q1=new queue[b];
while(i<b)
    {cout<<"\n entet ll"<<i+1;
        while(1)
    {cout<<"enter the number";
    cin>>a;
    if(a==0)
        break;
    else
    {
        Q1[i].push(a);
    }
    }
    insert(Q,Q1[i].head1);
    i++;
    }
    if(i%2==1)
    {
        Q1[i].push(INT_MAX);
        insert(Q,Q1[i].head1);
    }
    tnode * T;
    T=new  tnode;
    T=Q.pop();
    root=T;
    cout<<"done";
    cout<<endl;
    while(1)
    {
        am=torsort(T);
        if(am->num==INT_MAX)
            break;
        else
            { cout<<am->num<<"  ";
             remove(root,am->num);
            }
    }
}
int main()
{
    tournament U;
    U.interface();
    return 0;
}
