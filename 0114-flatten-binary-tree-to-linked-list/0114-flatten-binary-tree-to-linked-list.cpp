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
TreeNode* nextright = NULL;
void helper(TreeNode* node){
    
    if(node == NULL) return;
    helper(node->right);
    helper(node->left);
    
    
    node->left = NULL;
    node->right = nextright;
    nextright = node;

}
    void flatten(TreeNode* root) {
        helper(root);
    }
};