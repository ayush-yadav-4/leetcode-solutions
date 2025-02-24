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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0,curr_id=0,last=0,first=0;
        queue<pair<TreeNode*,long long>>q;
        TreeNode*temp = NULL;
        q.push({root,1});
        while(!q.empty()){
        int size = q.size();    
       int nmin = q.front().second;
       first=0;last=0;
       for(int i=0;i<size;i++){
         long long curr_id = q.front().second-nmin;
         temp = q.front().first;
        q.pop();

         if(i==0)first = curr_id;
         if(i == size-1) last = curr_id;
         if(temp->left != NULL)q.push({temp->left,curr_id*2+1});
          if(temp->right != NULL)q.push({temp->right,curr_id*2+2});
       }
       ans = max(ans,((last-first)+1));
        }
        return ans;
    }
};