class Solution {
public:
 void heapify(vector<int>& nums, int idx,int n){
    int largest = idx;
    int left = 2 *idx+1;
    int right = 2 *idx+2;
 
    if(left < n && nums[largest] < nums[left])
    largest = left;
    if(right< n && nums[largest] < nums[right])
    largest = right;

    if(largest != idx){
        swap(nums[largest],nums[idx]);
        heapify(nums,largest,n);
    }


 }
    int findKthLargest(vector<int>& nums, int k) {
       
        int n = nums.size();
     for(int i = (nums.size()/2) -1 ; i>=0;i--){    
         heapify(nums,i,n);   // build a max heap
     }

     for(int i=0;i<k-1;i++){
       swap(nums[0],nums[n-1]);
       n--;
       heapify(nums,0,n);
     }
        return nums[0];
    }
};