#include "work3.h"
#include <iostream>
void visit(int key, int count) {
    cout << key << ':' << count << endl;
}
int main() {

    BSTree tree;
    int key;
    cin >> key;
    while (key != -1) {
        tree.Insert(key);
        cin >> key;
    }
    tree.PostOrder(visit);
    int a = tree.Search(1);
    cout << a << endl;
}