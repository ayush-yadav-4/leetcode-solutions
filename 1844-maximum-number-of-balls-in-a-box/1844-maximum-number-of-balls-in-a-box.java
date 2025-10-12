class Solution
{
    public int countBalls(int lowLimit, int highLimit)
    {
        // Step 1: Create a HashMap to store the count of balls in each box
        HashMap<Integer, Integer> map = new HashMap<>();
        int maxBalls = 0;

        // Step 2: Iterate over each ball from lowLimit to highLimit
        for(int i = lowLimit; i <= highLimit; i++)
        {
            // Step 3: Find the box number for the current ball
            int boxNumber = getBoxNumber(i);

            // Step 4: Update the count of balls in this box
            map.put(boxNumber, map.getOrDefault(boxNumber, 0) + 1);

            // Step 5: Update the maximum number of balls in any box
            maxBalls = Math.max(maxBalls, map.get(boxNumber));
        }       

        // Step 6: Return the maximum count found
        return maxBalls;
    }

    // Helper function to calculate the sum of digits of a number
    public int getBoxNumber(int n)
    {
        int sum = 0;

        // Step 1: Compute the sum of digits of n
        while(n > 0)
        {
            sum += (n % 10); 
            n /= 10;         
        }

        // Step 2: Return the computed sum (which is the box number)
        return sum;
    }
}