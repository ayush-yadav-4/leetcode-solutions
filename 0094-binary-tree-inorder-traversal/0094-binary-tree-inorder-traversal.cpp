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
// void Inorder(TreeNode* temp,vector<int>&ans){
//    if(temp == NULL)return;

//    Inorder(temp->left,ans);
//    ans.push_back(temp->val);
//    Inorder(temp->right,ans);
   
// }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;
      //  Inorder(root,ans);

        TreeNode* temp;
        stack<TreeNode*>st;
        stack<int>visited;
        st.push(root);
        visited.push(0);
        while(!st.empty()){
         temp = st.top();
         st.pop();

         bool visit = visited.top(); visited.pop();
         if(!visit){
            if(temp->right!= NULL){st.push(temp->right); visited.push(0);}
            st.push(temp);
            visited.push(1);

            if(temp->left!= NULL){st.push(temp->left); visited.push(0);}


         }
         else{
         ans.push_back(temp->val);}
        }
        return ans;
    }
};