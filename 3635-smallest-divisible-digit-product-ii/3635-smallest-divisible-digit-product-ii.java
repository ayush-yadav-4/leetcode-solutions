
class Solution {
    int primes[] = new int[]{2, 3, 5, 7}, maxPrime = primes[primes.length - 1];

    public String smallestNumber(String num, long t) {
        int primeCount[] = new int[maxPrime + 1]; // Prime factor counts for t
        int numLength = num.length();
        int minLength;
        int firstZeroIndexFromLeft = 0;

        // Factorize t
        long temp_t = t;
        for (int prime : primes) {
            while (temp_t % prime == 0) {
                primeCount[prime]++;
                temp_t /= prime;
            }
        }
        if (temp_t != 1) return "-1"; // Invalid t

        minLength = getMinLength(primeCount);
        if (numLength < minLength) return buildSuffix(primeCount, minLength, new char[minLength]); // Num too short

        char[] result = new char[numLength + 1];
        for (int i = 0; firstZeroIndexFromLeft < numLength && (result[++i] = num.charAt(firstZeroIndexFromLeft)) != '0'; firstZeroIndexFromLeft++)
            logNum(primeCount, result[i], -1); // Initial prime counts from num prefix

        if (getMinLength(primeCount) == 0) { // Already divisible?
            if (firstZeroIndexFromLeft == numLength) return num; // Num is already valid
            Arrays.fill(result, ++firstZeroIndexFromLeft, result.length, '1'); // Pad with '1's
            return new String(result, 1, numLength);
        }

        for (int last = numLength - 1, end = Math.min(firstZeroIndexFromLeft, last); end >= 0; end--) {
            logNum(primeCount, result[end + 1], 1); // Backtrack: remove digit contribution
            for (; ++result[end + 1] <= '9'; logNum(primeCount, result[end + 1], 1)) { // Increment digit
                logNum(primeCount, result[end + 1], -1); // Add new digit contribution
                if (getMinLength(primeCount) <= last - end) // Suffix can satisfy?
                    return buildSuffix(primeCount, last - end, result); // Build and return with suffix
            }
        }

        return buildSuffix(primeCount, result.length, result); // Build for length+1 if no solution in current length
    }

    void logNum(int[] primeCount, int num, int value) { // Update prime counts based on digit
        if (num < '2') return;
        if (num == '9') primeCount[3] += value << 1; // 9 = 3*3
        else if (num == '4') primeCount[2] += value << 1; // 4 = 2*2
        else if (num == '8') primeCount[2] += value * 3; // 8 = 2*2*2
        else if (num == '6') { // 6 = 2*3
            primeCount[2] += value;
            primeCount[3] += value;
        } else primeCount[num - '0'] += value; // Prime digit
    }

    String buildSuffix(int[] primeCount, int targetLength, char[] result) { // Build smallest suffix
        int index = result.length;
        for (; primeCount[3] > 1; primeCount[3] -= 2) result[--index] = '9'; // Use '9' for pairs of 3s
        for (; primeCount[2] > 2; primeCount[2] -= 3) result[--index] = '8'; // Use '8' for triplets of 2s
        while (primeCount[7]-- > 0) result[--index] = '7'; // Use '7' for 7s
        if (primeCount[2] > 0 && primeCount[3] > 0) { // Use '6' for pairs of 2 and 3
            result[--index] = '6';
            primeCount[2]--;
            primeCount[3]--;
        }
        while (primeCount[5]-- > 0) result[--index] = '5'; // Use '5' for 5s
        for (; primeCount[2] > 1; primeCount[2] -= 2) result[--index] = '4'; // Use '4' for pairs of 2s
        for (; primeCount[3] > 0; primeCount[3]--) result[--index] = '3'; // Use '3' for 3s
        for (; primeCount[2] > 0; primeCount[2]--) result[--index] = '2'; // Use '2' for remaining 2s
        while (index + targetLength != result.length) result[--index] = '1'; // Pad with '1's
        return targetLength == result.length ? new String(result) : new String(result, 1, result.length - 1); // Return suffix string
    }

    int getMinLength(int[] primeCount) { // Calculate minimum length based on prime counts
        int count2 = Math.max(0, primeCount[2]);
        int count3 = Math.max(0, primeCount[3]);
        int count23 = (count3 & 1) + (count2 % 3); // Remaining 2s and 3s after using 8 and 9
        return (count3 >> 1) + (count2 / 3) + Math.max(0, primeCount[7]) + Math.max(0, primeCount[5]) + (count23 == 3 ? 2 : count23 > 0 ? 1 : 0);
        // count3>>1: count of 9s, count2/3: count of 8s, etc.
    }
}