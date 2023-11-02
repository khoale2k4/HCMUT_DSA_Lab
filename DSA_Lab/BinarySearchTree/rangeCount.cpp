#include <iostream>

using namespace std;

class BTNode {
public:
    int val;
    BTNode* left;
    BTNode* right;
    BTNode() {
        this->left = this->right = NULL;
    }
    BTNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
    BTNode(int val, BTNode*& left, BTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

int rangeCount(BTNode* root, int lo, int hi) {
    if (!root) return 0;

    int s = 0;
    if (root->val <= hi && root->val >= lo) s++;
    s += rangeCount(root->left, lo, hi);
    s += rangeCount(root->right, lo, hi);

    return s;
}

int main()
{
}