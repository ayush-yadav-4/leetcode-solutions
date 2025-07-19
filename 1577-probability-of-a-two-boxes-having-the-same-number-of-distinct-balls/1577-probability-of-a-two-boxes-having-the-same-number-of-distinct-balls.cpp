class Solution {
    vector<long double> fact;  // factorials for combination calculation
    int n;
    vector<int> balls;
    
    long double comb(int n, int r) {
        if (r > n) return 0;
        return fact[n] / (fact[r] * fact[n-r]);
    }
    
    long double dfs(int colorIndex, int box1BallsCount, int box1Distinct, int box2Distinct, long double ways, long double& totalWays, long double& validWays) {
        if (colorIndex == (int)balls.size()) {
            if (box1BallsCount == n) {
                totalWays += ways;
                if (box1Distinct == box2Distinct) {
                    validWays += ways;
                }
            }
            return 0;
        }
        
        int maxBalls = balls[colorIndex];
        for (int x = 0; x <= maxBalls; ++x) {
            int box1 = x;
            int box2 = maxBalls - x;
            
            // Prune if box1 balls exceed n or box2 balls exceed n
            if (box1BallsCount + box1 > n) continue;
            
            int newBox1Distinct = box1Distinct + (box1 > 0 ? 1 : 0);
            int newBox2Distinct = box2Distinct + (box2 > 0 ? 1 : 0);
            
            long double newWays = ways * comb(maxBalls, box1);
            
            dfs(colorIndex + 1, box1BallsCount + box1, newBox1Distinct, newBox2Distinct, newWays, totalWays, validWays);
        }
        
        return 0;
    }
    
public:
    double getProbability(vector<int>& balls_) {
        balls = balls_;
        n = 0;
        for (int b : balls) n += b;
        n /= 2;  // half balls go to box1, half to box2
        
        // Prepare factorials for combinations up to sum of balls (max 48)
        int maxBalls = accumulate(balls.begin(), balls.end(), 0);
        fact.resize(maxBalls+1, 1.0);
        for (int i = 1; i <= maxBalls; ++i) fact[i] = fact[i-1] * i;
        
        long double totalWays = 0.0, validWays = 0.0;
        dfs(0, 0, 0, 0, 1.0, totalWays, validWays);
        
        return (double)(validWays / totalWays);
    }
};
