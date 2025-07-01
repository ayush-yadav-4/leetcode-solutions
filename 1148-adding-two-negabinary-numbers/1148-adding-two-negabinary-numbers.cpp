class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int i = arr1.size() - 1, j = arr2.size() - 1;
        vector<int> result;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            int sum = carry;
            if (i >= 0) sum += arr1[i--];
            if (j >= 0) sum += arr2[j--];

            result.push_back(sum & 1); // sum % 2
            carry = -(sum >> 1);       // Carry logic for base -2
        }

        // Remove leading zeros
        while (result.size() > 1 && result.back() == 0)
            result.pop_back();

        reverse(result.begin(), result.end());
        return result;
    }
};
