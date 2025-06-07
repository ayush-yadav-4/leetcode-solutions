class Solution {
public:
void Swap(int a , int b, vector<int>& nums){
   int temp = nums[a];
   nums[a] = nums[b];
   nums[b] = temp;
}
    void sortColors(vector<int>& nums) {
        // int mid =0 ,low=0, high = nums.size()-1;
           
        // while(mid<=high){

        //     if(nums[mid] == 0){
        //         Swap(mid,low,nums);
        //         mid++;low++;
        //     }
        //     else if(nums[mid] == 1){
        //         mid++;
        //     }
        //     else{
        //         Swap(mid,high,nums);
        //         high--;
        //     }
        // }

        
        int st=0,mid=0,end = nums.size()-1;
        while(mid<=end){
              if(nums[mid] == 1)mid++;
              else if (nums[mid] == 0){ swap(nums[mid],nums[st]); mid++;st++;}
              else{ swap(nums[mid],nums[end]); end--;}

        }
    }
};