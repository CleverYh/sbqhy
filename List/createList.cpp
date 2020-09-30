#include "Node.h"
#include <cstdlib>
#include <string>

Node* insertAtTail(Node *head, T data) {
    if (head == NULL) {
        head = (Node *)calloc(1, sizeof(Node));
        // head->data = data;
        head->next = NULL;
        // return head;
    }
    if (head->next == NULL) {
        head->next = (Node *)calloc(1, sizeof(Node));
        head->next->data = data;
        head->next->next = NULL;
        return head;
    }
    Node *pre = NULL;
    Node *cur = head->next;
    while (cur != NULL) {
        pre = cur;
        cur = cur->next;
    }
    Node *newp = (Node *)calloc(1, sizeof(Node));
    newp->data = data;
    newp->next = NULL;
    pre->next = newp;
    return head;
}

void freeIt(Node *head) {
    if (head == NULL) {
        return;
    }
    freeIt(head->next);
    free(head);
}

void printIt(Node *head) {
    while (head != NULL) {
        head = head->next;
        cout << head->data << " ";
    }
}
Node *foo() {
    Node *head = NULL;

    head = insertAtTail(head, "Programming");
    head = insertAtTail(head, "is");
    head = insertAtTail(head, "fun");

    return head;
}

int main() {
    Node *head = foo();
    printIt(head);
    freeIt(head);
    return 0;
}