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
 
   void helper(TreeNode*& root,TreeNode*& prev,TreeNode*& first,TreeNode*& sec){
    if(root == NULL) return;
      helper(root->left,prev,first,sec);
      if(prev != NULL && root->val < prev->val){
         if(first == NULL){
            first = prev;
         }
         sec = root;
      }
      prev = root;
      helper(root->right,prev,first,sec);

   }
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;TreeNode* sec = NULL;
        helper(root,prev,first,sec);
        if(first != NULL && sec != NULL){
            swap(first->val,sec->val);
        }
       
        
    }
};