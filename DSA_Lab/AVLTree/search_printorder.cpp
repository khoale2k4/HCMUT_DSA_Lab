#include <iostream>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}

    bool h_search(Node* node, T value){
        if(!node) return false;
        
        if(node->data == value) return true;
        int right = h_search(node->pRight, value);
        int left = h_search(node->pLeft, value);
        
        return max(right, left);
    }

    bool search(T value){
        return h_search(this->root, value);
    }

    void h_printInorder(Node* node){
        if(!node) return;
        
        h_printInorder(node->pLeft);
        cout << node->data << " ";
        h_printInorder(node->pRight);
    }

    void printInorder(){
        h_printInorder(this->root);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};