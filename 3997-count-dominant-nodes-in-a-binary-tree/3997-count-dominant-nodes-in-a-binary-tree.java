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
    int cnt = 0;
    int traverse(TreeNode root){
       if(root == null) return 0;
       if(root.left == null && root.right == null){
        cnt++; return root.val;
       }
       int elem = Math.max(traverse(root.left), traverse(root.right));
       if(elem <= root.val){
        cnt++;
       }
       return Math.max(elem,root.val);
    }
    public int countDominantNodes(TreeNode root) {
        if(root == null ) return 0;
        if(root.left == null && root.right == null) return 1;
        traverse(root);
        return cnt;
    }
}