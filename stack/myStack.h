#include <iostream>

using namespace std;

typedef int Stack_entry;

class Stack {
public:
    // Standard Stack methods
    Stack() {
        num = 0;
    }
    bool empty() const {

        return num == 0;
    }
    /* Returns true if the stack is empty, otherwise, returns false.
    */
    int size() const {
        return num;
    }
    /* Returns the number of elements in the stack.
    */
    void push(const Stack_entry &item) {
        a[num] = item;
        num++;
    }
    /*item is pushed into the stack and it becomes the new top element.
     */
    void pop() {
        if (empty())
            return;
        num--;
    }
    /*The top item is removed if the stack is not empty.
     Otherwise, nothing happens.
     */

    const Stack_entry &top() const {

        return a[num - 1];
    }
    /* The top element is returned by item if the stack is not empty,
    and the stack remains unchanged.
    Nothing happens if the stack is empty.
   */
    // Safety features
    ~Stack() {
        num = 0;
    }
    Stack(const Stack &original) {
        *this = original;
    }
    void operator=(const Stack &original) {
        for (int i = 0; i < original.size(); i++)
            a[i] = original.a[i];
        num = original.size();
    }

private:
    Stack_entry a[100];
    int num;
};
