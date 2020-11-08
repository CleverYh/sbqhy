#include <iostream>
using namespace std;
struct BSTNode {
	int Key;
	int Count;
	BSTNode *LChild, *RChild;
	BSTNode() {};
	BSTNode(int key) { Key = key; Count = 1; LChild = RChild = NULL; };
};
class BSTree {
public:
	BSTree() { Root = NULL; };
	void Insert(int key) { Rec_Insert(Root, key); };
	void PostOrder(void visit(int, int)) { Rec_PostOrder(Root, visit); };
	int Search(int key);
private:
	void Rec_Insert(BSTNode* &root, int key);
	void Rec_PostOrder(BSTNode *root, void visit(int, int));
	BSTNode *Root;
}; 