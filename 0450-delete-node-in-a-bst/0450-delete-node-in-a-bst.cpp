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
TreeNode* rightmost(TreeNode* root){
  if(root->right == NULL)return root;

  return rightmost(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left == NULL){ // if no left child
        return root->right;
    }
    if(root->right == NULL){ // if no right child
        return root->left;
    }
   TreeNode* right = root->right;
   TreeNode* leftmost = rightmost(root->left);
   leftmost->right = right;
   return root->left;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL || root->right==NULL && root->left == NULL && root->val == key)return NULL;
        if(root->val == key){
            return helper(root);
            
        }
        TreeNode* dummy = root;
        while(root!= NULL){
            if(key<root->val){
          if(root->left != NULL && root->left->val == key){
            root->left = helper(root->left);
            return dummy;
          }
          else{
            root = root->left;
          }
            }
        
        else{
             if(root->right != NULL && root->right->val == key){
            root->right = helper(root->right);
            return dummy;
          }
          else{
            root = root->right;
          }
        }
        }
        return dummy;
    }
};