class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1;
        int count = 0;
        
        do {
            if (pos % 2 == 0)
                pos = pos / 2;
            else
                pos = n / 2 + (pos - 1) / 2;
            count++;
        } while (pos != 1); // Stop when index 1 returns to position 1

        return count;
    }
};
