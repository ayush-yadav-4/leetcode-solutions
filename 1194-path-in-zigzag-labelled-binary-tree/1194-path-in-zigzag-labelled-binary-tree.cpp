#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;

        int level = log2(label) + 1;

        while (label >= 1) {
            path.push_back(label);

            int level_start = pow(2, level - 1);
            int level_end = pow(2, level) - 1;

            // If the level is even, we are in a reversed level, so we need to find the mirrored value
            int normal_label = label;
            if (level % 2 == 0) {
                normal_label = level_start + level_end - label;
            }

            int parent_normal_label = normal_label / 2;

            // Now compute the label of the parent in zigzag format
            level--;
            int parent_level_start = pow(2, level - 1);
            int parent_level_end = pow(2, level) - 1;

            if (level % 2 == 0) {
                label = parent_level_start + parent_level_end - parent_normal_label;
            } else {
                label = parent_normal_label;
            }
        }

        reverse(path.begin(), path.end());
        return path;
    }
};
