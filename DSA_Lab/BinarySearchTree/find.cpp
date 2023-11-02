#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value);
    void add(T value);
    bool findh(Node* root, T i) {
        if (!root) return false;
        if (root->value == i) return true;

        return (findh(root->pLeft, i) || findh(root->pRight, i));
    }

    bool find(T i) {
        return findh(this->root, i);
    }

    T sumh(Node* root, T l, T r) {
        if (!root) return 0;
        T s = 0;
        if (root->value >= l && root->value <= r) s += root->value;

        s += sumh(root->pLeft, l, r);
        s += sumh(root->pRight, l, r);

        return s;
    }

    T sum(T l, T r) {
        return sumh(this->root, l, r);
    }
};

int main()
{
}
