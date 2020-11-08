#include"work3.h"
#include <iostream>
using namespace std;
int BSTree::Search(int key)
{
	BSTNode *pNode = Root;
	while (pNode != NULL) {
		if (key < pNode->Key) 
			pNode = pNode->LChild;
		else if (key > pNode->Key) 
			pNode = pNode->RChild;
		else 
			return pNode->Count;
	}
	return 0;
}
void BSTree::Rec_Insert(BSTNode* &root, int key)
{
	if (root == NULL)
	{
		root = new BSTNode(key);
		return;
	}
	if (root->Key > key)
	{
		Rec_Insert(root->LChild, key);
	}
	else if(root->Key < key)
	{
		Rec_Insert(root->RChild, key);
	}
	else {
		root->Count += 1;
	}
}
void BSTree::Rec_PostOrder(BSTNode *root, void visit(int, int))
{
	if (root != NULL)
	{
		Rec_PostOrder(root->LChild, visit);
		Rec_PostOrder(root->RChild, visit);
		visit(root->Key, root->Count);
	}
	return;
}
