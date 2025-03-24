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
int size_of_tree(TreeNode* root){
    if(root == NULL) return 0;

    int left = size_of_tree(root->left);
    int right = size_of_tree(root->right);

    return 1+left+right;

}
bool check(TreeNode* root,int size,int idx){
   if(root == NULL)  return true;

   if(idx >=size) return false;
  
 
  return check(root->left,size,2*idx+1) &&
  check(root->right,size,2*idx+2);
   
}
    
    bool isCompleteTree(TreeNode* root) {
        int size = size_of_tree(root);
        return check(root,size,0);
    }
};