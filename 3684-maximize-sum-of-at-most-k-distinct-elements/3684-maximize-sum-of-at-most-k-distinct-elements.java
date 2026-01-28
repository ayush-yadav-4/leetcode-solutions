class Solution {
    public int[] maxKDistinct(int[] nums, int k) {
        Arrays.sort(nums);
        List<Integer> ans = new ArrayList<>();
        
        int i = nums.length-1,j=0;
        k = k-1;

        while(i>=0 && k>=0){
           ans.add(nums[i]);
            while(i>=0 && nums[i]== ans.get(ans.size()-1)&& k>=0){
                i--;
            } 
            j++;
            k--;
        }
        int[] arr = new int[ans.size()];
        for(int l=0;l<ans.size();l++){
            arr[l] = ans.get(l);
        }
        return arr;
    }
}