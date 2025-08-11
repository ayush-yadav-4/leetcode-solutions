class Solution {
    public int totalFruit(int[] nums) {

        int first = -1,second = -1,f =0,end=0,ans=0;
         Map<Integer,Integer> mp = new HashMap<>();
        while(end < nums.length){
              mp.merge(nums[end],1,Integer::sum);

              while(mp.size() > 2){
                mp.merge(nums[f],-1,Integer::sum);
                
                if(mp.get(nums[f]) == 0){
                    mp.remove(nums[f]);
                }
                f++;
              }
              ans = Math.max(ans,end-f+1);
              end++;
        }

        return ans;



            }
}