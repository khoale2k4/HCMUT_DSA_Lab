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

BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (root == nullptr) {
        return nullptr;
    }

    root->left = subtreeWithRange(root->left, lo, hi);
    root->right = subtreeWithRange(root->right, lo, hi);

    if (root->val < lo) {
        BSTNode* rightSubtree = root->right;
        delete root;
        return rightSubtree;
    }
    else if (root->val > hi) {
        BSTNode* leftSubtree = root->left;
        delete root;
        return leftSubtree;
    }
    else {
        return root;
    }
}


int main()
{
}