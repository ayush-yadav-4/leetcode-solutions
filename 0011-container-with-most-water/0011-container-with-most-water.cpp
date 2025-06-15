class Solution {
public:
    int maxArea(vector<int>& arr) {
    //     int area = 0,heigh =0, width =0,maxarea =0,i=0,j=height.size()-1;
    // while(i<=j){
    //     heigh = min(height[i],height[j]);
    //     width = j-i;
    //     area = width * heigh;
    //     maxarea = max(area, maxarea);
    //     if(height[i]<height[j]){
    //         i++;
    //     }else{
    //         j--;
    //     }

    // }
    //     return maxarea;



        int area = 0,ans = INT_MIN,l=0,r=arr.size()-1;
        while(l<r){
          area = (r-l) * min(arr[l],arr[r]);
        if(arr[l] < arr[r]){
            l++;
        }
        else r--;

        if(area>ans)ans = max(area,ans);
        }
        return ans;


    }
};