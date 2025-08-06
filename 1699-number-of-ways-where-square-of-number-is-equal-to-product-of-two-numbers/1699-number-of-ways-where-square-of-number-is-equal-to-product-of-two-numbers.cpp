class Solution {
public:
    using ll = long long;

    int countTriplets(vector<int>& A, vector<int>& B) {
        unordered_map<ll, int> freq;
        for (int num : B) freq[num]++;
        
        int count = 0;
        for (int x : A) {
            ll target = (ll)x * x;
            for (auto& [a, cntA] : freq) {
                if (target % a != 0) continue;
                ll b = target / a;
                if (!freq.count(b)) continue;
                
                if (a == b) {
                    count += cntA * (cntA - 1) / 2;
                } else if (a < b) {
                    count += cntA * freq[b];
                }
            }
        }
        return count;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return countTriplets(nums1, nums2) + countTriplets(nums2, nums1);
    }
};

