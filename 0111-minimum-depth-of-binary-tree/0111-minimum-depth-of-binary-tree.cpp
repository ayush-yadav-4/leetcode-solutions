class Solution {
public:
    int depth(TreeNode* root) {
        if (!root) return 0; 
        if (!root->left && !root->right) return 1;  // If it's a leaf node, return 1
        
        if (!root->left) return 1 + depth(root->right);  
        if (!root->right) return 1 + depth(root->left);  

        return 1 + min(depth(root->left), depth(root->right));  // min depth
    }

    int minDepth(TreeNode* root) {
        return depth(root);
    }
};
