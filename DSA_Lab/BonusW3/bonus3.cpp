#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

class BTNode {
public:
    int val;
    BTNode* left;
    BTNode* right;
    BTNode() {
        val = 0;
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

bool isLeaf(BTNode* node) {
    return (node != nullptr && node->left == nullptr && node->right == nullptr);
}

int distinctParities(BTNode* root) {
    if (root == nullptr) {
        return 0;
    }

    stack<BTNode*> s;
    s.push(root);

    int countPNodes = 0;

    while (!s.empty()) {
        BTNode* current = s.top();
        s.pop();

        if (current->left && current->right) {
            int leftSum = 0, rightSum = 0;
            queue<BTNode*> q;
            q.push(current->left);

            while (!q.empty()) {
                BTNode* temp = q.front();
                q.pop();
                leftSum += temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            q.push(current->right);

            while (!q.empty()) {
                BTNode* temp = q.front();
                q.pop();
                rightSum += temp->val;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
            }

            if (leftSum % 2 != rightSum % 2) {
                countPNodes++;
            }
        }

        if (current->left) {
            s.push(current->left);
        }
        if (current->right) {
            s.push(current->right);
        }
    }

    return countPNodes;
}

int sum(BTNode* node, int& s) {
    if (!node) {
        return 0;
    }

    int right = sum(node->right, s);

    int ori = node->val;
    node->val += s;
    s += ori;

    int left = sum(node->left, s);

    return left + ori + right;
}

BTNode* enlarge(BTNode* root) {
    int s = 0;
    sum(root, s);
    return root;
}

void inorder(BTNode* root, vector<int>& nums) {
    if (root == nullptr) return;
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
}

bool findTarget(BTNode* root, int k) {
    vector<int> nums;
    inorder(root, nums);
    for (int i = 0, j = nums.size() - 1; i < j;) {
        if (nums[i] + nums[j] == k)
            return true;
        (nums[i] + nums[j] < k) ? i++ : j--;
    }
    return false;
}

int inRange(BTNode* root, int lo, int hi) {
    // STUDENT ANSWER
    if (!root) return 0;
    int rs = 0;
    rs += inRange(root->left, lo, hi);
    rs += inRange(root->right, lo, hi);
    if (root->val <= hi && root->val >= lo) rs++;
    return rs;
}

int countGreatAncestors(BTNode* node, int& count) {
    if (node == NULL)
        return -1000001;

    int leftMax = countGreatAncestors(node->left, count);
    int rightMax = countGreatAncestors(node->right, count);

    if (node->val >= max(leftMax, rightMax))
        count++;

    return max(node->val, max(leftMax, rightMax));
}

int greatAncestor(BTNode* root) {
    int count = 0;
    countGreatAncestors(root, count);
    return count;
}

void dfs(BTNode* node, int curMin, int curMax, int& result) {
    if (node == nullptr) {
        return;
    }
    int val = node->val;
    result = max(result, max(abs(val - curMin), abs(curMax - val)));
    curMin = min(curMin, val);
    curMax = max(curMax, val);
    dfs(node->left, curMin, curMax, result);
    dfs(node->right, curMin, curMax, result);
}

int largestDiff(BTNode* root) {
    int result = 0;
    dfs(root, root->val, root->val, result);
    return result;
}


int main(){
}