class Solution {
    public List<Integer> majorityElement(int[] nums) {

        int elem1 = 0, elem2 = 0;
        int count1 = 0, count2 = 0;

        // Step 1: Find candidates
        for(int num : nums){

            if(num == elem1) count1++;

            else if(num == elem2) count2++;

            else if(count1 == 0){
                elem1 = num;
                count1 = 1;
            }

            else if(count2 == 0){
                elem2 = num;
                count2 = 1;
            }

            else{
                count1--;
                count2--;
            }
        }

        // Step 2: Verify counts
        count1 = 0;
        count2 = 0;

        for(int num : nums){
            if(num == elem1) count1++;
            else if(num == elem2) count2++;
        }

        List<Integer> ans = new ArrayList<>();
        int n = nums.length;

        if(count1 > n/3) ans.add(elem1);
        if(count2 > n/3) ans.add(elem2);

        return ans;
    }
}