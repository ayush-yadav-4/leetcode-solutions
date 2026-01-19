class Solution {

    int reverse(int num){
        int ans =0;
        while(num!=0){
            ans = ans * 10 + num%10;
            num = num/10;
        }
        return ans;
    }
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer,Integer>mp = new HashMap<>();
        int ans = 10000000;
        for(int i=0;i<nums.length;i++){
            if(mp.containsKey(nums[i])){
                ans = Math.min(ans,(Math.abs(i - mp.get(nums[i]))));
            }
            
                   int n = reverse(nums[i]);
                   mp.put(n,i);
            
           
            
        }
        return (ans == 10000000) ? -1 : ans;
    }
}