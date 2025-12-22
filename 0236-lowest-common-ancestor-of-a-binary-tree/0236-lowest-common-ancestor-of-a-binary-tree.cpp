/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
   TreeNode* helper(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL) return NULL;

        if(node == p || node == q) return node;
        TreeNode* left = helper(node->left,p,q);
        TreeNode* right = helper(node->right,p,q);

        if(left && right){
            return node;
        }
        else if(left == NULL){
            return right;
        }
        else{
            return left;
        }
   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};