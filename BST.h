//Header file for the Binary Search Tree

#include<iostream>
#include"Node.h"
#ifndef LIST
#define LIST
using namespace std;
class BST
{
private:
	 Node* Root;
	 string res = "";
public:
	int node_count = 0;

	BST();
	void insert(int d);		
	Node* search(int d);
	void inorder(Node* t);
	void preorder(Node* t);
	void postorder(Node* t);

	Node* maximum();
	Node* minimum();

	Node* Successor(int data);
	Node* Predecessor(int data);

	void set_root(Node* h);
	Node* get_root();		
	

	bool DeleteNode(int d);
	Node* insertLevelOrder(int arr[], Node* root, int i, int n);

	


};

#endif
