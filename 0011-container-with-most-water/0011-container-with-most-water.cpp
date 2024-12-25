class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0,heigh =0, width =0,maxarea =0,i=0,j=height.size()-1;
    while(i<=j){
        heigh = min(height[i],height[j]);
        width = j-i;
        area = width * heigh;
        maxarea = max(area, maxarea);
        if(height[i]<height[j]){
            i++;
        }else{
            j--;
        }

    }
        return maxarea;
    }
};