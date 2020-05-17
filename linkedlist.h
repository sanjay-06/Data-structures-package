#include <bits/stdc++.h>
#include<fstream> 
using namespace std;
class Node1
{
	string data; 
	Node1 *next, *prev;
	public:
		friend class linkedlist;
};
class linkedlist
{
	Node1 *head;
	public:
		linkedlist();
		Node1* getNode(string);
		void push1(Node1**, Node1*);
		void printList();
		Node1* Reverse(Node1*);
		void insert(string);
		void rev();
		bool search(string);
		void replace(string,string);
		void recreate(string);    
};
linkedlist::linkedlist()
{
	 head = NULL; 
} 
Node1* linkedlist::getNode(string data) 
{  
	Node1* new_node = new Node1; 
	new_node->data = data; 
	new_node->next = new_node->prev = NULL; 
	return new_node; 
} 
void linkedlist::push1(Node1** head_ref, Node1* new_node) 
{ 
	new_node->prev = NULL;  
	new_node->next = (*head_ref);  
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 
	(*head_ref) = new_node; 
} 
void linkedlist::printList() 
{ 
	Node1* temp;
	temp=head;
	while (temp != NULL) { 
		cout << temp->data << " "; 
		temp = temp->next; 
	} 
}
void linkedlist::replace(string str,string str1)
{
	Node1* temp;
	temp=head;
	while(temp!=NULL)
	{
		if(str.compare(temp->data)==0)
		{
			temp->data=str1;
			break;
		}
		temp=temp->next;
	}
}
void linkedlist::recreate(string fileName)
{
	fstream file;
	Node1* temp;
	temp=head;
	file.open(fileName.c_str(),ios::in);
	remove(fileName.c_str());
	file.open(fileName.c_str(),ios::in);
	file.close();
	file.open(fileName.c_str(),ios::out);
	while(temp!=NULL)
	{
		file<<temp->data+" ";
		temp=temp->next;
	}
	file.close();
	return;
}
bool linkedlist::search(string str)
{
	Node1* temp;
	rev();
	temp=head;
	while(temp!=NULL)
	{
		if(str.compare(temp->data)==0)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}
Node1* linkedlist::Reverse(Node1* node) 
{  
    if (!node) 
        return NULL; 
	Node1* temp = node->next; 
    node->next = node->prev; 
    node->prev = temp; 
    if (!node->prev) 
        return node; 
    return Reverse(node->prev); 
}
void linkedlist::insert(string s)
{  
	push1(&head, getNode(s)); 
} 
void linkedlist::rev()
{
	head = Reverse(head); 
} 
