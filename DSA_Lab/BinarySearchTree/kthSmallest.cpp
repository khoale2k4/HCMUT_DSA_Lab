#include <iostream>
#include <vector>
#include <algorithm>

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

void getArr(BSTNode* root, vector<int>& arr) {
    if (!root) return;
    else arr.push_back(root->val);

    getArr(root->left, arr);
    getArr(root->right, arr);
}

int kthSmallest(BSTNode* root, int k) {
    vector<int> rs;
    getArr(root, rs);
    sort(rs.begin(), rs.end());
    return rs[k - 1];
}

int main()
{
    std::cout << "Hello World!\n";
}