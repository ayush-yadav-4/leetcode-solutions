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
    void help(TreeNode root , int lvl, List<Integer> ls){
        if(root == null) return;

        if(ls.size() == lvl){
            ls.add(root.val);
        }
        help(root.right , lvl+1, ls);
        help(root.left, lvl+1, ls);

    }
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ls = new ArrayList<>();
        help(root, 0 , ls);
        return ls;

    }
}