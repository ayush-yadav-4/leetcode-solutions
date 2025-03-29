class Solution {
public:
    string triangleType(vector<int>& nums) {
        // Sort the sides to make checking easier
        sort(nums.begin(), nums.end());
        
        // Check if the sides can form a valid triangle
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        }
        
        // Check for equilateral triangle
        if (nums[0] == nums[1] && nums[1] == nums[2]) {
            return "equilateral";
        }
        
        // Check for isosceles triangle
        if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        }
        
        // If none of the above conditions matched, it's a scalene triangle
        return "scalene";
    }
};