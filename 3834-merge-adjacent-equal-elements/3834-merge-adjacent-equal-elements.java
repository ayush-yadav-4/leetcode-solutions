class Solution {
    boolean duplicate(List<Long> ls){
        for(int i=1;i<ls.size();i++){
            if(ls.get(i).equals(ls.get(i-1))){
                long num = ls.get(i);
                long sum = num + num;
                //int idx = ls.indexOf(ls.get(i-1));
                 ls.set(i-1,sum);
                 ls.remove(i);
               
                
               
                return true;
            }
        }
        return false;
    }
    public List<Long> mergeAdjacent(int[] nums) {
         List<Long>ls = new ArrayList<>();
         Stack<Long> st = new Stack<>();
         int n = nums.length;
         for(int i = 0; i < nums.length; i++){

            long val = nums[i];

            while(ls.size() > 0 && ls.get(ls.size()-1) == val){
                 
                val = ls.get(ls.size()-1) * 2;
                ls.remove(ls.size()-1);
            }

            ls.add(val);
        }
         
        //  while(!st.isEmpty()){
        //     long elem = st.peek();
        //     st.pop();
        //     if(st.size() == 0){
        //         ls.add(elem);
        //         return ls;
        //     }
        //     if(elem == st.peek()){
        //         st.pop();
              
        //         st.push(elem + elem);
        //     }
        //     else ls.add(elem);
            
        //  }
        // while(duplicate(ls)){}
        
        return ls;
    }
}