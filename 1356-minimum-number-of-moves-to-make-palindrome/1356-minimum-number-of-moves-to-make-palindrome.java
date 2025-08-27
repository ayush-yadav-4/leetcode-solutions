class Solution {
    public int minMovesToMakePalindrome(String s) {
        char[] arr = s.toCharArray();
        int l = 0, r = arr.length - 1;
        int moves = 0;

        while (l < r) {
            if (arr[l] == arr[r]) {
                l++;
                r--;
            } else {
                int k = r;
                while (k > l && arr[k] != arr[l]) {
                    k--;
                }

                if (k == l) {
                    // arr[l] is the middle character, swap it rightwards by one step
                    swap(arr, l, l + 1);
                    moves++;
                } else {
                    // bring arr[k] to position r by swapping step by step
                    while (k < r) {
                        swap(arr, k, k + 1);
                        moves++;
                        k++;
                    }
                    l++;
                    r--;
                }
            }
        }
        return moves;
    }

    private void swap(char[] arr, int i, int j) {
        char tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
