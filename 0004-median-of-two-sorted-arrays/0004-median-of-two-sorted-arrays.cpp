class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
       int n1 = a.size();
       int n2 = b.size();
       if(n2 > n1) return findMedianSortedArrays(b,a);

       int low = 0,high = n2;
       int size = (n1 + n2);
       int left = (n1 + n2 +1)/2;

       while(low <= high){
           int mid1 = (low + high)/2;
           int mid2 = left - mid1;
           double l1 = INT_MIN,l2 = INT_MIN,r1 = INT_MAX,r2= INT_MAX;

            if(mid1 -1 >=0) l1 = b[mid1-1];
            if(mid1 < n2) r1 = b[mid1];
            if(mid2 -1 >=0) l2 = a[mid2-1];
            if(mid2 < n1) r2 = a[mid2];
            if(l1<=r2 && l2<=r1){
            if(size%2 == 0){
                return (double)(max(l1,l2) + min(r1,r2))/2.0;
            }
            else return max(l1,l2);
           }
          
           if(l1>r2) high = mid1-1;
           else low = mid1 +1;

           
           

       }
       return 0;
       
    }
};