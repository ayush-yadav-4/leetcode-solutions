class Solution {
    public int averageValue(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++){
            if(nums[i]%3==0 && nums[i]%2==0){
                list.add(nums[i]);
            }
        }
        int avg=0,sum=0;
        for(int n:list ){
            sum+=n;
        }
        if(list.size()!=0){
        avg = sum / list.size();
        return avg;
        }
        return 0;
    }
}