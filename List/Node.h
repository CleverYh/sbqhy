// #include <cstring>
#include <iostream>
// #include <string>
using namespace std;

typedef string T;
typedef struct Node {
    T data;
    struct Node *next;

    Node() { next = NULL; };
    Node(T item, Node *add_on = NULL) {
        data = item;
        next = add_on;
    };
}Node;
