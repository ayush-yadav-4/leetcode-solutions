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
int check(TreeNode*left,TreeNode*right){
    if(left == NULL && right == NULL) return 0;
    if((left == NULL && right != NULL) || (left !=NULL && right == NULL))    return -1;
    if(left->val != right->val) return -1;
    int a = check(left->left,right->right);
    int b = check(left->right,right->left);

    if(a== -1 || b == -1) return -1;
    return 0;


}
    bool isSymmetric(TreeNode* root) {
        if(check(root->left,root->right) == -1)return false;
        return true;
    }
};