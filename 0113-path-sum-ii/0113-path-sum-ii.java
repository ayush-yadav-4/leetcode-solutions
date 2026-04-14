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
    void helper(TreeNode root, int t , int sum ,List<Integer> path , List<List<Integer>> ans){
        if(root == null) return;
       sum += root.val;
        path.add(root.val);
        if(root.left == null && root.right == null){
            if(sum == t){
                ans.add(new ArrayList<>(path));
                
            }
           
        }
        
            helper(root.left , t , sum , path , ans);
            
            helper(root.right , t , sum , path , ans);
        
         sum -= root.val;
         path.remove(path.size()-1);
         return;
       
        

    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
         List<List<Integer>> ans = new ArrayList<>();
         List<Integer> path = new ArrayList<>();
         helper(root , targetSum,0,path,ans);

         return ans;
    }
}