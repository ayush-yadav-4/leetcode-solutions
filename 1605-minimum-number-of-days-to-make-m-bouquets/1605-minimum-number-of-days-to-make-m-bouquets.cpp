class Solution {
public:
    bool check(vector<int>& arr, int m, int k, int mid) {
        int f = 0, cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                cnt++;
                if (cnt == k) {
                    cnt = 0;
                    f++;
                }
            } else if (f >= m)
                return true;
            else if (arr[i] > mid) {
                cnt = 0;
            }
        }

        if (f < m)
            return false;
        return true;
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long b = m,f = k;
        if (arr.size() < (b * f))
            return -1;
        int ans = 0, mid = 0;
        int st = INT_MAX, end = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            st = min(st, arr[i]);
            end = max(end, arr[i]);
        }

        while (st <= end) {
            mid = st + (end - st) / 2;
            if (check(arr, m, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return ans;
    }
};