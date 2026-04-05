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
    void find(TreeNode root, TreeNode p, TreeNode q){
       if(root == null) return;
       if(root.val == p.val || root.val == q.val && ans == null){
        ans = root;
        return;
       }
     
       if(p.val < root.val && q.val < root.val){
         find(root.left, p,q);
       }
       else if(q.val > root.val && p.val > root.val){
          find(root.right, p,q);
       }
       else if(ans == null){
        ans = root;
        return;

       }
     
      

    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        if(root.left == null && root.right == null) return root;
        find(root, p , q);
        return ans;
    }
}