#include <iostream>

using namespace std;


typedef int T;

struct Node {
//  data members
   T data;
   Node *next;
//  constructors
   Node(){ next = NULL;};
   Node(T item, Node *add_on = NULL){
      data = item;
      next = add_on;
   };
};

//insert x before position in a nonempty linked list with header node
//returns the linked list afte insertion
Node * insert(Node* head, Node* position, const T &x);
