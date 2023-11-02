#include <iostream>

using namespace std;

class BTNode {
public:
    int val;
    BTNode* left;
    BTNode* right;
    BTNode() {
        this->left = this->right = nullptr;
    }
    BTNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
    BTNode(int val, BTNode*& left, BTNode*& right) {
        this->val = val;
        this->left = left;
        this->right = right;
    }
};

void maxsum(BTNode* root, int sum, int len, int& maxSum, int& maxLen) {
    if (!root) {
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        }
        else if (maxLen == len && maxSum < sum) {
            maxSum = sum;
        }
        return;
    }
    maxsum(root->left, sum + root->val, len + 1, maxSum, maxLen);
    maxsum(root->right, sum + root->val, len + 1, maxSum, maxLen);
}

int longestPathSum(BTNode* root) {
    if (!root) return 0;
    int maxSum = -999999;
    int maxLen = 0;
    maxsum(root, 0, 0, maxSum, maxLen);
    return maxSum;
}

BTNode* lowestCommonAncestor(BTNode* root, int a, int b) {
    if (!root) {
        return nullptr;
    }

    if (root->val == a || root->val == b) {
        return root;
    }

    BTNode* leftLCA = lowestCommonAncestor(root->left, a, b);
    BTNode* rightLCA = lowestCommonAncestor(root->right, a, b);

    if (leftLCA && rightLCA) {
        return root;
    }

    return (leftLCA) ? leftLCA : rightLCA;
}

int lowestAncestor(BTNode* root, int a, int b) {
    BTNode* lca = lowestCommonAncestor(root, a, b);
    return lca->val;
}

int sumDigitPath(BTNode* root, int cursum = 0) {
    if (!root) {
        return 0;
    }

    cursum = (cursum * 10 + root->val) % 27022001;

    if (root->left == nullptr && root->right == nullptr) {
        return cursum;
    }

    int t = 0;
    if (root->left) t += sumDigitPath(root->left, cursum);
    t %= 27022001;
    if (root->right) t += sumDigitPath(root->right, cursum);
    t %= 27022001;
    return t;
}

int main()
{
}
