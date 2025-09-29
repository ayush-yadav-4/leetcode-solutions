import java.util.Arrays;

class Solution {
    public int maxCoins(int[] piles) {
        Arrays.sort(piles);
        int ans = 0;
        int i = 0;
        int j = piles.length - 1;
        
        while (i < j) {
            ans += piles[j - 1]; // take the second largest pile
            j -= 2; // remove Alice's and your piles from the right
            i++;    // remove Bob's pile from the left
        }
        
        return ans;
    }
}