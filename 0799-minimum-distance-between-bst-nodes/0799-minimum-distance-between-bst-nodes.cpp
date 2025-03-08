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
    void find_dist(TreeNode* root,int &val,int &prev){

     if(root == NULL)return;
    find_dist(root->left,val,prev);
    val = min(val,abs(prev - root->val));
    prev = root->val;
    find_dist(root->right,val,prev);
    }
    int minDiffInBST(TreeNode* root) {
        int val = INT_MAX,prev = INT_MAX;
        find_dist(root,val,prev);
        return val;
    }
};