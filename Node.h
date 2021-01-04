//A node class which creates the nodes for the linked List along basic getter and setter functions

#include<iostream>
using namespace std;
#ifndef NODE
#define NODE
class Node
{
private:
	int data;
	Node* Left;
	Node* Right;
	Node* Parent;
public:
	Node();
	Node(int d);			
	void set_data(int d);
	void set_Left(Node* l);		
	void set_Right(Node* r);
	void set_Parent(Node* p);
	Node* get_Left();
	Node* get_Right();
	Node* get_Parent();
	int get_data();
};

#endif


