class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int i=0,j=people.length-1,cnt = 0;
       while(i <= j ){
          if(people[i] + people[j] <= limit){
            cnt++;
            i++; j--;
          }
          else{
            j--; cnt++;
          }
       } 
       return cnt;
    }
}