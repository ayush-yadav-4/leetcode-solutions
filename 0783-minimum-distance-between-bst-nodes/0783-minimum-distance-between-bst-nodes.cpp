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
    void helper(TreeNode* root,TreeNode*& prev,int& diff){
        if(root==NULL){return;}
      
        helper(root->left,prev,diff);
         if(prev!= NULL) diff = min(diff, root->val - prev->val);
        prev = root;
        helper(root->right,prev,diff);
        
        return;

        
    }
    int minDiffInBST(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev = NULL;
         helper(root, prev,diff);
         return diff;

    }
};