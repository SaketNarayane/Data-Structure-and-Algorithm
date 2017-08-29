#include<iostream>
using namespace std;

struct bstnode
{
bstnode*lchild;
int data;
bstnode*rchild;

};

typedef bstnode* bstptr;

bstnode* create(bstptr T,int k)
{
	bstnode * temp;
    if(T==NULL)
    {
        temp=new bstnode;
        temp->data=k;
        temp->lchild=NULL;
        temp->rchild=NULL;
        return temp;
    }
    else
    {

        if(k<T->data)
           T->lchild= create(T->lchild,k);
        else
           T->rchild= create(T->rchild,k);
		return T;

    }

}


 int height(bstnode*T)
 {

   if (T == NULL)
   {
      return 0;
   }

   int left = height(T->lchild);
   int right = height(T->rchild);
   return 1 + max(left, right);
 }


 int nodes(bstnode*T)
 {
     if(T==NULL)
        return 0;
    return 1 + nodes(T->lchild) + nodes(T->rchild);

 }


/*void postorder(bstnode*T,int space)
{
   // int space=0;
    if(T != NULL) {
        if(T->lchild) postorder(T->lchild, space+4);
        if(T->rchild) postorder(T->rchild, space+4);
        if (space) {
            cout <<setw(space) << ' ';
        }
        cout<< T->data << "\n ";
    }
}*/

void printGivenLevel(struct bstnode* root, int level)
{
 // if(root == NULL)
   // return;
    if(level==0)
    return;
    
  if(level == 1)
  {
  //  int n=nodes(root);
    //for(int i=0;i<n;i++)
    //cout<<" ";
    cout<< root->data<<" ";

  }
  else if (level > 1)
  {

    printGivenLevel(root->lchild, level-1);
   //  int t=nodes(root)+nodes(root->lchild);
     //for(int i=0;i<t;i++)
    //cout<<" ";
    printGivenLevel(root->rchild, level-1);

  }

}

void printLevelOrder(struct bstnode* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        cout<<endl;
    }
}

int main()
{

    int n;
 	bstptr root;
    root=NULL;

    char ch='y';
    while(ch=='y')
    {
        cout<<"Enter value in the node of tree\n";
        cin>>n;
        root=create(root,n);
        cout<<"\nWant to add more?(y/n)\n";
        cin>>ch;
    }


int h=height(root);
int x=nodes(root);
printLevelOrder(root);
//int s=0;
//postorder(root,s);
//print(root,h,x);

    return 0;
}

