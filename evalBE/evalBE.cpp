#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

bool eval_BE(const string &exp, map<char, bool> f) {
    if (exp.size() == 0) return true;
    stack<char> ops, exps;
    int i = 0;
    while (exp.size() > i) {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*') {

            if (exp[i] == '+' && exps.size() > 1) {
                bool a, b;
                if (exps.top() == '0' || exps.top() == '1') {
                    a = exps.top() - 48;
                } else {
                    a = f[exps.top()];
                }

                exps.pop();
                if (exps.top() == '0' || exps.top() == '1') {
                    b = exps.top() - 48;
                } else {
                    b = f[exps.top()];
                }
                exps.pop();
                if((a+b) == true){
                    exps.push('1');
                } else {
                    exps.push('0');
                }
                
            } else if (exp[i] == '-' && exps.size() > 0) {
                bool a;
                if (exps.top() == '0' || exps.top() == '1') {
                    a = exps.top() - 48;
                } else {
                    a = f[exps.top()];
                }
                exps.pop();
                if((-a) == true){
                    exps.push('1');
                } else {
                    exps.push('0');
                }
            } else if (exp[i] == '*' && exps.size() > 1) {
                bool a, b;
                if (exps.top() == '0' || exps.top() == '1') {
                    a = exps.top() - 48;
                } else {
                    a = f[exps.top()];
                }

                exps.pop();
                if (exps.top() == '0' || exps.top() == '1') {
                    b = exps.top() - 48;
                } else {
                    b = f[exps.top()];
                }
                exps.pop();
                 if((a&&b) == true){
                    exps.push('1');
                } else {
                    exps.push('0');
                }
            }

            // ops.push(exp[i]);
        } else {
            exps.push(exp[i]);
        }
        i++;
    }
    if (exps.size() == 1)
        if( exps.top() == '1') return true;
        else if(f[exps.top()] == true) return true;
        else
            return false;
    else
        return true;

    //     bool a = false, b = false, A = false, B = false;

    // while (exp.size() > i) {
    //     if (exp[i] == '+') {
    //         if (a == true && b == true) {
    //             A = A + B;
    //             b = false;
    //         }
    //     } else if (exp[i] == '*') {
    //         if (a == true && b == true) {
    //             A = A && B;
    //             b = false;
    //         }
    //     } else if (exp[i] == '-') {
    //         if (a == true) {
    //             A = -A;
    //         }
    //     } else if (exp[i] == '0' || exp[i] == '1') {
    //         if (a != true && b != true) {
    //             A = exp[i] - '0';
    //             a = true;
    //         } else if (a == true && b != true) {
    //             B = exp[i] - '0';
    //             b = true;
    //         }
    //     } else {
    //         if (a != true && b != true) {
    //             A = f[exp[i]];
    //             a = true;
    //         } else if (a == true && b != true) {
    //             B = f[exp[i]];
    //             b = true;
    //         }
    //     }
    //     i++;
    // }
    // return A;
}

int main() {
    map<char, bool> f;

    f.insert(pair<char, bool>('a', true));
    f.insert(pair<char, bool>('b', true));

    string s = "ab0++";

    cout << eval_BE(s, f) << endl;
    return 0;
}