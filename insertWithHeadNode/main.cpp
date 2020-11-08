#include "Node.h"
#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void clear(Node *p) {
    if (p != NULL) {
        Node *q = p->next;
        delete p;
        clear(q);
    }
}
//print linked list with header node
void print(Node *p) {
    p = p->next;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Node *createList(int n) {
    Node *head = new Node();
    while (n--) {
        Node *p = new Node(n + 1, head->next);
        head->next = p;
    }
    return head;
}

int main(int argc, char **argv) {
    int N, n;
    cin >> N;
    while (N--) {
        cin >> n;
        Node *position, *head;

        for (int i = 1; i <= n; i++) {
            head = createList(n);
            print(head);

            position = head->next;
            for (int j = 1; j < i; j++) {
                position = position->next;
            }
            head = insert(head, position, 100);
            print(head);
            clear(head);
        }
    }
    return 0;
}
