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

    T gmin(Node* root) {
        if (!root) return 9999;
        T rs = root->value;
        rs = min(rs, min(gmin(root->pLeft), gmin(root->pRight)));
        return rs;
    }
    T getMin() {
        return gmin(this->root);
    }

    T gmax(Node* root) {
        if (!root) return -9999;
        T rs = root->value;
        rs = max(rs, max(gmax(root->pLeft), gmax(root->pRight)));
        return rs;
    }
    T getMax() {
        return gmax(this->root);
    }
};
int main()
{
}