class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;

        // Step 1: Checking the number of places which are indifferent in s1 and s2.
        // There can only be 2 possibilites , s1 having x and s2 having y or vice-versa.
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'x' && s2[i] == 'y') xy++;
            if (s1[i] == 'y' && s2[i] == 'x') yx++;
        }

        // Step 2: Checking if the number of the differences is odd , 
        // if yes then swaps won't make the strings identical
        if ((xy + yx) % 2 != 0) return -1;

        // Step 3: Then finally return the number of swaps and we are dividing by 2 because
        // in one swap , we count one from s1 and one from s2
        return xy / 2 + yx / 2 + (xy % 2) * 2;
    }
};