class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans = 0, zero = 0, one = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0) zero++;
            else one++;

            int elem = zero - one;   // ❌ removed abs()

            if(elem == 0) {
                ans = max(ans, i + 1);  // ❌ fixed length
            }
            else if(mp.find(elem) == mp.end()) {
                mp[elem] = i;          // store first index
            }
            else {
                ans = max(ans, i - mp[elem]);
            }
        }

        return ans;
    }
};
