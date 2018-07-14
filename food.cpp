#include <iostream>
#include <cstdlib>

#define PROTEINCAL 4
#define CARBCAL 4
#define FATCAL 9

using namespace std;
//header
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
	double totalprotein = 0;
	double totalcarb = 0;
	double totalfat = 0;
	while(head){
		cout << head -> name << endl;
		cout << head -> servings << " servings of " << head -> name << " : "<< endl;
	        cout <<"protein : " << (double)(head -> protein) << endl; 
		totalprotein += (double)(head -> protein);
		cout <<"carbs : " << (double)(head -> carbs) << endl;
		totalcarb += (double)(head -> carbs);
		cout <<"fat : " << (double)(head -> fat) << endl;
		totalfat += (double)(head -> fat);
		cout <<"calories : " << (double)(head -> protein) * PROTEINCAL + (double)(head -> carbs) * CARBCAL +
			(double)(head -> fat) * FATCAL << endl;
		cout << endl;
		head = head -> next;
		i++;
	}
	cout << "Total protein is: " << totalprotein << endl;
	cout << "Total carbs is: " << totalcarb << endl;
	cout << "Total fat is: " << totalfat << endl;
       	cout << "Total calories is: " << totalprotein * PROTEINCAL + totalcarb * CARBCAL + totalfat * FATCAL << endl;
}
