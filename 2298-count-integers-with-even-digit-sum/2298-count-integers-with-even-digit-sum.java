class Solution {
    public int countEven(int num) {
        int evencount=0;
        for(int i=1;i<=num;i++){
            int sum=0;
            int temp=i;
            while(temp!=0){
              int rem=temp%10;
              sum+=rem;
              temp/=10;
            }
            if(sum%2==0){
                evencount++;
            }
        }
        return evencount;
    }
}