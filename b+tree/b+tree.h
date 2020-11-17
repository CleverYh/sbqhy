#ifndef __BPLUSTREE_H__
#define __BPLUSTREE_H__

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

#define M 4
//二叉树的阶
#define L 6
//叶中存储数据数

const int MINKEY = ceil(M / 2);
const int MAXKEY = M;
const int MINCHILD = MINKEY + 1;
const int MAXCHILD = MAXKEY + 1;
const int MINLEAF = ceil(L / 2);
const int MAXLEAF = L;

typedef int keyType;
//key类型值为int
typedef double dataType;
typedef pair<keyType, dataType> retData;

enum NodeType { Internal,
                Leaf }; //标注该节点为内部节点或叶节点

enum broSide { Left,
               Right }; //兄弟节点的方向

class Node { //基类
protected:
    NodeType nType;  //节点类型
    int keyNum;      //当前键数
    keyType keys[M]; //键数组

public:
    Node(NodeType NT) : nType(NT) {}
    virtual ~Node() {}

    NodeType getType() const { return nType; }
    void setType(NodeType type) { nType = type; }
    int getKeyNum() const { return keyNum; }
    void setKeyNum(int n) { keyNum = n; }
    keyType getKeyValue(int i) const { return keys[i]; }
    void setKeyValue(int i, keyType key) { keys[i] = key; }
    int getKeyIndex(keyType key) const { // 找到键值在结点中存储的下标
        int left = 0;
        int right = getKeyNum() - 1;
        int current;
        while (left != right) {
            current = (left + right) / 2;
            keyType currentKey = getKeyValue(current);
            if (key > currentKey) {
                left = current + 1;
            } else {
                right = current;
            }
        }
        return left;
    }
    //纯虚函数
    virtual bool getChildIndex(keyType key, int keyIndex) const = 0;                   //搜索根据键值获取孩子结点指针下标
    virtual void remove(int keyIndex, int childIndex) = 0;                             //移除
    virtual void split(Node *parentNode, int childIndex) = 0;                          //分裂
    virtual void merge(Node *parentNode, Node *childNode, int keyIndex) = 0;           //合并
    virtual void borrow(Node *broNode, Node *parentNode, int keyIndex, broSide s) = 0; //向兄弟借
    virtual void clear() = 0;                                                          // 清空结点，同时会清空结点所包含的子树结点
};

class InternalNode : public Node { //内部节点
    Node *children[M];             //可能指向内部节点，也可能指向叶节点

public:
    InternalNode() : Node(Internal) {}
    virtual ~InternalNode() {}

