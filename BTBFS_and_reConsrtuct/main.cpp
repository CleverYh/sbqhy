#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct BinaryNode {
    char data;
    BinaryNode *left, *right;
    BinaryNode(char d, BinaryNode *l = NULL, BinaryNode *r = NULL) : data(d), left(l), right(r){};
};

BinaryNode *reConstructBinaryTree(char pre[], char in[], int size) {
    if (size <= 0) return NULL;
    int i, leftn;
    for (i = 0; i < size; i++) {
        if (in[i] == pre[0])
            leftn = i;
    }
    // int leftn = strchr((char*)in, (char)pre[0]) - (char*)in;
    int rightn = size - leftn - 1;
    BinaryNode *root = new BinaryNode(pre[0], reConstructBinaryTree(pre + 1, in, leftn), reConstructBinaryTree(pre + 1 + leftn, in + 1 + leftn, rightn));
    // root->data = pre[0];
    // root->left = reConstructBinaryTree(pre + 1, in, leftn);
    // root->right = reConstructBinaryTree(pre + 1 + leftn, in + 1 + leftn, rightn);
    return root;
}

void deleteTree(BinaryNode *root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

//---------------------------------------------------//
void postOrder(BinaryNode *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data;
}

void BFS_BT(BinaryNode *root){
    if (root == NULL) return;

    queue<BinaryNode *> q;
    q.push(root);
    while(!q.empty()) {
        BinaryNode * t = q.front();
        q.pop();
        cout << t->data;
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
}

int main() {

    int size;
    string s1, s2;
    cin >> s1 >> s2;
    size = s1.size();
    if (size > 0) {

        char preOrder[30], inOrder[30];
        strcpy(preOrder, s1.c_str());
        strcpy(inOrder, s2.c_str());

        BinaryNode *root = reConstructBinaryTree(preOrder, inOrder, size);
        // postOrder(root);
        BFS_BT(root);

        deleteTree(root);
        root = NULL;
    }
    return 0;
}