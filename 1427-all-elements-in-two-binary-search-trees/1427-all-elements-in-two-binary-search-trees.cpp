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
void push_elem(TreeNode* root, vector<int>&arr){
 if(root == NULL) return;
 arr.push_back(root->val);
 push_elem(root->left,arr);
 push_elem(root->right,arr);
}
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
         vector<int>elem;
         push_elem(root1,elem);
          push_elem(root2,elem);

          sort(elem.begin(),elem.end());
          return elem;
    }
};