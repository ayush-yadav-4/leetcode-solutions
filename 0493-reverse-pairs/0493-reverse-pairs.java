class Solution {
     int merge(int low, int mid, int high, int[] arr) {

        int i = low, j = mid + 1;
        int cnt = 0;

        int[] temp = new int[high - low + 1];
        int k = 0;

        while (i <= mid && j <= high) {

            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                cnt += (mid - i + 1);
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];

        while (j <= high)
            temp[k++] = arr[j++];

        // copy back
        for (int x = 0; x < temp.length; x++) {
            arr[low + x] = temp[x];
        }

        return cnt;
    }
    int count(int st, int mid,int end, int[]arr){
        
        int cnt = 0;
        int right = mid + 1;

        for (int i = st; i <= mid; i++) {

            while (right <= end &&
                  (long)arr[i] > 2L * arr[right]) {
                right++;
            }

            cnt += (right - (mid + 1));
        }

        return cnt;
    }
    int mergeSort(int low, int high, int[] arr) {

        if (low >= high) return 0;

        int mid = (low + high) / 2;

        int ans = 0;
        ans += mergeSort(low, mid, arr);
      ans+=  mergeSort(mid + 1, high, arr);
       ans += count(low,mid,high,arr);
         merge(low, mid, high, arr);

        return ans;
    }
    public int reversePairs(int[] nums) {
        return mergeSort(0,nums.length-1,nums);
    }
}