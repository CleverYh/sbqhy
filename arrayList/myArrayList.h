#include "ArrayList.h"

ArrayList ::ArrayList() : count(0) {
    arraySize = 0;
    elems = NULL;
}

ArrayList::ArrayList(size_t n) {
    count = n;
    arraySize = n;
    elems = new T[n];
}

ArrayList::~ArrayList() {
    delete[] elems;
}

ArrayList::ArrayList(const ArrayList &c) {
    count = c.size();
    arraySize = c.capacity();
    elems = new T[arraySize];
    for (size_t i = 0; i < size(); i++) {
        elems[i] = c.elems[i];
    }
}

const ArrayList &ArrayList ::operator=(ArrayList &c) {
    if (this != &c) {
        count = c.size();
        arraySize = c.capacity();
        delete[] elems;
        elems = new T[arraySize];
        for (size_t i = 0; i < count; i++) {
            elems[i] = c[i];
        }
    }
    return *this;
}

T &ArrayList ::operator[](size_t p) {

    return elems[p];
}

size_t ArrayList ::size() const {
    return count;
}

size_t ArrayList ::capacity() const {
    return arraySize;
}

//bool ArrayList :: full()const{
//  return (count >= MAX_SIZE);
//}

void ArrayList ::clear() {
    count = 0;
}
bool ArrayList ::empty() const {
    return (count == 0);
}

void ArrayList::traverse(void (*visit)(T &)) {
    for (size_t i = 0; i <= size() - 1; i++)
        (*visit)(elems[i]);
}

void ArrayList ::retrieve(size_t position, T &x) const {
    if (position > size() - 1)
        return;
    x = elems[position];
}

void ArrayList ::replace(size_t position, const T &x) {
    elems[position] = x;
}

void ArrayList ::erase(size_t position, T &x) {
    x = elems[position];
    for (size_t i = position; i < size() - 1; i++) {
        elems[i] = elems[i + 1];
    }
    count--;
}

void ArrayList ::insert(size_t position, const T &x) {
    if (count >= arraySize) {
        arraySize = (arraySize == 0) ? 256 : arraySize * 2;
        //cout << "arraySize: " << arraySize;
        T *temp = new T[arraySize];
        for (size_t i = 0; i < size(); i++)
            temp[i] = elems[i];

        delete[] elems;
        elems = temp;
    }
    if (position == count) {
        elems[position] = x;
    } else {

        for (size_t i = 0; i <= count - position - 1; i++) {
            elems[count - i] = elems[count - i - 1];
        }
        elems[position] = x;
    }
    count++;
}

void ArrayList::push_back(const T &x) {
    return insert(count, x);
}

void ArrayList ::erase(size_t position) {
    size_t i;
    for (i = position + 1; i < count; i++) {
        elems[i - 1] = elems[i];
    }
    count--;
    return;
}
