class Solution {
    class Pair {
        int node, cost, stops;
        Pair(int node, int cost, int stops){
            this.node = node;
            this.cost = cost;
            this.stops = stops;
        }
    }

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {

        List<List<Pair>> adj = new ArrayList<>();
        for(int i=0;i<n;i++) adj.add(new ArrayList<>());

        for(int[] f : flights){
            adj.get(f[0]).add(new Pair(f[1], f[2], 0));
        }

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(src, 0, 0));

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        while(!q.isEmpty()){
            Pair cur = q.poll();

            int node = cur.node;
            int cost = cur.cost;
            int stops = cur.stops;

            if(stops > k) continue;

            for(Pair nei : adj.get(node)){
                int newCost = cost + nei.cost;

                if(newCost < dist[nei.node]){
                    dist[nei.node] = newCost;
                    q.add(new Pair(nei.node, newCost, stops+1));
                }
            }
        }

        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}
