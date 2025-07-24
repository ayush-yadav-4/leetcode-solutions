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
class Solution {
public:
int helper(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;
            maxWidth = max(maxWidth, (int)(right - left + 1));
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front().first;
                unsigned long long idx = q.front().second - left; // normalize to avoid overflow
                q.pop();
                
                if (node->left) q.push({node->left, 2 * idx + 1});
                if (node->right) q.push({node->right, 2 * idx + 2});
            }
        }
        
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) {
       return helper(root); 
    }
};