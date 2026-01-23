class Solution {
    public int longestBalanced(int[] nums) {
        Set<Integer> st = new HashSet<>();
        int ans = 0,even = 0,odd = 0;
        for(int i=0;i<nums.length;i++){
            st.clear();
            even = 0; odd = 0;
            for(int j = i;j<nums.length;j++){
              if(st.contains(nums[j]) == false){
                st.add(nums[j]);
                if(nums[j]%2 == 0) even++;
                else odd++;
              }
              if(even == odd){
                ans = Math.max(ans , (j-i+1));
              }
            }
        } 

        return ans;
    }
}