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
void PreOrder(TreeNode* temp,vector<int>&ans){
  if(temp == NULL)return;

  PreOrder(temp->left,ans);
   PreOrder(temp->right,ans);
   ans.push_back(temp->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        PreOrder(root,ans);
        return ans;
    }
};