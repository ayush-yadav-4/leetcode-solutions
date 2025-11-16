class Solution {
    int nums = 0;
    public List<Integer> grayCode(int n) {
        List<Integer> out = new ArrayList<>();
        helper(n, out);
        return out;
    }
    private void helper(int n, List<Integer> out){
        if(n==0){
            out.add(nums);
            return;
        }
        helper(n-1, out);
        nums^=(1<<n-1);
        helper(n-1, out);
    }
}