    Node *getChild(int i) const { return children[i]; }
    void setChild(int i, Node *child) { children[i] = child; }
    void insert(int keyIndex, int childIndex, keyType key, Node *childNode) {
        for (int i = getKeyNum(); i >= keyIndex; i--) {
            setChild(i + 1, children[i]);
            if (i != childIndex) setKeyValue(i, keys[i - 1]);
        }

        setChild(childIndex, childNode);
        setKeyValue(keyIndex, key);
        setKeyNum(keyNum++);
    }
    virtual bool getChildIndex(keyType key, int keyIndex) const {
        if (key == getKeyValue(keyIndex))
            return keyIndex + 1;
        else
            return keyIndex;
    }
    virtual void split(Node *parentNode, int childIndex) {
        InternalNode *newNode = new InternalNode();
        newNode->setKeyNum(MINKEY);
        for (int i = 0; i < MINKEY; i++) newNode->setKeyValue(i, keys[i + MINCHILD]);
        for (int i = 0; i < MINCHILD; i++) newNode->setChild(i, children[i + MINCHILD]);
        setKeyNum(MINKEY);
        ((InternalNode *)parentNode)->insert(childIndex, childIndex + 1, keys[MINKEY], newNode);
    }
    virtual void merge(Node *parentNode, Node *childNode, int keyIndex) {
        insert(MINKEY, MINKEY + 1, parentNode->getKeyValue(keyIndex), ((InternalNode *)childNode)->getChild(0));
        for (int i = 0; i <= childNode->getKeyNum(); i++) insert(MINKEY + i, MINKEY + 1 + i, childNode->getKeyValue(i - 1), ((InternalNode *)childNode)->getChild(i));

        parentNode->remove(keyIndex, keyIndex + 1);
        delete ((InternalNode *)parentNode)->getChild(keyIndex + 1);
    }
    virtual void remove(int keyIndex, int childIndex) {
        for (int i = 0; i < getKeyNum() - keyIndex - 1; i++) {
            setKeyValue(keyIndex + i, getKeyValue(keyIndex + i + 1));
            setChild(childIndex + i, getChild(childIndex + i + 1));
        }
        setKeyNum(getKeyNum() - 1);
    }
    virtual void borrow(Node *broNode, Node *parentNode, int keyIndex, broSide s) {
        if (s) { // s == Right
            insert(getKeyNum(), getKeyNum() + 1, parentNode->getKeyValue(keyIndex), ((InternalNode *)broNode)->getChild(0));
            parentNode->setKeyValue(keyIndex, broNode->getKeyValue(0));
            broNode->remove(0, 0);
        } else { // s == Left
            insert(0, 0, parentNode->getKeyValue(keyIndex), ((InternalNode *)broNode)->getChild(broNode->getKeyNum()));
            parentNode->setKeyValue(keyIndex, broNode->getKeyValue(broNode->getKeyNum() - 1));
            broNode->remove(broNode->getKeyNum() - 1, broNode->getKeyNum());
        }
    }
    virtual void clear() {
        for (int i = 0; i <= keyNum; i++) {
            children[i]->clear();
            delete children[i];
            children[i] = NULL;
        }
    }
};

class LeafNode : public Node { //叶节点
    LeafNode *leftSibling;     //左兄弟
    LeafNode *rightSibling;    //右兄弟
    dataType data[L];          //存储的数据

public:
    LeafNode() : Node(Leaf) {}
    virtual ~LeafNode() {}

    LeafNode *getLeft() const { return leftSibling; }   //返回左兄弟节点
    LeafNode *getRight() const { return rightSibling; } //返回右兄弟节点
    void setLeft(LeafNode *ls) { leftSibling = ls; }    //设置左兄弟节点
    void setRight(LeafNode *rs) { rightSibling = rs; }  //设置右兄弟节点
    dataType getData(int i) const { return data[i]; }
    void setData(int i, const dataType &d) { data[i] = d; }
    void insert(keyType key, const dataType &d) {
        int i = getKeyNum();
        for (; i >= 1 && keys[i - 1] > key; i--) { //数据后挪
            setKeyValue(i, keys[i - 1]);
            setData(i, data[i - 1]);
        }
        setKeyValue(i, key);
        setData(i, d);
        setKeyNum(keyNum + 1);
    }
    virtual bool getChildIndex(keyType key, int keyIndex) const { return keyIndex; }
    virtual void split(Node *parentNode, int childIndex) {
        LeafNode *newNode = new LeafNode();
        setKeyNum(MINLEAF);
        newNode->setKeyNum(MINLEAF + 1);
        newNode->setRight(getRight());
        newNode->setLeft(this);
        setRight(newNode);
        for (int i = 0; i < MINLEAF + 1; i++) newNode->setKeyValue(i, keys[i + MINLEAF]);
        for (int i = 0; i < MINLEAF + 1; i++) newNode->setData(i, data[i + MINLEAF]);
        ((InternalNode *)parentNode)->insert(childIndex, childIndex + 1, keys[MINLEAF], newNode);
    }
    virtual void merge(Node *parentNode, Node *childNode, int keyIndex) {
        for (int i = 0; i < childNode->getKeyNum(); i++) insert(childNode->getKeyValue(i), ((LeafNode *)childNode)->getData(i));
        setRight(((LeafNode *)childNode)->getRight());
        parentNode->remove(keyIndex, keyIndex + 1);
    }
    virtual void remove(int keyIndex, int childIndex) {
        for (int i = keyIndex; i < getKeyNum() - 1; i++) {
            setKeyValue(i, getKeyValue(i + 1));
            setData(i, getData(i + 1));
        }
        setKeyNum(getKeyNum() - 1);
    }
    virtual void borrow(Node *broNode, Node *parentNode, int keyIndex, broSide s) {
        if (s) { // s == Right
            insert(broNode->getKeyValue(0), ((LeafNode *)broNode)->getData(0));
            parentNode->setKeyValue(keyIndex, broNode->getKeyValue(0));
            broNode->remove(0, 0);
        } else { // s == Left
            insert(broNode->getKeyValue(broNode->getKeyNum() - 1), ((LeafNode *)broNode)->getData(broNode->getKeyNum() - 1));
            parentNode->setKeyValue(keyIndex, broNode->getKeyValue(broNode->getKeyNum() - 1));
            broNode->remove(broNode->getKeyNum() - 1, broNode->getKeyNum());
        }
    }
    virtual void clear() {}
};

