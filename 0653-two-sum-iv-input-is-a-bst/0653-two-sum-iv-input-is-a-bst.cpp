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
 class BSTree{
    bool isReverse = true;
    private:
    stack<TreeNode*>st;
    void pushALL(TreeNode* root){
       while(root != NULL){
         if(isReverse == true){
            this->st.push(root);
            root = root->left;
         }
         else{
             this->st.push(root);
            root = root->right;
         }
       }
    }
    public:
    BSTree(TreeNode*root,bool reverse){
       this->isReverse = reverse;
       pushALL(root);
    }
    int next(){
        TreeNode*temp = st.top();
        st.pop();
        if(isReverse == true){
            if(temp->right != NULL){
                pushALL(temp->right);
            }
        }
        else{
            if(temp->left != NULL){
                pushALL(temp->left);
            } 
        }
        return temp->val;
    }

    bool hasNext(){
       if(!st.empty()){
        return true;
       }
       return false;
    }
 };
class Solution {
public:
 bool findTarget(TreeNode* root, int k) {
       BSTree l(root,true);  BSTree r(root,false);
       
       int left = l.next();
       int right = r.next();

       while(left<right){
         if(left+right == k){
            return true;
         }
         else if(left+right > k){
            right = r.next();
         }
         else{
            left = l.next();
         }
       }
       return false;
    }
};