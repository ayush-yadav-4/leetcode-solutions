class Solution {
    public int findKthPositive(int[] arr, int k) {
        if(k < arr[0]) return k;
        for(int i=0;i<arr.length;i++){
            if(arr[i] > k) return k;
            else{
                k++;
            }
        }
        return k;
    }
}