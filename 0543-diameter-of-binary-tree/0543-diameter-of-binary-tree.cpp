class Solution {
public:
    int ans = 0;

    int height(TreeNode* root) {
        if (root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        ans = max(ans, left + right); // diameter update

        return 1 + max(left, right); // height
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};
