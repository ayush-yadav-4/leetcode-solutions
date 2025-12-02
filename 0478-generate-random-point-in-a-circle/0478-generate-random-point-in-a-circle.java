class Solution {
    double r;
    double x;
    double y;

    public Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    public double[] randPoint() {
        Random rand = new Random();
        double angle = 2 * Math.PI * rand.nextDouble(); 
        double radius = r * Math.sqrt(rand.nextDouble());
        return new double[]{radius * Math.cos(angle) + x, radius * Math.sin(angle) + y};
    }
}