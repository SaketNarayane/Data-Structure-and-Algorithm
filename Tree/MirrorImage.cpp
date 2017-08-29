#include<iostream>
using namespace std;
struct bnode
{
	int data;
	bnode *left;
	bnode *right;
};
class btree
{
		bnode *tree;
		int count;
		bnode *gettree(bnode *,int);
		bnode *mirror(bnode *);
		void inordertrav(bnode *);
	public:
		void insert(int);
		void inorder();
		void mirrori();
		btree()
		{
			int count=0;
			tree=NULL;
		}
};

void btree::insert(int x)
{
	tree=gettree(tree,x);
}
void btree::inorder()
{
	inordertrav(tree);
}

void btree::mirrori()
{
	tree=mirror(tree);
}

bnode *btree::gettree(bnode *tree,int x)
{
	if(tree==NULL)
	{
		tree=new bnode;
		tree->left=tree->right=NULL;
		tree->data=x;
		count++;
	}
	else
		if(count%2==1)
			tree->left=gettree(tree->left,x);
		else
			tree->right=gettree(tree->right,x);
		return(tree);
}

void btree::inordertrav(bnode *tree)
{
	if(tree!=NULL)
	{
		inordertrav(tree->left);
		cout<<endl<<tree->data;
		inordertrav(tree->right);
	}
}

bnode * btree::mirror(bnode *tree)
{
	bnode *temp;
  if(tree==NULL)
  {
    return NULL;
  }
  else
  {
    temp=tree->left;
    tree->left=mirror(tree->right);
    tree->right=mirror(temp);
    return (tree);
  }
}

int main()
{
	btree T;
	int data,i;
	for(i=0;i<7;i++)
	{
		cout<<"enter data\n";
		cin>>data;
		T.insert(data);
	}
	cout<<"\ninorder traversing :\n";
	T.inorder();
	T.mirrori();
	cout<<"\nthe mirror image is :\n";
	T.inorder();
	
	return 0;
}
