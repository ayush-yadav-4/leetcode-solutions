class Solution {

    boolean check(String s, int[] order, int k, long t){
       long n = s.length();
       long total = (n * (n+1))/2;
       long valid = 0;
       boolean[] arr = new boolean[s.length()];
       long len = 0, invalid = 0;
       for(int i=0;i<=(int)t;i++){
          arr[order[i]] = true;
       }

       for(int i=0;i<s.length();i++){
           
           if(arr[i] == false){
            len++;
           }
           else{
            invalid += (len * (len+1))/2;
            len = 0;
           }
       }

       invalid += (len * (len +1))/2;

       valid = total - invalid;

       return valid >=k;
    }
    public int minTime(String s, int[] order, int k) {
        
        long left = 0, right = s.length()-1;
        long ans = -1;
        while(left<=right){
           long mid = left + (right - left)/2;

           if(check(s,order,k,mid)){
             ans = mid;
             right = mid-1;
           }
           else{
            left = mid+1;
           }
        }

        return (int)ans;
    }
}