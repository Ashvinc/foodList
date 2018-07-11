#include <iostream>
#include <cstdlib>
using namespace std;

class Node
{
	public:
		Node * next;
		string name;
		double servings;
		double protein;
		double carbs;
		double fat;
};

class LinkedList
{
	public:
	int size;
	Node * front;

	LinkedList();
	~LinkedList();

	void add(string name, double servings, double protein, double carbs, double fat);
	void print();
	bool remove(string name);
	void removeAllNodes();
};

LinkedList::LinkedList(){
	this -> size = 0;
	this -> front = NULL;
}

LinkedList::~LinkedList(){
	cout << "LIST DELETED";
	removeAllNodes();
	this -> size = 0;
}

void LinkedList::add(string name, double servings, double protein, double carbs, double fat)
{
	Node * node = new Node();
	node -> name = name;
	node -> servings = servings;
	node -> protein = servings * protein;
	node -> carbs = servings * carbs;
	node -> fat = servings * fat;
	node -> next = this -> front;
	this -> front = node;
	this -> size++;
}

bool LinkedList::remove(string name){
	Node * head = this -> front;
	Node * pre;
	bool retval = false;
	
	if(size == 0)
	{
	}
	else if(head -> name == name)
	{
		this -> front = head -> next;
		retval = true;
		this -> size--;
		delete head;
	}
	else 
	{
		
		int i = 1;
		while(i < this -> size)
		{
			pre = head;
			head = head -> next;
			if(head -> name == name)
			{
				pre -> next = head -> next;
				retval = true;
				this -> size--;
				delete head;
			}
			i++;
		}
		
	}
	return retval;
}

void LinkedList::removeAllNodes(){
	Node * head = this -> front;
	if(head == NULL)
	{
		return;
	}
	while(head -> next != NULL)
	{
		this -> front = head -> next;
		delete head;
		head = this -> front;
	}
	delete head;

	this -> front = NULL;
	this -> size = 0;
}


void LinkedList::print(){
	Node * head = this -> front;
	int i = 1;
	while(head){
		cout << head -> name << endl;
		cout << head -> servings << " servings of " << head -> name << " : "<< endl;
	        cout <<"protein : " << (double)(head -> protein) << endl; 
		cout <<"carbs : " << (double)(head -> carbs) << endl;
		cout <<"fat : " << (double)(head -> fat) << endl;
		cout << endl;
		head = head -> next;
		i++;
	}
}
