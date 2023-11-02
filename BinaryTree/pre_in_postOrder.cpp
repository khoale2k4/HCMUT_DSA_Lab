#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;
private:
    Node* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }
    class Node
    {
    private:
        K key;
        V value;
        Node* pLeft, * pRight;
        friend class BinaryTree<K, V>;
    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }
        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }
    string getHeight() {
        return to_string(gh(this->root));
    }

    int gh(Node* node) {
        if (!node) {
            return 0;
        }
        else {
            int left = gh(node->pLeft);
            int right = gh(node->pRight);
            return 1 + max(left, right);
        }
    }

    string preOrder() {
        return preO(this->root);
    }

    string preO(Node* node) {
        if (!node) {
            return "";
        }
        string rs = to_string(node->value) + " ";
        rs += preO(node->pLeft);
        rs += preO(node->pRight);
        return rs;
    }

    string inOrder() {
        return inO(this->root);
    }

    string inO(Node* node) {
        if (!node) {
            return "";
        }
        string rs = inO(node->pLeft);
        rs += to_string(node->value) + " ";
        rs += inO(node->pRight);
        return rs;
    }

    string postOrder() {
        return postO(this->root);
    }

    string postO(Node* node) {
        if (!node) {
            return "";
        }
        string rs = postO(node->pLeft);
        rs += postO(node->pRight);
        rs += to_string(node->value) + " ";
        return rs;
    }

};

int main()
{
    std::cout << "Hello World!\n";
}
