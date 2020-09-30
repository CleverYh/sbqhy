#include <iostream>
using namespace std;

#define SIZE 100

template <typename T>
class Queue {
private:
    T *queue;
    // int size;
    int head;
    int rear;
    // bool empty;

public:
    Queue() {
        queue = new T[SIZE];
        head = 0;
        rear = 0;
        // this->size = SIZE;
        // empty = true;
    }

    ~Queue() {
        delete[] queue;
    }

    Queue(const Queue &rhs){
        queue = new T[SIZE];
        for(int i =0 ;i<SIZE;i++){
            queue[i] = rhs.queue[i];
        }
        head = rhs.head;
        rear = rhs.rear;
        // this.size = rhs.size;
    }

    const Queue & operator = (const Queue &rhs){
        queue = new T[SIZE];
        for(int i =0 ;i<SIZE;i++){
            queue[i] = rhs.queue[i];
        }
        head = rhs.head;
        rear = rhs.rear;
        // this.size = rhs.size;
    }

    bool empty() const {
        return rear == head;
    }

    bool full() const {
        return ((rear + 1) % SIZE == head);
    }

    int size()const{
        return (rear - head)%SIZE;
    }

    bool push(const T &x){//bool enqueue(const T val) {
        // if (((rear + 1) % size == front)) return false;
        if (full()) return false;
        ++rear %= SIZE;
        queue[rear] = x;
    }

    bool pop(){//T dequeue() {
        if (empty()) return false;
        // if (front == rear) empty = true;
        ++head %= SIZE;
        return true;//queue[front];
    }
    const T & front()const{
        return queue[head+1];
    }
};

// int main() {

//     Queue<int> q;
//     q.enqueue(2);
//     q.enqueue(3);
//     int i = q.dequeue();
//     cout << i << endl;
//     // cout << q.isEmpty() << endl;
//     return 0;
// }

