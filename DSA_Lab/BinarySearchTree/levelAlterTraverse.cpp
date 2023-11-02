#include <iostream>
#include <vector>
#include <queue>

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

vector<int> levelAlterTraverse(BSTNode* root) {
    // STUDENT ANSWER
    if (!root) return {};

    queue<BSTNode*> node;
    vector<BSTNode*> tem;
    vector<int> rs;

    node.push(root);
    bool rever = false;
    while (!node.empty()) {
        int n = node.size();
        for (int i = 0; i < n; i++) {
            tem.push_back(node.front());
            if (node.front()->left) node.push(node.front()->left);
            if (node.front()->right) node.push(node.front()->right);
            node.pop();
        }
        for (int i = 0; i < n; i++) {
            rs.push_back(tem[rever ? n - i - 1 : i]->val);
        }
        tem = {};
        rever = !rever;
    }
    return rs;
}

int main()
{
}