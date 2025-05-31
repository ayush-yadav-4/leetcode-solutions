class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int a : answers) {
            count[a]++;
        }
        
        int result = 0;
        for (auto& [x, freq] : count) {
            int groupSize = x + 1;
            int groups = (freq + groupSize - 1) / groupSize; // ceil(freq / groupSize)
            result += groups * groupSize;
        }
        
        return result;
    }
};
