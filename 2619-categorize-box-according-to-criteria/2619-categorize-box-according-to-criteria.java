class Solution {
    public String categorizeBox(int length, int width, int height, int mass) {
        boolean bulky = Math.max(length, Math.max(width, height)) >= 1e4 || (long) length*width*height >= 1e9, heavy = mass >= 100; 
        if (bulky && heavy) return "Both"; 
        if (bulky) return "Bulky"; 
        if (heavy) return "Heavy"; 
        return "Neither"; 
    }
}