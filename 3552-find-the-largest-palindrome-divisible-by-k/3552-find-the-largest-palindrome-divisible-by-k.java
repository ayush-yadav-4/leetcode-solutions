class Solution {
    public String largestPalindrome(int n, int k) {
        if(k == 1 || k == 3 || k == 9){
            return handle169(n);
        }
        else if(k == 2){
            return handle2(n);
        }
        else if(k == 4){
            return handle4(n);
        }
        else if(k == 5){
            return handle5(n);
        }
        else if(k == 6){
            return handle6(n);
        }
        else if(k == 7){
            return handle7(n);
        }
        else if(k == 8){
            return handle8(n);
        }
        else{
            return "-1";
        }
    }

    private String handle169(int n){
        StringBuilder sb = new StringBuilder(n);
        for(int i=0; i<n; i++) sb.append("9");
        return sb.toString();
    }

    private String handle2(int n){
        if(n == 1) return "8";
        if(n == 2) return "88";
        String s = handle169(n);
        s = "8"+s.substring(1, n-1)+"8";
        return s; 
    }

    private String handle4(int n){
        if(n == 1) return "8";
        if(n == 2) return "88";
        if(n == 3) return "888";
        if(n == 4) return "8888";
        String s = handle169(n);
        s = "88"+s.substring(2, n-2)+"88";
        return s;         
    }

    private String handle5(int n){
        if(n == 1) return "5";
        if(n == 2) return "55";
        String s = handle169(n);
        s = "5"+s.substring(1, n-1)+"5";
        return s;
    }

    private String handle6(int n){
        if(n == 1) return "6";
        if(n == 2) return "66";
        String s = handle2(n);
        if(n%2 == 0){
            s = s.substring(0, n/2-1) + "77" + s.substring(n/2+1, n);
        }
        else{
            s = s.substring(0, n/2) + "8" + s.substring(n/2+1, n);
        }
        return s;
    }

    private String handle7(int n){
        if(n == 1) return "7";
        if(n == 2) return "77";
        String s = handle169(n);

        if(n%2 == 0){
            for(int i=9; i>=0; i--){
                s = s.substring(0, n/2-1) + i+""+i + s.substring(n/2+1, n);
                int remainder = 0;
                for(int j=0; j<n; j++) remainder = (remainder * 10 + s.charAt(j) - '0')%7;
                if(remainder == 0) return s;
            }
        }
        else{
            for(int i=9; i>=0; i--){
                s = s.substring(0, n/2) + i + s.substring(n/2+1, n);
                int remainder = 0;
                for(int j=0; j<n; j++) remainder = (remainder * 10 + s.charAt(j) - '0')%7;
                if(remainder == 0) return s;
            }
        }
        return "-1";
    }

    private String handle8(int n){
        if(n == 1) return "8";
        if(n == 2) return "88";
        if(n == 3) return "888";
        if(n == 4) return "8888";
        if(n == 5) return "88888";
        if(n == 6) return "888888";
        String s = handle169(n);
        s = "888" + s.substring(3, n-3) + "888";
        return s;
    }

}