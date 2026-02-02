class Solution {

    boolean Increasing(int[] nums , int l , int r){
        
        for(int i=l+1;i<=r;i++){
           if(nums[i] <= nums[i-1]) return false;
        }

        return true;
    }
    boolean Decreasing(int[] nums , int l , int r){
         for(int i=l+1;i<=r;i++){
           if(nums[i] >= nums[i-1]) return false;
        }
        return true;
    }
    public boolean isTrionic(int[] nums) {
        

        for(int p=1;p<=nums.length-3;p++){
           for(int q = p+1;q<=nums.length-2;q++){
               
               if(Increasing(nums,0,p) && 
                  Decreasing(nums,p,q) && 
                  Increasing(nums,q,nums.length-1)
                  ){
                return true;
               }
           }
        }

        return false;
    }
}