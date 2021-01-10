//.cpp file to implement the Liked List class

#include<iostream>
#include <algorithm> 
#include<cmath>
#include"BST.h"


using namespace std;

BST::BST()
{
	Root = NULL;
}

Node* BST::get_root()
{
	return Root;
}

void  BST::set_root(Node* r)
{
	Root = r;
}

void BST::insert(int d)
{
	Node* new_element = new Node(d);
	if (Root == NULL)
	{
		new_element->set_Parent(NULL);
		Root = new_element;
	}

	else
	{
		Node* previous = Root;
		Node* current = Root;
		while (current != NULL)
		{
			previous = current;
			if (d > current->get_data())
				current = current->get_Right();
			else
				current = current->get_Left();
		}
		if (d > previous->get_data())
		{
			new_element->set_Parent(previous);
			previous->set_Right(new_element);
		}

		else
		{
			new_element->set_Parent(previous);
			previous->set_Left(new_element);
		}
	}

}



void BST::inorder(Node* t)
{
	if (t != NULL)
	{
		inorder(t->get_Left());
		cout << t->get_data() << "  ";
		inorder(t->get_Right());
	}
}

void BST::preorder(Node* t)
{
	if (t != NULL)
	{
		cout << t->get_data() << "  ";
		preorder(t->get_Left());
		preorder(t->get_Right());
	}
}

void BST::postorder(Node* t)
{
	if (t != NULL)
	{
		postorder(t->get_Left());
		postorder(t->get_Right());
		cout << t->get_data() << "  ";
	}
}

Node* BST::maximum()
{
	if (Root == NULL)
		return NULL;
	else
	{
		Node* current = Root;
		while (current->get_Right() != NULL)
			current = current->get_Right();
		return current;
	}
}

Node* BST::minimum()
{
	if (Root == NULL)
		return NULL;
	else
	{
		Node* current = Root;
		while (current->get_Left() != NULL)
			current = current->get_Left();
		return current;
	}
}

Node* BST::search(int d)
{
	if (Root == NULL)
		return NULL;
	else if (Root->get_data() == d)
		return Root;
	else
	{
		Node* current = Root;
		while (current != NULL)
		{
			if (d > current->get_data())
				current = current->get_Right();
			else
				current = current->get_Left();
			if (current != NULL && d == current->get_data())
				return current;

		}
		return NULL;
	}

}

Node* BST::Successor(int d)
{
	Node* s = search(d);
	if (s == NULL)
		return NULL;
	else if (s->get_Right() != NULL)
	{
		Node* current = s->get_Right();
		while (current->get_Left() != NULL)
			current = current->get_Left();
		return current;
	}
	else
	{
		while (s != Root && s->get_data() > s->get_Parent()->get_data())
		{
			s = s->get_Parent();
		}
		if (s == Root)
			return NULL;
		else
			return s->get_Parent();

	}
}

Node* BST::Predecessor(int d)
{
	Node* s = search(d);
	if (s == NULL)
		return NULL;
	else if (s->get_Left() != NULL)
	{
		Node* current = s->get_Left();
		while (current->get_Right() != NULL)
			current = current->get_Right();
		return current;
	}
	else
	{
		while (s != Root && s->get_data() < s->get_Parent()->get_data())
		{
			s = s->get_Parent();
		}
		if (s == Root)
			return NULL;
		else
			return s->get_Parent();
	}
}
bool BST::DeleteNode(int data)
{
	if (Root == NULL)
		return false;
	else
	{
		Node* current = search(data);
		if (current == NULL)
			return false;
		else
		{
		case3:
			if (current->get_Right() == NULL && current->get_Left() == NULL)
			{
				if (current->get_Parent()->get_data() > current->get_data())
					current->get_Parent()->set_Left(NULL);
				else
					current->get_Parent()->set_Right(NULL);
				return true;
			}
			else if (current->get_Right() != NULL && current->get_Left() != NULL)
			{
				Node* suc = Successor(current->get_data());
				int val1 = current->get_data(), val2 = suc->get_data();
				swap(val1, val2);
				current->set_data(val1);
				suc->set_data(val2);
				current = suc;
				goto case3;
			}
			else
			{
				if (current->get_Right() == NULL)
				{
					if (current == current->get_Parent()->get_Left())
						current->get_Parent()->set_Left(current->get_Left());
					else
						current->get_Parent()->set_Right(current->get_Left());
					return true;
				}
				else
				{
					if (current == current->get_Parent()->get_Right())
						current->get_Parent()->set_Right(current->get_Right());
					else
						current->get_Parent()->set_Left(current->get_Right());
					return true;
				}

			}
		}

	}
}

Node* BST::insertLevelOrder(int arr[], Node* root, int i, int n)
{
	if (i < n)
	{
		Node* temp = new Node(arr[i]);
		root = temp;

		// insert left child 
		root->set_Left(insertLevelOrder(arr,
			root->get_Left(), 2 * i + 1, n));

		// insert right child 
		root->set_Right(insertLevelOrder(arr, root->get_Right(), 2 * i + 2, n));
	}
	Root = root;
	return root;
}

