/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    TreeNode ans = null;
    int find(TreeNode root, TreeNode p, TreeNode q){
      
     if(root == null) return 0;
     int left = find(root.left, p , q);
     int right = find(root.right, p , q);
     int self = 0;
     if(root.val == p.val || root.val == q.val){
        self = 1;
     }
     int total = self + left + right;
     if(total == 2 && ans == null) ans = root;
     return total;

    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        if(root.left == null && root.right == null) return root;

        find(root, p , q);
        return ans;
    }
}