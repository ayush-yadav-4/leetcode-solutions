class Solution {
public:
    void find_path(TreeNode* root, string path, vector<string>& ans) {
        if (!root) return;  // Base case: If node is null, return

        path += to_string(root->val);  // Append current node value

        if (!root->left && !root->right) {  // If leaf node, push the path
            ans.push_back(path);
            return;
        }

        path += "->";  // Append separator for next nodes

        // Recur for left and right subtrees
        find_path(root->left, path, ans);
        find_path(root->right, path, ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        find_path(root, "", ans);
        return ans;
    }
};