class BPlusTree {
public:
    BPlusTree() {
        root = NULL;
        dataHead = NULL;
    }
    ~BPlusTree() { clear(); }

    bool insert(keyType key, const dataType &data) { return p_insert(key, data); } // 插入
    bool remove(keyType key) { return p_remove(key); }                             // 删除
    bool search(keyType key) { return rec_search(key, root); }                     // 查找
    retData accessData(keyType key) { return rec_access(key, root); }

private:
    void clear() {
        if (root != NULL) {
            root->clear();
            delete root;
            root = NULL;
            dataHead = NULL;
        }
    }

    void changeKey(Node *pNode, keyType oldKey, keyType newKey) {
        if (pNode != NULL && pNode->getType() != Leaf) {
            int keyIndex = pNode->getKeyIndex(oldKey);
            if (keyIndex < pNode->getKeyNum() && oldKey == pNode->getKeyValue(keyIndex)) // 找到
                pNode->setKeyValue(keyIndex, newKey);
            else // 继续找
                changeKey(((InternalNode *)pNode)->getChild(keyIndex), oldKey, newKey);
        }
    }

    bool rec_search(keyType key, Node *pNode) const {
        if (pNode == NULL) { //检测节点指针是否为空，或该节点是否为叶子节点
            return false;
        } else {
            int keyIndex = pNode->getKeyIndex(key);
            int childIndex = pNode->getChildIndex(key, keyIndex); // 孩子结点指针索引
            if (keyIndex < pNode->getKeyNum() && key == pNode->getKeyValue(keyIndex)) {
                return true;
            } else {
                if (pNode->getType() == Leaf) //检查该节点是否为叶子节点
                    return false;
                else
                    return rec_search(key, ((InternalNode *)pNode)->getChild(childIndex));
            }
        }
    }

    retData rec_access(keyType key, Node *pNode) const {
        if (pNode == NULL) { //检测节点指针是否为空，或该节点是否为叶子节点
            cout << "DO NOT EXITS" << endl;
        } else {
            int keyIndex = pNode->getKeyIndex(key);
            int childIndex = pNode->getChildIndex(key, keyIndex); // 孩子结点指针索引
            if (keyIndex < pNode->getKeyNum() && key == pNode->getKeyValue(keyIndex)) {
                return make_pair(keyIndex, ((LeafNode *)pNode)->getData(keyIndex));
            } else {
                if (pNode->getType() == Leaf) //检查该节点是否为叶子节点
                    cout << "DO NOT EXITS" << endl;
                else
                    return rec_access(key, ((InternalNode *)pNode)->getChild(childIndex));
            }
        }
    }

