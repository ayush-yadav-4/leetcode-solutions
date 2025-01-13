
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;

            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                // Handle collision
                if (abs(st.top()) < abs(asteroids[i])) {
                    st.pop(); // Top asteroid is destroyed
                } else if (abs(st.top()) == abs(asteroids[i])) {
                    st.pop(); // Both are destroyed
                    destroyed = true; // Current asteroid also destroyed
                    break;
                } else {
                    destroyed = true; // Current asteroid is destroyed
                    break;
                }
            }

            // Push the current asteroid if it survived
            if (!destroyed) {
                st.push(asteroids[i]);
            }
        }

        // Collect the result from the stack
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end()); // Reverse to get the correct order
        return ans;
    }
};
