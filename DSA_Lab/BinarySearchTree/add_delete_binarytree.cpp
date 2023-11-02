#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
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

    //Helping function

    void add(T value) {
        this->root = addRec(this->root, value);
    }

    Node* addRec(Node* root, T value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value <= root->value) {
            root->pLeft = addRec(root->pLeft, value);
        }
        else if (value > root->value) {
            root->pRight = addRec(root->pRight, value);
        }
        return root;
    }


    void deleteNode(T value) {
        this->root = deleteNodeRec(this->root, value);
    }

    Node* deleteNodeRec(Node* root, T value) {
        if (root == nullptr) {
            return root;
        }
        if (value < root->value) {
            root->pLeft = deleteNodeRec(root->pLeft, value);
        }
        else if (value > root->value) {
            root->pRight = deleteNodeRec(root->pRight, value);
        }
        else {
            if (root->pLeft == nullptr) {
                Node* temp = root->pRight;
                delete root;
                return temp;
            }
            else if (root->pRight == nullptr) {
                Node* temp = root->pLeft;
                delete root;
                return temp;
            }
            Node* temp = minValueNode(root->pRight);
            root->value = temp->value;
            root->pRight = deleteNodeRec(root->pRight, temp->value);
        }
        return root;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->pLeft != nullptr)
            current = current->pLeft;
        return current;
    }

    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }

    string inOrder() {
        return inOrderRec(this->root);
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
};



int main()
{
    std::cout << "Hello World!\n";
}