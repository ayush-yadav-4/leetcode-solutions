class Solution {
    public int sumDivisibleByK(int[] nums, int k) {
        Map<Integer,Integer>mp = new HashMap<>();
        int sum =0;
        for(int i=0;i<nums.length;i++){
           mp.put(nums[i],mp.getOrDefault(nums[i],0)+1);
        }

        for(Map.Entry<Integer,Integer> m : mp.entrySet()){
            if(m.getValue()%k == 0){
                sum += m.getKey() * m.getValue();
            }
        }
        return sum;
    }
}