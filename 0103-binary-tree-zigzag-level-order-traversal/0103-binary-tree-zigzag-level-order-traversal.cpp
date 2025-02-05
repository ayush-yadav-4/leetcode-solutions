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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
         if(root == NULL)return ans;
        queue<TreeNode*>q; int count=1;
        TreeNode* temp= NULL;
       
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>arr;
            for(int i=0;i<size;i++){
                temp = q.front(); q.pop();
                if(temp->left != NULL)q.push(temp->left);
                if(temp->right != NULL)q.push(temp->right);
                arr.push_back(temp->val);
            }
            if(count%2 == 0){reverse(arr.begin(),arr.end());}
            ans.push_back(arr); count++;
        }
        return ans;
    }
};