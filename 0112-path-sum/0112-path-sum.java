/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    boolean ans = false;
    void help(TreeNode root, int target){
        if(root == null) return ;

        target -= root.val;
        if(root.left == null && root.right == null){
            if(target == 0)ans = true;
            return;
        }
        help(root.left,target);
        help(root.right, target);
        
        
       
    }
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if(root == null) return false;
        help(root,targetSum);
        return ans;
    }
}