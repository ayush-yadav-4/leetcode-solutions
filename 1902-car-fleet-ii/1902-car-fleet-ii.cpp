class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> res(n, -1.0);
        stack<int> st; // stack to store indices of cars that could be collided into

        for (int i = n - 1; i >= 0; --i) {
            int pos1 = cars[i][0], speed1 = cars[i][1];

            while (!st.empty()) {
                int j = st.top();
                int pos2 = cars[j][0], speed2 = cars[j][1];

                if (speed1 <= speed2) {
                    // i-th car can never catch up
                    st.pop();
                } else {
                    double time = (double)(pos2 - pos1) / (speed1 - speed2);
                    if (res[j] == -1 || time <= res[j]) {
                        res[i] = time;
                        break;
                    } else {
                        // j will collide before i can reach it
                        st.pop();
                    }
                }
            }

            st.push(i);
        }

        return res;
    }
};
