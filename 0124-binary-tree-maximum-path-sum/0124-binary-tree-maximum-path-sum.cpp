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

int helper(TreeNode* root,int* ans){
    if(root == NULL) return 0;

    int left = max(0, helper(root->left, ans));   // ignore negative paths
        int right = max(0, helper(root->right, ans)); // ignore negative paths
    (*ans) = max((*ans),(left+right+root->val));
    return root->val + max(left,right); // choosing which path to shoose;
}
    int maxPathSum(TreeNode* root) {
      int ans = root->val;
     helper(root,&ans);
        return ans;
    }
};