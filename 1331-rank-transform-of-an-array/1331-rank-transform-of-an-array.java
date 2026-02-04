class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] arr1 = arr.clone();
        Map<Integer,Integer> mp = new HashMap<>();
         Arrays.sort(arr1);
       int rank = 1;

       for(int num : arr1){
         if(!mp.containsKey(num)){
            mp.put(num,rank++);
         }
       }
        
       
        for(int i =0;i<arr.length;i++){
           arr[i] = mp.get(arr[i]);
        }

        return arr;
    }
}