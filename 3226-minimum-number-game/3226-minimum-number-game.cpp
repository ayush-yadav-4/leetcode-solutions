class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Step 1: Sort the array
        vector<int> arr;
        
        for (int i = 0; i < nums.size(); i += 2) {
            int alice = nums[i];     // Alice removes the smallest
            int bob = nums[i + 1];   // Bob removes the next smallest
            
            arr.push_back(bob); // Bob appends first
            arr.push_back(alice); // Alice appends next
        }
        
        return arr;
    }
};
