#include "myStack.h"
#include "check.h"
#include <iostream>

using namespace std;

void print(Stack s) {

    cout << "size:" << s.size() << endl;
    if (!s.empty()) {
        int x;
        x = s.top();
        cout << x << endl;
    }
    cout << "-------" << endl;
}

int main() {

    char op[25] = {0, 1, -1, 0, -1, 1, 1, 0, 0, 1, 1, 1, 0, -1, 1, -1, 1, 1, -1, 0, 1, 1, 1, 1, 0};
    int a[25] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    Stack s;

    for (int i = 0; i < 25; i++) {
        switch (op[i]) {
            case 0:
                if (!s.empty())
                    s.top();
                break;
            case 1:
                s.push(a[i]);
                break;
            case -1:
                if (!s.empty())
                    s.pop();
                break;
            default:
                break;
        }
        print(s);
    }

    for (int i = 1; i <= 20; i++) {
        s.push(3 * i);
    }
    print(s);

    Stack s1, s2(s);
    print(s2);
    s.push(100);
    print(s2);

    s1 = s;
    s.push(200);
    print(s1);

    Stack *p = new Stack(s);
    print(*p);

    delete p;
    return 0;
}