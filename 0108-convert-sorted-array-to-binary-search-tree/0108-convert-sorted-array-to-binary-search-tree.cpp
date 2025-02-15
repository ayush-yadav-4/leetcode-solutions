

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr; // Base case: If no elements left, return null

        int mid = left + (right - left) / 2; // Find the middle element
        TreeNode* root = new TreeNode(nums[mid]); // Create the root node

        root->left = buildBST(nums, left, mid - 1);  // Construct left subtree
        root->right = buildBST(nums, mid + 1, right); // Construct right subtree

        return root; // Return the root node
    }
};