    bool p_insert(keyType key, const dataType &data) {
        // 是否已经存在
        if (search(key)) return false;
        // 找到可以插入的叶子结点，否则创建新的叶子结点
        if (root == NULL) {
            root = new LeafNode();
            dataHead = (LeafNode *)root;
            maxKey = key;
        }
        if (root->getKeyNum() >= MAXKEY) {              // 根结点已满，分裂
            InternalNode *newNode = new InternalNode(); //创建新的根节点
            newNode->setChild(0, root);
            root->split(newNode, 0); // 叶子结点分裂
            root = newNode;          //更新根节点指针
        }
        if (key > maxKey) { // 更新最大键值
            maxKey = key;
        }
        rec_insert(root, key, data);
        return true;
    }
    void rec_insert(Node *parentNode, keyType key, const dataType &data) {
        if (parentNode->getType() == Leaf) { // 叶子结点，直接插入
            ((LeafNode *)parentNode)->insert(key, data);
        } else {
            // 找到子结点
            int keyIndex = parentNode->getKeyIndex(key);
            int childIndex = parentNode->getChildIndex(key, keyIndex); // 孩子结点指针索引
            Node *childNode = ((InternalNode *)parentNode)->getChild(childIndex);
            if (childNode->getKeyNum() >= MAXLEAF) { // 子结点已满，需进行分裂
                childNode->split(parentNode, childIndex);
                if (parentNode->getKeyValue(childIndex) <= key) // 确定目标子结点
                    childNode = ((InternalNode *)parentNode)->getChild(childIndex + 1);
            }
            rec_insert(childNode, key, data);
        }
    }

    bool p_remove(keyType key) {
        if (!search(key)) //不存在
        {
            return false;
        }
        if (root->getKeyNum() == 1) //特殊情况处理
        {
            if (root->getType() == Leaf) {
                clear();
                return true;
            } else {
                Node *pChild1 = ((InternalNode *)root)->getChild(0);
                Node *pChild2 = ((InternalNode *)root)->getChild(1);
                if (pChild1->getKeyNum() == MINKEY && pChild2->getKeyNum() == MINKEY) {
                    pChild1->merge(root, pChild2, 0);
                    delete root;
                    root = pChild1;
                }
            }
        }
        rec_remove(key, root);
        return true;
    }
    void rec_remove(keyType key, Node *parentNode) {
        int keyIndex = parentNode->getKeyIndex(key);
        int childIndex = parentNode->getChildIndex(key, keyIndex); // 孩子结点指针索引
        if (parentNode->getType() == Leaf) {                       // 找到目标叶子节点
            if (key == maxKey && keyIndex > 0)
                maxKey = parentNode->getKeyValue(keyIndex - 1);
            parentNode->remove(keyIndex, childIndex); // 直接删除
            // 如果键值在内部结点中存在，也要相应的替换内部结点
            if (childIndex == 0 && root->getType() != Leaf && parentNode != dataHead)
                changeKey(root, key, parentNode->getKeyValue(0));
        } else {                                                                                                                     // 内结点
            Node *pChildNode = ((InternalNode *)parentNode)->getChild(childIndex);                                                   //包含key的子树根节点
            if (pChildNode->getKeyNum() == MINKEY) {                                                                                 // 包含关键字达到下限值，进行相关操作
                Node *pLeft = childIndex > 0 ? ((InternalNode *)parentNode)->getChild(childIndex - 1) : NULL;                        //左兄弟节点
                Node *pRight = childIndex < parentNode->getKeyNum() ? ((InternalNode *)parentNode)->getChild(childIndex + 1) : NULL; //右兄弟节点
                // 先考虑从兄弟结点中借
                if (pLeft && pLeft->getKeyNum() > MINKEY) { // 左兄弟结点可借
                    pChildNode->borrow(pLeft, parentNode, childIndex - 1, Left);
                } else if (pRight && pRight->getKeyNum() > MINKEY) { //右兄弟结点可借
                    pChildNode->borrow(pRight, parentNode, childIndex, Right);
                }
                //左右兄弟节点都不可借，考虑合并
                else if (pLeft) { //与左兄弟合并
                    pLeft->merge(parentNode, pChildNode, childIndex - 1);
                    pChildNode = pLeft;
                } else if (pRight) { //与右兄弟合并
                    pChildNode->merge(parentNode, pRight, childIndex);
                }
            }
            rec_remove(key, pChildNode);
        }
    }

    Node *root;
    LeafNode *dataHead;
    keyType maxKey;
};

#endif /*__BPLUSTREE_H__*/