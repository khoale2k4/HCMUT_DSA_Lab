#include <iostream>

using namespace std;

class SplayTree {
    struct Node {
        int val;
        Node* pLeft;
        Node* pRight;
        Node* pParent;
        Node(int val = 0, Node* l = nullptr, Node* r = nullptr, Node* par = nullptr) : val(val), pLeft(l), pRight(r), pParent(par) { }
    };
    Node* root;

    // print the tree structure for local testing
    void printBinaryTree(string prefix, const Node* root, bool isLeft, bool hasRightSibling) {
        if (!root && isLeft && hasRightSibling) {
            cout << prefix << "├──\n";
        }
        if (!root) return;
        cout << prefix;
        if (isLeft && hasRightSibling) 
            cout << "├──";
        else 
            cout << "└──";
        cout << root->val << '\n';
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pLeft, true, root->pRight);
        printBinaryTree(prefix + (isLeft && hasRightSibling ? "|  " : "   "), root->pRight, false, root->pRight);
    }

    void printPreorder(Node* p) {
        if (!p) {
            return;
        }
        cout << p->val << ' ';
        printPreorder(p->pLeft);
        printPreorder(p->pRight);
    }
public:
    SplayTree() {
        root = nullptr;
    }
    ~SplayTree() {
        // Ignore deleting all nodes in the tree
    }
    void printBinaryTree() {
        printBinaryTree("", root, false, false);
    }
    void printPreorder() {
        printPreorder(root);
        cout << "\n";
    }
    void splay(Node* p);
    void insert(int val);
    bool search(int val);
    Node* remove(int val){
        //TODO
        if (!root) return nullptr;
        
        search(val);
        
        if (root->val != val) return nullptr;
        
        Node* removedNode = root;
        
        Node* leftSubTree = root->pLeft;
        Node* rightSubTree = root->pRight;
        
        if (!leftSubTree) {
            root = rightSubTree;
            
            if (root) root->pParent = nullptr;
        }
        else {
            Node* largestInLeft = leftSubTree;
            
            while (largestInLeft->pRight) {
                largestInLeft = largestInLeft->pRight;
            }
            
            splay(largestInLeft);
            
            largestInLeft->pRight = rightSubTree;
            
            root = largestInLeft;
            
            if (rightSubTree) rightSubTree->pParent = largestInLeft;
        }
        
        removedNode->pLeft = nullptr;
        removedNode->pRight = nullptr;
        removedNode->pParent = nullptr;
        
        return removedNode;
    }
};