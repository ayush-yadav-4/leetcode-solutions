class Solution {
    public List<String> simplifiedFractions(int n) {
        List<String> list = new ArrayList<>();
        for(int deno=2;deno<=n;deno++){
            for(int num=1;num<deno;num++){
                if(gcd(num,deno)==1){
                    list.add(num+"/"+deno);
                }
            }
        }
        return list;
    }
    private int gcd(int a,int b){
        while(b!=0){
            int temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
}