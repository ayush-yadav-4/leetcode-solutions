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
int check(TreeNode*p,TreeNode*q){
  if(p == NULL && q == NULL) return 1;
  if((p == NULL && q != NULL) || (p!=NULL && q == NULL))return 0;

  if(p->val != q->val) return 0;
  int left = check(p->left,q->left);
  int right = check(p->right,q->right);
  if(left == 0 || right == 0) return 0;

  return left & right;



}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(check(p,q) == 0) return false;
        return true;
    }
};