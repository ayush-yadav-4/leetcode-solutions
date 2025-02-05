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

  void right(TreeNode* temp,vector<int>&arr,int level){
    if(temp == NULL)return;
    if(level == arr.size()) arr.push_back(temp->val);
    right(temp->right,arr,level+1);
    right(temp->left,arr,level+1);

  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>arr;
        right(root,arr,0);
        return arr;
    }
};