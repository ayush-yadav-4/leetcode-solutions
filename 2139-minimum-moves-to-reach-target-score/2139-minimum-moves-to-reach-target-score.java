class Solution {
    public int minMoves(int target, int maxDoubles) {
        int cnt = 0;
        if(maxDoubles == 0) return target-1;
        int num = target;
        while(num>1){
          if(maxDoubles >=1 && num%2 == 0){
            num = num/2;
            maxDoubles -= 1;
            cnt++;
          }
          else{
            num--;
            cnt++;
          }
          
        }
        return cnt;
    }
}