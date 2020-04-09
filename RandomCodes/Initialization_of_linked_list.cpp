# include <iostream>
using namespace std;
class node{
	public : 
	int data;
	node* next;
	node(int t)
	{
		data=t;
		next=NULL;
	}
};
class linkedlist{
	public : 
	node* head;
	node* tail;
	linkedlist()
	{
		head=NULL;
		tail=NULL;
	}
	void insertatend(int t)
	{
		if(head==NULL)
		{
			node* n=new node(t);
			head=n;
			tail=n;
		}
		else 
		{
			node* n=new node(t);
			tail->next=n;
			// can also be written as (*tail).next= n;
			tail=n;
		}
	}
	void print()
	{
		node* temp=head;
		while(temp)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};
int main()
{
	int n;
	cout<<"Enter the size of the list"<<endl;
	cin>>n;
	linkedlist l;
	for(int i=1;i<=n;i++)
	{
		l.insertatend(n+1-i);
	}
	l.print();
	return 0;
}
