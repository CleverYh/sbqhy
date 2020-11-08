#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

typedef int T;
class ArrayList {
   public:
    ArrayList();//construct an empty list
    ArrayList(size_t n);//construct a list of size n
    ~ArrayList();
    ArrayList(const ArrayList & c);
    const ArrayList& operator = (ArrayList & c);
    size_t size() const; //返回线性表中元素个数
    size_t capacity()const;//返回数组的容量
    bool empty() const; //如果表空，返回true, 否则，返回false.
    void clear(); //将表置为空表。
    void traverse(void (*visit)(T &));
    //将函数 (*visit)应用到表中每个元素上。
    void retrieve(size_t position, T &x) const;
    //如果0=<position<=size()-1, 则用x返回位于position的元素
    //否则，动作为空.
    void replace(size_t position, const T &x);
    //如果0=<position<=size()-1, 则将位置position的元素修改成x.
    //否则，动作为空.
    void erase(size_t position, T &x);
    //如果0=<position<=size()-1, 则将位置position的元素删除，
    //并将删除的元素用x返回，否则，动作为空.
    void erase(size_t position);
    T & operator [] (size_t position);
    //如果0=<position<=size()-1, 则返回位于position的元素
    //否则，动作为空.
    void push_back(const T &x);//put x after the last item 
    void insert(size_t position, const T &x);
    //如果0=<position<=size(), 则将x插入到位置position.
    //否则，动作为空.
  private:
    T *elems;
    size_t count; //记录数组elems中存储的元素个数
    size_t arraySize;//数组长度
};
#endif