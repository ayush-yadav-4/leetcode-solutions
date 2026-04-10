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

     void preorder(TreeNode root,ArrayList<Integer> arr){
       if(root == null){
        return;
       }
       preorder(root.left,arr);
       arr.add(root.val);
       preorder(root.right, arr);
     }
    public boolean findTarget(TreeNode root, int k) {
        ArrayList<Integer>arr = new ArrayList<>();
        preorder(root, arr);
        int left = 0 , right = arr.size()-1;
         while(left<right){
            int sum = arr.get(left) + arr.get(right);
            if(sum == k) return true;
            if(sum < k){
                left++;
            }else{
                right--;
            }
         }

         return false;

    }
}