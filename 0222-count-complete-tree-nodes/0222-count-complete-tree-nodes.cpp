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
void Count(TreeNode*temp,int* ptr){
  if(temp == NULL) return;
    (*ptr)++;
  Count(temp->left,ptr);
  Count(temp->right,ptr);
}
    int countNodes(TreeNode* root) {
       int count=0;
        Count(root,&count);
        return count;
    }
};