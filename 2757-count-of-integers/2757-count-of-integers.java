class Solution {
    Integer[][][]dp;
    public int count(String num1, String num2, int min_sum, int max_sum) {        
       // dp=new Integer[23][2][401];
      // num1=f1(num1);
     //  num2=f1(num2);
     //   System.out.println(num1.length()+" "+num2.length());
        int a=f1(num1,min_sum,max_sum);
        int b=f1(num2,min_sum,max_sum);
       // System.out.println(a+" "+b);
        if(ff(num1,min_sum,max_sum)){
           return (b-a+1+(int)(1e9+7))%((int)(1e9)+7);
        }
        else{
            return (b-a+(int)(1e9+7))%((int)(1e9)+7); 
        }
    }
    public int f(int idx,String s,int min,int max,int f,int aa){
        if(aa>max)return 0;
        if(idx==s.length()){
            if(aa<=max&&aa>=min)return 1;
            return 0;
        }
        if(dp[idx][f][aa]!=null)return dp[idx][f][aa];
             int nf=9;
             if(f==1){
              nf=s.charAt(idx)-'0';               
             }
             int ans=0;
             for(int i=0;i<=nf;i++){
               if(f==1&&i==s.charAt(idx)-'0'){
                ans+=f(idx+1,s,min,max,1,aa+i);
               }
               else{
                  ans+=f(idx+1,s,min,max,0,aa+i);
               }   
               ans=(ans)%((int)(1e9)+7);               
             }
             return dp[idx][f][aa]=ans;
    }
    public boolean ff(String s,int min,int max){
        int ans=0;
        for(int i=0;i<s.length();i++){
            ans+=(s.charAt(i)-'0');
        }
        return ans>=min&&ans<=max;
    }
    public int f1(String s,int min,int max){
        dp=new Integer[s.length()][2][401];
       return f(0,s,min,max,1,0);
    }
}