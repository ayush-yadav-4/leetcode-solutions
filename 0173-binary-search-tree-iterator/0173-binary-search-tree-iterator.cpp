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
public:
vector<int>arr;
int idx = 0;
  void helper(TreeNode* root){
    if(root == NULL) return;
    helper(root->left);
    arr.push_back(root->val);
    
    helper(root->right);
  }
    BSTIterator(TreeNode* root) {
      helper(root);  
    }
    
    int next() {
        if(idx<=arr.size()-1){
            int elem = arr[idx];
            idx++;
            return elem;
        }
        return -1;
    }
    
    bool hasNext() {
        if(idx<=arr.size()-1){return true;}
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */