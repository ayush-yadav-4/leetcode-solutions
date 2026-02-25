class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer>st = new HashSet<>();

        for(int i=0;i<nums.length;i++){
          st.add(nums[i]);
        }
        int cnt =0, ans =0, num = 0;
        for(int elem : st){
            if(st.contains(elem-1) == false){
                cnt = 0;
                num = elem;
                while(st.contains(num)){
                  cnt++;
                  num = num +1;
                }
                ans = Math.max(ans, cnt);
            }
        }

        return ans;
    }
}