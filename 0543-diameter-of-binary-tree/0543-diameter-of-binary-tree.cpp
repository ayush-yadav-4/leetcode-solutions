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
 int diameter(TreeNode* temp,int*maxi){
    if(temp == NULL) return 0;

    int left = diameter(temp->left,maxi);
    int right = diameter(temp->right,maxi);
    (*maxi) = max((*maxi),left+right);

    return 1+max(left,right);
 }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0,maxi=0;
        int height = diameter(root,&maxi);
        
        return maxi; 
    }
};