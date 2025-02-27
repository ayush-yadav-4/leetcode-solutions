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
 void mark_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
   
   queue<TreeNode*>q;
   TreeNode* temp = NULL;
   q.push(root);
   while(!q.empty()){
    int size = q.size();
    for(int i=0;i<size;i++){
       temp = q.front(); q.pop();

       if(temp->left != NULL){
        parent[temp->left] = temp;
        q.push(temp->left);
       }
         if(temp->right != NULL){
        parent[temp->right] = temp;
        q.push(temp->right);
       }
    }
   }
 }
   TreeNode* find_Node(TreeNode*root,int val){
     if(root == NULL) return NULL;
     if(root->val == val) return root;
    TreeNode* left =  find_Node(root->left,val);
      TreeNode* right = find_Node(root->right,val);
      if(left == NULL) return right;
      else if(right == NULL) return left;
      else return NULL;
      
      
   }
    int amountOfTime(TreeNode* root, int start) {
        if(root->left == NULL && root->right == NULL)return 0;
        TreeNode* target = find_Node(root,start);
        if(target == NULL)return 0;
        unordered_map<TreeNode*,TreeNode*>parent;
         unordered_map<TreeNode*,bool>visited;
        mark_parent(root,parent);
        int ans=0;
         TreeNode* temp = NULL;
        queue<TreeNode*>q;

        q.push(target);
        visited[target] = true;

        while(!q.empty()){
     int size = q.size();
     ans++;
    for(int i=0;i<size;i++){
       temp = q.front(); q.pop();
       if(temp->left && !visited[temp->left]){
        q.push(temp->left);
        visited[temp->left] = true;
       }
        if(temp->right && !visited[temp->right]){
        q.push(temp->right);
        visited[temp->right] = true;
       }
       if(parent[temp] && !visited[parent[temp]]){
           q.push(parent[temp]);
        visited[parent[temp]] = true;
       }
    }
        }
        return ans-1;
    }
};