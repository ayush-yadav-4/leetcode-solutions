class Solution {
public:
    void findNSE(vector<int>& nse, vector<int>& heights) {
        stack<int> st;
        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            } else {
                nse[i] = heights.size(); // No smaller element, set to end of array
            }
            st.push(i);
        }
    }

    void findPGE(vector<int>& pge, vector<int>& heights) {
        stack<int> st;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            } else {
                pge[i] = -1; // No greater element, set to start of array
            }
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse(heights.size(), heights.size());
        vector<int> pge(heights.size(), -1);
        
        findNSE(nse, heights);
        findPGE(pge, heights);

        int maxi = 0;
        for (int i = 0; i < heights.size(); i++) {
            int base = nse[i] - pge[i] - 1; // Correct base calculation
            int area = heights[i] * base;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};
