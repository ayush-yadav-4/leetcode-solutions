import java.util.*;

class Solution {
    Map<String, List<Integer>> memo = new HashMap<>();

    public List<Integer> diffWaysToCompute(String expression) {
        if (memo.containsKey(expression)) return memo.get(expression);

        List<Integer> results = new ArrayList<>();

        for (int i = 0; i < expression.length(); i++) {
            char c = expression.charAt(i);
            if (c == '+' || c == '-' || c == '*') {
                // Split into left and right parts
                String leftExpr = expression.substring(0, i);
                String rightExpr = expression.substring(i + 1);

                List<Integer> left = diffWaysToCompute(leftExpr);
                List<Integer> right = diffWaysToCompute(rightExpr);

                // Combine results
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') results.add(a + b);
                        else if (c == '-') results.add(a - b);
                        else if (c == '*') results.add(a * b);
                    }
                }
            }
        }

        // Base case: no operator, it's a number
        if (results.isEmpty()) {
            results.add(Integer.parseInt(expression));
        }

        memo.put(expression, results);
        return results;
    }
}
