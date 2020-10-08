#include "NodeTemplate.h"
template <typename T>
Node<T> *copyList(const Node<T> *head) {
    Node<T> *copylist;
    Node<T> *copyhead = copylist;
    Node<T> *p = head;
    while (p) {
        copyhead->next = NULL;
        Node<T> *s = new Node<T>;
        s->entry = p->entry;
        copyhead = s;
        copyhead = copyhead->next;
        p = p->next;
    }
    copyhead->next = NULL;
    return copylist;
}
//return a coply of the linked