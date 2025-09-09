class Solution {
    public int numberOfSteps(int num) {
        int n=num;
        int count=0;
        while(n!=0)
        {
//odd or even using bit manipulation.
            if((n&1)==1)
            {
                n-=1;
                count++;
            }
            else{
                n/=2;
                count++;
            }
        }
        return count;
    }
}