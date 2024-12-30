class Solution {
public:
void Merge(vector<int>& nums,int st,int mid,int end){
   int i = st, j = mid+1;
   vector<int>temp;

   while(i<=mid && j <=end){

    if(nums[i]<= nums[j]){
        temp.push_back(nums[i]);
        i++;
    }
    else{
        temp.push_back(nums[j]);
        j++;
    }
   }
   while(i<=mid){
    temp.push_back(nums[i]);
        i++;
   }

    while(j<=end){
    temp.push_back(nums[j]);
        j++;
   }
    for(int j = 0;j<temp.size();j++){
         nums[j+st] = temp[j];
}
}
void MergeSort(vector<int>& nums,int st,int end){
  int mid;
  if(st<end){
     mid = st + (end - st)/2;

     MergeSort(nums,st,mid);
     MergeSort(nums,mid+1,end);
     Merge(nums,st,mid,end);
  }
}
    vector<int> sortArray(vector<int>& nums) {
         MergeSort(nums,0,nums.size()-1);
         return nums;
    }
};