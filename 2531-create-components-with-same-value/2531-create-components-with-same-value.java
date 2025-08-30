class Solution {
    public int componentValue(int[] nums, int[][] edges) {
        int n = nums.length;
        // Build adjacency list
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] e : edges) {
            graph[e[0]].add(e[1]);
            graph[e[1]].add(e[0]);
        }

        // Total sum of values
        int total = 0;
        for (int v : nums) total += v;

        // Try all divisors of total (larger ones first to maximize cuts)
        for (int k = total; k >= 1; k--) {
            if (total % k != 0) continue;  // must divide evenly
            int target = total / k;       // each component sum
            if (dfsCheck(0, -1, graph, nums, target) == 0) {
                return k - 1;  // number of edges we can delete
            }
        }
        return 0;
    }

    // DFS returns sum of subtree modulo target
    private int dfsCheck(int node, int parent, List<Integer>[] graph, int[] nums, int target) {
        int sum = nums[node];
        for (int nei : graph[node]) {
            if (nei == parent) continue;
            int childSum = dfsCheck(nei, node, graph, nums, target);
            if (childSum == -1) return -1;
            sum += childSum;
        }
        if (sum > target) return -1;   // invalid
        if (sum == target) return 0;   // cut here
        return sum;
    }
}
