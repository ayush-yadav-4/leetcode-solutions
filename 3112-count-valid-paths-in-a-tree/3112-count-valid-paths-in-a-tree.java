class Solution {
    long count;
    public long countPaths(int n, int[][] edges) {
        boolean[] prime = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            prime[i] = true;
        }
        prime[0] = prime[1] = false;
        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }
        int[] counts = new int[n+1];
        for (int[] e: edges) {
            counts[e[0]]++;
            counts[e[1]]++;
        }
        int[][] tree = new int[n+1][];
        for (int i=1; i<=n; i++) tree[i] = new int[counts[i]];
        for (int[] e: edges) {
            tree[e[0]][--counts[e[0]]] = e[1];
            tree[e[1]][--counts[e[1]]] = e[0];
        }
        count = 0;
        traverse(1, 0, tree, prime);
        return count;
    }
    private long[] traverse(int node, int prev, int[][] tree, boolean[] prime) {
        long[] counts = new long[2];
        long count1 = 0;
        if (prime[node]) counts[1]++;
        else counts[0]++;
        for (int next: tree[node]) if (next != prev) {
            long[] c = traverse(next, node, tree, prime);
            count += counts[0] * c[1] + counts[1]*c[0];
            if (!prime[node]) {
                counts[0]+=c[0];
                counts[1]+=c[1];
            } else {
                counts[1]+=c[0];
            }
        }
        return counts;
    }
}