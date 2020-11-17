#include "b+tree.h"

int main() {
    BPlusTree t;
    t.insert(1, 1);
    t.insert(2, 2.1111);
    t.insert(3, 3.14159);
    cout << t.accessData(1).first << " " << t.accessData(2).second << endl;
    cout << t.search(1) << t.search(2) << t.search(3) << endl;
    t.remove(3);
    t.remove(2);
    cout << t.search(1) << t.search(2) << t.search(3) << endl;
    return 0;
}