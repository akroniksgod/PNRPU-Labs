#include "Tree.h"
Tree::Tree()
{
	left = NULL;
	right = NULL;
	parent = NULL;
}

Tree::Tree(int newData)
{
	data = newData;
	left = NULL;
	right = NULL;
	parent = NULL;
}

Tree::~Tree()
{
	if (this != NULL)
		delete this;
}

void Tree::insertRight(int newData)
{
	Tree* node = new Tree(newData);
	if (this->right != NULL) {
		this->right->parent = node;
		node->right = this->left;
		this->right = node;
		node->parent = this;
	}
	else {
		Tree* node = new Tree(newData);
		this->right = node;
		node->parent = this;
	}
}

void Tree::insertLeft(int newData)
{
	Tree* node = new Tree(newData);
	if (this->left != NULL) {
		this->left->parent = node;
		node->left = this->left;
		this->left = node;
		node->parent = this;
	}
	else {
		Tree* node = new Tree(newData);
		this->left = node;
		node->parent = this;
	}
}

void Tree::insertNewNode(Tree*& root, int newData)
{
	if (root == NULL) {
		root = new Tree(newData);
		return;
	}
	Tree* node = root;
	while (node != NULL) {
		if (newData >= node->data) {
			if (node->right != NULL)
				node = node->right;
			else {
				node->insertRight(newData);				
				return;
			}
		}
		else if (newData < node->data) {
			if (node->left != NULL)
				node = node->left;
			else {
				node->insertLeft(newData);			
				return;
			}
		}
	}
}

void Tree::InOrder(Tree* node)
{
	if (node == NULL)
		return;	
	InOrder(node->left);	
	cout << node->data << "|";	
	InOrder(node->right);	
}

int Tree::getHeight()
{
	int h1 = 0, h2 = 0, hadd = 0;
	if (this == NULL)
		return 0;
	if (this->left != NULL)
		h1 = this->left->getHeight();
	if (this->right != NULL)
		h2 = this->right->getHeight();
	if (h1 >= h2)
		return h1 + 1;
	else
		return h2 + 1;
}

Tree* Tree::Find_a_Node(int newData)
{
	Tree* node = this;
	while (node != NULL) {
		if (node->data == newData)
			return node;
		else {
			if (node->data > newData)
				node = node->left;
			else
				node = node->right;
		}
	}
	return NULL;
}

int Tree::FindMax()
{
	Tree* node = this;
	while (node->right != NULL) {
		node = node->right;
	}
	return node->data;
}