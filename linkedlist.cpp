#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
class nodelink
{
public:
	int value;
	nodelink *next;

	nodelink(int);
	
};
nodelink::nodelink(int val)
{
	value=val;
	next=NULL;

}

class linkedlist
{
	
public:
	nodelink *head;
	linkedlist(int);
	linkedlist();
	~linkedlist();
	bool insert(int); //if insert is a success
	bool insertathead(int);
	bool print();
	bool del(int);//if delete success return true
	bool reverse();
	bool removeduplicates();
	bool partition(int);
	int kthlastelem(int);
	


	//nodelink* find(int);// return the pointer if success else return null
	//bool reverse(int);// if reverse success return true;


};

bool linkedlist::partition(int x)
{
	nodelink *head1,*head2,*temp,*nex;
	head1=NULL;
	head2=NULL;
	temp=head;
	while(temp!=NULL)
	{
		nex=temp->next;
		if(temp->value<x)
		{
			temp->next=head1;
			head1=temp;

		}
		else
		{
			temp->next=head2;
			head2=temp;
		}
		temp=nex;
	}
	temp=head1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head2;
	head=head1;
	return true;

	


}
bool deletenodelink(nodelink* node)
{
	nodelink *nex;
	if(node==NULL)
	{
		return false;

	}
	if (node->next==NULL)
	{
		return false;
	}
	
	nex=node->next;
	node->value=nex->value;
	node->next=nex->next;
	delete nex;

	

	
	delete node;
	return true;
}

int linkedlist::kthlastelem(int k)
{
	nodelink *temp1,*temp2;
	temp1=head;
	for (int i=0;i<k;i++)
	{
		temp1=temp1->next;
		if(temp1==NULL)
			return -1;
	}
	temp2=head;
	while(temp1!=NULL)
	{
		temp2=temp2->next;
		temp1=temp1->next;
	}
	return temp2->value;

}
bool linkedlist::removeduplicates()
{
	nodelink *temp,*prev;
	prev=NULL;
		temp=head;
	unordered_map<int,bool> dupmap;
	if (head==NULL)
		return true;
	if (head->next==NULL)
		return true;
	while (temp!=NULL)
	{
		if (dupmap[temp->value]==false)
		{
			dupmap[temp->value]=true;
			prev=temp;
			temp=temp->next;
		}
		else
		{
			prev->next=temp->next;
			delete temp;
			temp=prev->next;
		}
	}
	return true;

}
bool linkedlist::print()
{
	nodelink *temp;
	temp=head;
	cout<<temp->value;
	temp=temp->next;
	while(temp!=NULL)
	{
		cout<<" -> ";
		cout<<temp->value;
		temp=temp->next;
	}
	cout<<endl;
	return true;
}
linkedlist::linkedlist(int val)
{
	head=new nodelink(val);
}
linkedlist::linkedlist()
{
	head=NULL;
}
linkedlist::~linkedlist()
{
	delete head;
}
bool linkedlist::insert(int val)
{
	nodelink *temp;
	nodelink *newnode= new nodelink(val);
	if (head==NULL)
	{
		head=newnode;
		return true;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	
	temp->next=newnode;
	return true;
}
bool linkedlist::insertathead(int val)
{
	nodelink *newnode=new nodelink(val);

	if(head==NULL)
	{
		head=newnode;
		return true;
	}
	nodelink *temp=head;
	head=newnode;
	head->next=temp;
	return true;

}
bool linkedlist::del(int val)
{
	nodelink *temp,*previous;
	if (head==NULL)
		return false;
	temp=head;
	if (head->value==val)
	{
		head=head->next;
		delete head;
		return true;
	}
	while(temp->next!=NULL)
	{
		previous=temp;
		temp=temp->next;
		if(temp->value==val)
		{
			previous->next=temp->next;
			delete temp;
			return true;
		}
	}
	return false;
}

bool linkedlist::reverse()
{
	
	nodelink *curr,*prev,*nex;
	
	
	prev=NULL;
	curr=head;
	
	while(curr!=NULL)
	{
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;
		
		


	}
	
	head=prev;
	return true;

}
linkedlist* sum_link(linkedlist *link1,linkedlist *link2)
{
	nodelink *temp1=link1->head;
	nodelink *temp2=link2->head;
	linkedlist *list1=new linkedlist();
	int carry=0,l1,l2,sum;
	while((temp1!=NULL) || (temp2!=NULL))

	{

		if (temp1==NULL)
		{	l1=0;
		}
		else
		{
			l1=temp1->value;
			temp1=temp1->next;
			if (l1>=10)
				return NULL;
		}
		if (temp2==NULL)
			{
				l2=0;
			}
		else
		{
			l2=temp2->value;
			temp2=temp2->next;
			if (l2>=10)
				return NULL;
		}
		sum=l1+l2+carry;

		list1->insert(sum%10);
		carry=sum/10;
		
		
	}
	return list1;
}
linkedlist* sumrev_link(linkedlist* link1,linkedlist* link2)
{
	link1->reverse();
	link2->reverse();
	linkedlist *link3=sum_link(link1,link2);
	if (link3==NULL)
		return NULL;
	link3->reverse();
	return link3;
}
int loop_begin(linkedlist* link1)
{
	nodelink *slow,*slow1,*fast;
	slow=link1->head;
	fast=link1->head;
	slow=slow->next;
	if (slow==NULL)
		return -1;
	fast=slow->next;
	while((fast!=NULL && fast->next!=NULL) && (slow!=fast))
	{
		fast=fast->next->next;
		slow=slow->next;
	}

	if ((fast==NULL) || (fast->next=NULL))
		return -1;
	slow1=link1->head;
	
	while(slow!=slow1)
	{
		slow=slow->next;
		slow1=slow1->next;
	}
	return slow->value;
}
bool palindrome(linkedlist* link1)
{
	nodelink *slow,*fast;
  	stack <int> s;
  	slow=link1->head;
  	fast=link1->head;
  	while((fast!=NULL)&&(fast->next!=NULL))
  	{
  		s.push(slow->value);
  		slow=slow->next;
  		fast=fast->next->next;

  	}
  	if (fast!=NULL)
  	{
  		slow=slow->next;

  	}
  	while(slow!=NULL)
  	{
  		if (slow->value!=s.top())
  			return false;
  		s.pop();
  		slow=slow->next;

  	}
  	return true;


}
int main()
{
	linkedlist list1(1);

	list1.insert(2);
	list1.insert(3);
	list1.insert(3);
	list1.insert(2);
	list1.insert(1);
	list1.print();
		cout<<palindrome(&list1)<<endl;
	

	
	return 0;
}



