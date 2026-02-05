import java.util.*;

class Solution {

    boolean checkstr(String s){
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(!(Character.isLetterOrDigit(c) || c == '_')){
                return false;
            }
        }
        return true;
    }

    boolean checkBusiness(String s){
        return s.equals("electronics") || s.equals("grocery") 
            || s.equals("pharmacy") || s.equals("restaurant");
    }

    public List<String> validateCoupons(String[] code, String[] businessLine, boolean[] isActive) {

        Map<String,Integer> order = new HashMap<>();
        order.put("electronics",0);
        order.put("grocery",1);
        order.put("pharmacy",2);
        order.put("restaurant",3);

        List<String[]> list = new ArrayList<>();

        for(int i = 0; i < code.length; i++){

            if(code[i].length() == 0) continue;   // only skip empty

            if(checkstr(code[i]) && checkBusiness(businessLine[i]) && isActive[i]){
                list.add(new String[]{businessLine[i], code[i]});
            }
        }

        Collections.sort(list, (a,b)->{
            int cmp = order.get(a[0]) - order.get(b[0]);
            if(cmp != 0) return cmp;
            return a[1].compareTo(b[1]);
        });

        List<String> ans = new ArrayList<>();
        for(String[] arr : list) ans.add(arr[1]);

        return ans;
    }
}
