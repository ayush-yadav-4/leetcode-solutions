import java.util.Random;

class Solution {
    private int[] original;
    private int[] array;
    private Random rand;

    public Solution(int[] nums) {
        original = nums.clone(); // store the original configuration
        array = nums.clone();    // working copy for shuffling
        rand = new Random();
    }
    
    public int[] reset() {
        array = original.clone(); // restore to original state
        return array;
    }
    
    public int[] shuffle() {
        for (int i = array.length - 1; i > 0; i--) {
            int j = rand.nextInt(i + 1); // random index between 0 and i
            swap(i, j);
        }
        return array;
    }
    
    private void swap(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}