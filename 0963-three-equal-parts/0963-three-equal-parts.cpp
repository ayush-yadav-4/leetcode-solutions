class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int total_ones = 0;
        for (int bit : arr) total_ones += bit;

        if (total_ones == 0)
            return {0, (int)arr.size() - 1};  // All zeros

        if (total_ones % 3 != 0)
            return {-1, -1};  // Cannot divide evenly

        int ones_per_part = total_ones / 3;
        int first = -1, second = -1, third = -1;
        int count = 0;

        // Find starting index of each part
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == 1) {
                count++;
                if (count == 1) first = i;
                else if (count == ones_per_part + 1) second = i;
                else if (count == 2 * ones_per_part + 1) third = i;
            }
        }

        int n = arr.size();
        // Compare the parts
        while (third < n && arr[first] == arr[second] && arr[second] == arr[third]) {
            first++;
            second++;
            third++;
        }

        if (third == n)
            return {first - 1, second};
        else
            return {-1, -1};
    }
};
