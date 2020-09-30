// #include<cstdio>
#include <iostream>

#define SIZE 100001

using namespace std;

int matches(string e) {
    char stack[SIZE] = {0};
    int top = 0;

    int i = 0;

    while (e[i] != '(' && e[i] != '[' && e[i] != '{' && i < e.size()) {
        if (e[i] == ')' || e[i] == ']' || e[i] == '}') return 3; //若为')'或']'或'}'，则表明不匹配。
        i++;
    }

    if (i == e.size()) return 0;

    // if (e[i] == '(' || e[i] == '[' || e[i] == '{')
    //     stack[top++] = e[i++]; //检测到左括号，进栈
    // i++;

    while (i < e.size()) {
        if (e[i] == '(' || e[i] == '[' || e[i] == '{')
            stack[top++] = e[i]; //检测到左括号，进栈
        else if (e[i] == ')' || e[i] == ']' || e[i] == '}') {
            if (top == 0) {
                return 3;
            } else if (e[i] == ')') {
                if (stack[top - 1] == '(')
                    top--;
                else
                    return 1;
            } else if (e[i] == ']') {
                if (stack[top - 1] == '[')
                    top--;
                else
                    return 1;
            } else if (e[i] == '}') {
                if (stack[top - 1] == '{')
                    top--;
                else
                    return 1;
            }
        }
        i++;
    }
    if (top != 0 && i == e.size()) return 2;

    return 0;
}


int main() {
    string a="(())]()";
    // cin >> a;
    cout << matches(a) << endl;
    return 0;
}