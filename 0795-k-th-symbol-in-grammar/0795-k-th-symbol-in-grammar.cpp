class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) return 0;
        
        int parent = kthGrammar(n - 1, (k + 1) / 2);
        
        // If k is even, it's the flipped bit of the parent
        if (k % 2 == 0)
            return parent ^ 1;  // flip 0 to 1 or 1 to 0
        else
            return parent;      // same as parent
    }
};
