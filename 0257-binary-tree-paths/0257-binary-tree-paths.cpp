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
  void helper(TreeNode* root,string str, vector<string>&ans){
    if(root->left == NULL && root->right == NULL){
           str += to_string(root->val);
        ans.push_back(str);
        str = "";
        return;
    }
    str += to_string(root->val);
    str += "->";
    if(root->left!= NULL)helper(root->left,str,ans);
    if(root->right != NULL)helper(root->right,str,ans);
    

  }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        helper(root,"",ans);
        return ans;
    }
};