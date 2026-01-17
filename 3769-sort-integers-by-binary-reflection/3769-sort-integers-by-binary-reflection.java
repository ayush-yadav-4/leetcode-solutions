class Solution {
    int binary(int num){

       StringBuilder str = new StringBuilder();
       while(num > 0){
         str.append(num%2);
         num = num/2;
       }
       
       int p= 0,ans =0;
       for(int i = str.length()-1;i>=0;i--){
        ans += (Math.pow(2,p) * (str.charAt(i) - '0'));
        p++;
       }
       return ans;
       


    }
    public int[] sortByReflection(int[] nums) {
        List<int[]> ls = new ArrayList<>(
           
        );

        for(int i =0;i<nums.length;i++){
           int bin = binary(nums[i]);
           ls.add(new int[]{bin,i,nums[i]});
        }
        Collections.sort(ls, (a,b)->{
                if(a[0] != b[0]) return a[0] - b[0];
                return a[2] - b[2];
            });
            int[] ans = new int[nums.length];
            for(int i = 0;i<ls.size();i++){
               ans[i] = nums[ls.get(i)[1]];
            }
            return ans;
    }
}