/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

void mark_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parent){
   TreeNode* temp = NULL;
   queue<TreeNode*>q;
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        mark_parent(root,parent);
         int level =0;
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
           TreeNode* temp = NULL;

        while(!q.empty()){
          int size = q.size();
          if(level++ == k)break;

          for(int i=0;i<size;i++){
           temp = q.front(); q.pop();

           if(temp->left != NULL && !visited[temp->left]){
             q.push(temp->left);
             visited[temp->left] = true;
           }
           if(temp->right != NULL && !visited[temp->right]){
                q.push(temp->right);
             visited[temp->right] = true;
           }

            if(parent[temp] && !visited[parent[temp]]){
                q.push(parent[temp]);
                visited[parent[temp]] = true;
           }
          }

        }
       vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};