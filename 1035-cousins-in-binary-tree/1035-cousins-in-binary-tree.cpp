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
int check_parent(TreeNode* temp, int x, int y){
  if(temp == NULL) return 0;
  if(temp->right != NULL && temp->left != NULL){
  if(temp->right->val == x && temp->left->val == y){
     return -1;
  }
  if(temp->right->val == y && temp->left->val == x) return -1;
  }
  int r = check_parent(temp->right,x,y);
    int l = check_parent(temp->left,x,y);
    if(l == -1 || r == -1)return -1;

return 1;

}
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*>q;
        int level=0,l1=-1,l2=-1;
        TreeNode* temp = NULL;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
              temp = q.front(); q.pop();
              if(temp->val== x)l1 = level;
                if(temp->val== y)l2 = level;

               if(temp->right != NULL)q.push(temp->right);
                if(temp->left != NULL)q.push(temp->left); 

            }
            level++;
            if(l1 != l2) return false;
            if(l1 != -1 && l2 != -1)break;
        }

        if(check_parent(root,x,y) == 1) return true;
        return false;
    }
};