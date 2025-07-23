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
    int helper(TreeNode node,int[] ans){
    if(node == null) return 0;
    int left = helper(node.left,ans);
    int right = helper(node.right,ans);
    ans[0] = Math.max(ans[0],left+right);
    return Math.max(left,right) + 1;
  }
    public int diameterOfBinaryTree(TreeNode root) {
          int[] ans = new int[1];
       helper(root,ans);
       return ans[0];
    }
}


   