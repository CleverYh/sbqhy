#include <iostream>
using namespace std;

struct BinaryNode {
    string name;

    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(const string &n = "", BinaryNode *lt = NULL, BinaryNode *rt = NULL)
        : name(n), left(lt), right(rt){};
};

//return the tree.
//BinaryNode* foo();