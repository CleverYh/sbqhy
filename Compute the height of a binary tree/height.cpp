#include "BST.h"

int height(BinaryNode* root ){
    if (root == NULL) return -1;
    // BinaryNode *p = root;
    int lh = height(root->left);
    int rh = height(root->right);
    return lh > rh ? lh + 1 : rh + 1;
}

#if 0
int main() {
    BinaryNode *root = new BinaryNode(1,NULL,NULL);
    cout << height(root) << endl;
    return 0;
}
#endif