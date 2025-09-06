import java.math.*;
class Solution {
    public List<Integer> addToArrayForm(int[] num, int k) {
        String s="";
        for(int i=0;i<num.length;i++){
            s+=num[i];
        }
        BigInteger k1=new BigInteger(k+"");
        BigInteger y=new BigInteger(s);
        BigInteger sum=y.add(k1);
        String h=sum+"";
        List<Integer> arr=new ArrayList<>();
        for(int i=0;i<h.length();i++){
            int j=Integer.parseInt(h.charAt(i)+"");
            arr.add(j);
        }
        return arr;
    }
}