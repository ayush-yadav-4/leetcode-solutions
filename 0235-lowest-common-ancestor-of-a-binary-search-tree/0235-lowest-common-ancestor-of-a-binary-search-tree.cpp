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
    TreeNode* search(TreeNode* root, TreeNode* p, TreeNode* q){
      if(root == NULL) return NULL;
    if(p->val < root->val && q->val < root->val) return search(root->left,p,q);
    if(p->val > root->val && q->val > root->val) return search(root->right,p,q);
    return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        return search(root,p,q);
        
    }
};