class Solution {
public:
void Swap(int a,int b,vector<int>& nums1, vector<int>& nums2){
int temp = nums1[a];
nums1[a] = nums2[b];
nums2[b] = temp;
}
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=m-1,j=n-1,idx = nums1.size()-1;

        while(i>=0 && j >=0){
            if(nums1[i] > nums2[j]){
                nums1[idx--] = nums1[i--];
            }
            else{
                nums1[idx--] = nums2[j--];
            }
             
        }
         
          while(j>=0){
            nums1[idx--] = nums2[j--];

        }

       
    }
};