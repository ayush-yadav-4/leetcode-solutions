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
void insert(TreeNode* root, int val){
 if(root == NULL){
    
    return;}
  if(val < root->val && root->left!= NULL) return insert(root->left,val);
   else if(val > root->val && root->right!= NULL) return insert(root->right,val);
 
    TreeNode* node = new TreeNode(val);
    if(val < root->val) root->left = node;
    else root->right = node;
    return;
 
  

}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         if(root == NULL){
     return new TreeNode(val);
   }
        insert(root,val);
        return root;
    }
};