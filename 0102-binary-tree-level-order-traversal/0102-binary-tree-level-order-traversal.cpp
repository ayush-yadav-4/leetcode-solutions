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


    vector<vector<int>> levelOrder(TreeNode* root) {
          vector<vector<int>>ans2;
        if(root == NULL)return ans2;
        queue<TreeNode*>q;
        q.push(root); TreeNode* temp = NULL;
      
        while(!q.empty()){
            vector<int>ans;
            int size = q.size();
            for(int i=0;i<size;i++){
              temp = q.front(); q.pop();
              if(temp->left !=  NULL) q.push(temp->left);
               if(temp->right !=  NULL) q.push(temp->right);
                ans.push_back(temp->val);
            }
            ans2.push_back(ans);
         
          
        }
        return ans2;
    }
};