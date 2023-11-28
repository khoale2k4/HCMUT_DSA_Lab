#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    //Helping functions
    int getBalance(Node* N)
    {
        if (N == nullptr)
            return 0;
        return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
    }

    Node* maxValueNode(Node* node){
        if(!node) return nullptr;
        Node* curr = node;
        while(curr->pRight){
            curr = curr->pRight;
        }
        return curr;
    }
    Node* rightRotate(Node* y)
    {
        Node* x = y->pLeft;
        y->pLeft = x->pRight;
        x->pRight = y;
        return x;
    }
    Node* leftRotate(Node* x)
    {
        Node* y = x->pRight;
        x->pRight = y->pLeft;
        y->pLeft = x;
        return y;
    }
    Node* deleteNode(Node* root, int key)
    {
        if (root == nullptr)
            return root;
        if (key < root->data)
            root->pLeft = deleteNode(root->pLeft, key);
        else if (key > root->data)
            root->pRight = deleteNode(root->pRight, key);
        else
        {
            if ((root->pLeft == NULL) ||
                (root->pRight == NULL))
            {
                Node* temp = root->pLeft ?
                    root->pLeft :
                    root->pRight;

                if (temp == NULL)
                {
                    temp = root;
                    root = NULL;
                }
                else  
                    *root = *temp;
                delete temp;
            }
            else
            {
                Node* temp = maxValueNode(root->pLeft);
                root->data = temp->data;
                root->pLeft = deleteNode(root->pLeft, temp->data);
            }
        }
        if (root == nullptr)
            return root; 
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->pLeft) >= 0)
            return rightRotate(root);
            
        if (balance > 1 && getBalance(root->pLeft) < 0)
        {
            root->pLeft = leftRotate(root->pLeft);
            return rightRotate(root);
        }
        
        if (balance < -1 &&  getBalance(root->pRight) <= 0)
            return leftRotate(root);

        if (balance < -1 && getBalance(root->pRight) > 0)
        {
            root->pRight = rightRotate(root->pRight);
            return leftRotate(root);
        }

        return root;
    }
    void remove(const T& value)
    {
        // TODO
        this->root = deleteNode(root, value);
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

int main(){

}