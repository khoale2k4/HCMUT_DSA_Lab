#include <iostream>

using namespace std;

class BSTNode {
public:
    int val;
    BSTNode* left;
    BSTNode* right;
    BSTNode() {
        this->left = this->right = nullptr;
    }
    BSTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BSTNode(int val, BSTNode*& left, BSTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int singleChild(BSTNode* root) {
    if (!root) return 0;

    int s = 0;
    if ((!root->left && root->right) || (root->left && !root->right))s++;

    s += singleChild(root->left);
    s += singleChild(root->right);

    return s;
}

int main()
{
}
