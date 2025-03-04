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
void push_elem(TreeNode* root,vector<int>&arr){
    if(root == NULL)return;
    arr.push_back(root->val);

    push_elem(root->left,arr);
     push_elem(root->right,arr);

}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        push_elem(root,arr);
        sort(arr.begin(),arr.end());
        return arr[k-1];
    }
};