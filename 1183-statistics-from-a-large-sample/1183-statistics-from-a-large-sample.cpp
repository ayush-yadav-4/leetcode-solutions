class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = -1, maximum = -1;
        double mean = 0.0, median = 0.0, mode = 0.0;

        long long total_count = 0, total_sum = 0;
        int mode_count = 0;

        // Find min, max, mean, mode
        for (int i = 0; i < 256; ++i) {
            if (count[i] > 0) {
                if (minimum == -1) minimum = i;
                maximum = i;

                total_count += count[i];
                total_sum += (long long)count[i] * i;

                if (count[i] > mode_count) {
                    mode_count = count[i];
                    mode = i;
                }
            }
        }

        mean = (double)total_sum / total_count;

        // Find median
        int mid1 = (total_count + 1) / 2;
        int mid2 = (total_count % 2 == 0) ? (total_count / 2 + 1) : mid1;

        int curr_count = 0;
        int first_median = -1, second_median = -1;

        for (int i = 0; i < 256; ++i) {
            curr_count += count[i];
            if (first_median == -1 && curr_count >= mid1) {
                first_median = i;
            }
            if (curr_count >= mid2) {
                second_median = i;
                break;
            }
        }

        median = (first_median + second_median) / 2.0;

        return {minimum, maximum, mean, median, mode};
    }
};

