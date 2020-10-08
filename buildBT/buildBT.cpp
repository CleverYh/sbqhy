#include "BT.h"

BinaryNode* foo(){
    BinaryNode *lnode = new BinaryNode("is", NULL, NULL);
    BinaryNode *rnode = new BinaryNode("simple", NULL, NULL);
    BinaryNode* root = new BinaryNode("This",lnode,rnode);
    return root;
}

#if 0
int main(){
    BinaryNode *root = foo();
    cout << root->name << root->left->name << root->right->name << endl;

    return 0;
}
#endif