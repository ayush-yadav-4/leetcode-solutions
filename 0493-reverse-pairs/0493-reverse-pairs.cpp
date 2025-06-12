class Solution {
public:
int countpair(vector<int>& nums,int st,int mid,int end){
    int right = mid+1,cnt=0;
    for(int i=st;i<=mid;i++){
        long long num = nums[right];
        while(right <= end && 2*num < nums[i]){
          right++;
          num = nums[right];
        }
        cnt += (right - (mid+1)); 
    }
    return cnt;
}
int merge(vector<int>& nums,int st,int mid ,int end){
  int left = st,right = mid+1,cnt = 0;
  vector<int>arr;
  while(left<=mid && right<=end){
    if(nums[left]<=nums[right]){
        arr.push_back(nums[left++]);
    }else{
       arr.push_back(nums[right++]); 
    }
  }

  while(left <= mid){
            arr.push_back(nums[left++]);
        }
        while(right <= end){
            arr.push_back(nums[right++]);
        }

        for(int k = 0; k < arr.size(); k++){
            nums[st + k] = arr[k];
        }
        return cnt;
}
int mergesort(vector<int>& arr,int st,int end){
    if(st<end){
        int cnt = 0;
        int mid = st + (end-st)/2;
         cnt += mergesort(arr,st,mid);
         cnt += mergesort(arr,mid+1,end);
         cnt += countpair(arr,st,mid,end);
        merge(arr,st,mid,end);
        return cnt;
         
     }
     return 0;
}
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};