class Solution {
    public boolean sumGame(String nums) {
        int n = nums.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n / 2; i++) {
            char ch = nums.charAt(i);
            if (ch == '?') leftQ++;
            else leftSum += ch - '0';
        }

        for (int i = n / 2; i < n; i++) {
            char ch = nums.charAt(i);
            if (ch == '?') rightQ++;
            else rightSum += ch - '0';
        }

         
        if (leftQ == 0 && rightQ == 0)
            return leftSum != rightSum;

        return (rightSum - leftSum) * 2 != (leftQ - rightQ) * 9;
    }
}