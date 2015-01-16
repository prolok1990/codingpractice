#include<iostream>
#include<queue>
#include<stack>
#include<cstdlib>
#include<cmath>
using namespace std;
class nodetree
{
public:
	int val;
	nodetree *left,*right;

	nodetree(int);
};

nodetree::nodetree(int i)
{

	val=i;
	left=NULL;
	right=NULL;
}
class tree
{
protected:
	nodetree *root;
	tree *tree1,*tree2;
	int height;
	
public:
	explicit tree();
	explicit tree(int);
	explicit tree(nodetree*);
	~tree();
	bool bfs();
	bool dfs();
	bool balanced();
	bool setheight();
	int getheight();

	bool insert(int);
	
};
class bst : public tree
{
	

public:
	
	bool insert(int);
	bool del(int);

};
int tree::getheight()
{
	return height;
}
bool tree::setheight()
{
	if ((left==NULL) &&(right==NULL))
	{

		height=1;
		return true;
	}

	else
	{

	
	tree1->setheight();
	tree2->setheight();
	height=(tree1->height>tree2->height)?(tree1->height+1):(tree2->height+1);
	return true;
	}



}
bool tree::balanced()
{
	if ((left==NULL) &&(right==NULL))
	{

		
		return true;
	}

	else
	{
		
		int h=tree1->height - tree2->height;
	
	
		
		if(tree1->balanced()&& tree2->balanced() && (abs(h)<=1) )
		{
			
			return true;
		}
		else
			return false;
	}
}
tree::tree(nodetree* r)
{
	root=r;
	height=1;
	tree1=new tree(root->right);
	tree2=new tree(root->left);

}

bool bst::del(int v)
{
	if(root==NULL)
	{
		return false;
	}
	nodetree *temp,*temp2;
	temp=root;
	
	while(temp!=NULL)
	{
		if(temp->val == v)
		{
			nodetree *temp1=temp;
			if ((temp->left==NULL) && (temp->right==NULL))
			{
				if (temp2->val>temp->val)
					temp2->left=NULL;
				if(temp2->val<temp->val)
					temp2->right=NULL;
				delete temp;
				return true;
			}
			if(temp->left==NULL)
			{
				temp2=temp;
				temp1=temp->right;
				
				while(temp1->left!=NULL)
				{
					temp2=temp1;
					temp1=temp1->left;

				}
				
				if(temp2->val<temp1->val)
					temp2->right=temp1->left;
				else
					temp2->left=temp1->left;
				temp->val=temp1->val;
				delete temp1;
				return true;
			}
			else
			{
				temp2=temp;
				temp1=temp->left;
				
				while(temp1->right!=NULL)
				{
					temp2=temp1;
					temp1=temp1->right;
				}
				
				if(temp2->val<temp1->val)
					temp2->right=temp1->left;
				else
					temp2->left=temp1->left;
				temp->val=temp1->val;
				delete temp1;
				return true;
			}

			

		}
		if (temp->val<v)
		{
			temp2=temp;
			temp=temp->right;
			
			
		}
		if (temp->val>v)
		{
			temp2=temp;
			temp=temp->left;
			
			
		}
	}
	return false; 
}
bool bst::insert(int v)
{
	if(root==NULL)
	{
		root=new nodetree(v);
		tree1=NULL;
		tree2=NULL;
		return true;
	}
	
	nodetree* temp;
	temp=root;

	while(temp!=NULL)
	{
		
		if(v > temp->val)
		{
			if(temp->right == NULL)
			{
				temp->right= new nodetree(v);
				if(temp==root)
					tree2=new true(temp->right);
				
				return true;
			}
			
				temp=temp->right;
			

		}
		else
		{
			if(temp->left == NULL)
			{
				temp->left= new nodetree(v);
				if(temp==root)
					tree2=new true(temp->right);

				return true;
			}
			temp=temp->left;
		}
	}
	return true;
}
bool tree:: bfs()
{
	if (root==NULL)
	{
		return false;
	}
	nodetree *temp;
	queue <nodetree*> s;
	temp=root;
	s.push(temp);
	cout<<endl;
	while(!s.empty())
	{
		temp=s.front();
		cout<<temp->val<<"   ";
		if (temp->left!=NULL)
			s.push(temp->left);
		if(temp->right!=NULL)
			s.push(temp->right);
		s.pop();
	}
	cout<<endl;
	return true;
}
bool dfs(nodetree *root)
{
	cout<<endl;
	if (root==NULL)
		return false;
	cout<<root->val<<" ";
	dfs(root->left);
	dfs(root->right);
	return true;
}

bool tree::dfs()
{
	if(root==NULL)
		return false;
	nodetree *temp;
	stack<nodetree*> s;
	temp=root;
	s.push(temp);
	cout<<endl;
	
	while(!s.empty())
	{
		temp=s.top();
		s.pop();
		cout<<temp->val<<"   ";
	
		if(temp->right!=NULL)
		{
			
			s.push(temp->right);
		}
		
		if (temp->left!=NULL)
		{
			
			s.push(temp->left);
		}
		

	}
	cout<<endl;
	return true;

}
bool tree:: insert(int v)
{
	if (root==NULL)
	{
		root=new nodetree(v);
		return true;
	}
	nodetree *temp;
	queue <nodetree*> s;
	temp=root;
	s.push(temp);

	while(!s.empty())
	{
		temp=s.front();
		if(temp->left == NULL)
		{
			temp->left=new nodetree(v);
			return true;
		}
		else
			s.push(temp->left);
		if(temp->right ==NULL)
		{
			temp->right=new nodetree(v);
			return true;
		}
		else
			s.push(temp->right);
		s.pop();

	}
	return false;


}
tree::tree()
{
	root=NULL;
	tree1=NULL;
	tree2=NULL;
	
}
tree::tree(int v)
{
	root=new nodetree(v);
	tree1=NULL;
	tree2=NULL;
	height=1;
	
}

tree::~tree()
{
	delete root;
	delete tree1;
	delete tree2;
	
}
int main()
{
	bst tree1;
	int j;
	for(int i=1;i<=10;i++)
	{	
		j=rand()%100;
		
		tree1.insert(j);
		
	}
tree1.bfs();
	tree1.dfs();
	cout<<endl<<j<<endl;
	cout<<tree1.balanced()<<endl;
	tree1.del(7);
	tree1.del(30);
	tree1.del(73);
	tree1.del(23);
	tree1.del(58);
	tree1.del(9);
	

	tree1.bfs();
	tree1.dfs();
	cout<<endl;
	return 0;

}