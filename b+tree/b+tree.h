#define M 4
//二叉树的阶

#define L 6
//叶中存储数据数

typedef int keyType;
//key类型值为int

enum NodeType { Internal,
                Leaf }; //标注该节点为内部节点或叶节点

class Node { //基类
    NodeType nType;
    int keyNum;      //当前键数
    keyType keys[M]; //键数组

public:
    Node(NodeType NT):nType(NT){};
    virtual ~Node();

    //纯虚函数
    virtual bool search() = 0; //搜索
    virtual void remove() = 0; //移除
    virtual void split() = 0;  //分裂
    virtual void merge() = 0;  //合并
    virtual void borrow() = 0; //向兄弟借
};

class internalNode : public Node { //内部节点
    Node *children[M];             //可能指向内部节点，也可能指向叶节点

public:
    void insert();
    virtual bool search();
    virtual void split();
    virtual void merge();
    virtual void remove();
    virtual void borrow();
};

class LeafNode : public Node { //叶节点
    LeafNode *leftSibling;     //左兄弟
    LeafNode *rightSibling;    //右兄弟
    keyType data[L];           //存储的数据

public:
    LeafNode();
    virtual ~LeafNode();

    LeafNode *getLeft();  //返回左兄弟节点
    LeafNode *getRight(); //返回右兄弟节点
    virtual void split();
    virtual bool search();
    void insert(); //插入
    virtual void merge();
    virtual void remove();
    virtual void borrow();
};