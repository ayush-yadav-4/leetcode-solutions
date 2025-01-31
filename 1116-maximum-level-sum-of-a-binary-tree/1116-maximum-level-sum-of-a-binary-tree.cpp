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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int sum=INT_MIN,ans=INT_MIN,anslvl=0,level=0;
        TreeNode*temp = NULL;
        q.push(root);
        while(!q.empty()){
           int size = q.size();
           sum=0;
           for(int i=0;i<size;i++){
              temp = q.front(); q.pop();

              if(temp->left != NULL) q.push(temp->left);
              if(temp->right != NULL) q.push(temp->right);
              sum += temp->val;
           }
           level++;
           if(ans<sum){
            anslvl = level;
            ans = sum;
           }

        }
        return anslvl;
    }
};