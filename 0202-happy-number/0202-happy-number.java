class Solution {
    public boolean isHappy(int n) {
        HashSet<Integer> set= new HashSet<Integer>();
      
        while(n!=1)
        {
            if(!set.contains(n))
            {
                set.add(n);
                int sum=0;
                 int temp=n;
                while(temp!=0)
                {
                    int rem = temp%10;
                    sum+=rem*rem;
                    temp/=10;
                }
                n=sum;

            }
            else{
                return false;
            }
        }
        return true;
    }
}