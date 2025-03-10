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
TreeNode* build(vector<int>& preorder,int min , int max,int& idx){

    if(idx == preorder.size() || preorder[idx]<min || preorder[idx]>max){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = build(preorder,min,root->val,idx);
    root->right = build(preorder,root->val,max,idx);
    
    return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return build(preorder,INT_MIN,INT_MAX,idx);
        
    }
};