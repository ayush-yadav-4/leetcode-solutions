class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long low = 1, high = 1e6;  // Upper bound guess based on constraints

        while (low < high) {
            long long mid = (low + high) / 2;
            long long totalApples = 2 * mid * (mid + 1) * (2 * mid + 1);
            
            if (totalApples >= neededApples) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return 8 * low;  // perimeter = 8 * k
    }
};
