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
class BSTIterator {
private: 
stack<TreeNode*>st;
void push_left(TreeNode*root){
    while(root!= NULL){
        this->st.push(root);
        root = root->left;
    }
}
public:
    BSTIterator(TreeNode* root) {
        push_left(root);
    }
    
    int next() {
    TreeNode*temp = this->st.top();
     this->st.pop();
    if(temp->right != NULL){
        push_left(temp->right);
    }
   
    return temp->val;
       
    }
    
    bool hasNext() {
        if(!this->st.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */