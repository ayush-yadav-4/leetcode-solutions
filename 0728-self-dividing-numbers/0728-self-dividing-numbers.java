class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> arr=new ArrayList<>();
        for(int i=left;i<=right;i++){
            if(helper(i))
            {
                arr.add(i);
            }
        }
        return arr;
    }
    public boolean helper(int num){
        int temp=num;
        while(temp>0){
            int dig=temp%10;
            if(dig==0||num%dig!=0){
                return false;
            }
            temp=temp/10;
        }
        return true;
    }
}