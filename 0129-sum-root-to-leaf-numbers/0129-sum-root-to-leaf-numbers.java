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
    int ans =0;
    void helper(TreeNode root, StringBuilder str){
      
      if(root == null) return;
      str.append(String.valueOf(root.val));

      if(root.right == null && root.left == null){
         ans += Integer.parseInt(str.toString());
         
      }
      else{
      helper(root.left, str);
      
     
      helper(root.right, str);
      }

       str.deleteCharAt(str.length()-1);


    }
    public int sumNumbers(TreeNode root) {
        if(root == null) return 0;
        StringBuilder str = new StringBuilder();

        helper(root, str);
        return ans;
    }
}