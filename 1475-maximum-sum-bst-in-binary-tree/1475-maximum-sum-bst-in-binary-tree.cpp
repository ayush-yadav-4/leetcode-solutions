/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Node {
public:
    int sum, maxVal, minVal;
    bool isBST;
    Node(int sum, int maxVal, int minVal, bool isBST) {
        this->sum = sum;
        this->maxVal = maxVal;
        this->minVal = minVal;
        this->isBST = isBST;
    }
};

class Solution {
public:
    int maxsum = 0;

    Node checkBST(TreeNode* root) {
        if (root == NULL) return Node(0, INT_MIN, INT_MAX, true);

        auto left = checkBST(root->left);
        auto right = checkBST(root->right);

        if (left.isBST && right.isBST && left.maxVal < root->val && root->val < right.minVal) {
            int sum = left.sum + right.sum + root->val;
            maxsum = max(sum, maxsum);
            return Node(sum, max(root->val, right.maxVal), min(root->val, left.minVal), true);
        }
        return Node(0, 0, 0, false);
    }

    int maxSumBST(TreeNode* root) {
        checkBST(root);
        return maxsum;
    }
};
