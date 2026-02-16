class Solution {
    public int firstUniqueFreq(int[] nums) {
        Map<Integer, Integer> mp = new LinkedHashMap<>();
        Set<Integer> st = new LinkedHashSet<>();
        for(int i=0;i<nums.length;i++){
           mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }
       int deleted = 0;
       List<Integer> del = new ArrayList<>();
        for(Map.Entry<Integer, Integer> m : mp.entrySet()){
            if(st.contains(m.getValue())){
                  del.add(m.getValue());
                st.remove(m.getValue());
            }
            else if(del.contains(m.getValue()) == false)st.add(m.getValue());
        }
        if(st.size() == 0) return -1;
       
        int freq = st.iterator().next();
        for(Map.Entry<Integer, Integer> m : mp.entrySet()){
            if(m.getValue() == freq){
                return  m.getKey();
            }
        }

        return -1;
    }
}