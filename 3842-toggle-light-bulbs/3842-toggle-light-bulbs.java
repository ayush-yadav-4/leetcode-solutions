class Solution {
    public List<Integer> toggleLightBulbs(List<Integer> bulbs) {
        int[] freq = new int[101];
        Arrays.fill(freq,0);

        for(int i=0;i<bulbs.size();i++){
            if(freq[bulbs.get(i)] == 1){
                freq[bulbs.get(i)] = 0;
            }
            else{
                freq[bulbs.get(i)]= 1;
            }
        }
        List<Integer> ans = new ArrayList<>();
        for(int i=1;i<=100;i++){
            if(freq[i] == 1){
                ans.add(i);
            }
        }
        return ans;
    }
}