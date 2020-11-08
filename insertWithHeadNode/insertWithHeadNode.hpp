#include "Node.h"

//insert x before position in a nonempty linked list with header node
//returns the linked list afte insertion
Node * insert(Node* head, Node* position, const T &x){
	Node *p;
	p = head;
	while (p->next != position){
		p = p->next;
	}
	Node * q = new Node(x,position);
	p->next = q;
	return head;
}
