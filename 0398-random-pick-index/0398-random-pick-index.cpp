class Solution {
private:
    std::unordered_map<int, std::vector<int>> indexMap;
    
public:
    Solution(std::vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            indexMap[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        const std::vector<int>& indices = indexMap[target];
        int randIndex = rand() % indices.size();
        return indices[randIndex];
    }
};