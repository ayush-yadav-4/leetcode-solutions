class Solution {
    Map<Integer,Set<Integer>> graph;
    Map<Integer, Integer> path;
    int[] result;
    boolean[][] coprimes;
    int[][] memo;
    
    public int[] getCoprimes(int[] nums, int[][] edges) {
        int n = nums.length;
        
        result = new int[n];//for storing the result
        graph = new HashMap<>();//graph of the tree of coprimes
        memo = new int[n][51];//memoize the search for ancestor to avoid TLE
        coprimes = new boolean[51][51];//precompute matrix of coprimes
        
        //create the graph
        for(int[] edge: edges){
            graph.computeIfAbsent(edge[0], k->new HashSet<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], k->new HashSet<>()).add(edge[0]);
        }
         
        //precompute coprimes. 
        //Notice that matrix is symmetric
        for(int i=1; i<=50; i++){
            for(int j=1; j<=50; j++){
                if(i>=j){
                    boolean coprime = gcd(i,j) == 1;
                    coprimes[i][j] = coprime;
                    coprimes[j][i] = coprime;
                }
            }
        }
        
        for(int[] m: memo)
            Arrays.fill(m,-1);
        
        //keep track of paths while performing BFS
        path = new HashMap<>();
        
        //Queue for BFS
        Queue<Integer> queue = new LinkedList<>();
        
        path.put(0,-1);
        queue.offer(0);
        while(!queue.isEmpty()){
            
            int cur = queue.poll();
            
            //get ancestor using path map and memoization
            result[cur] = getCoprimeAncestor(cur,path.get(cur), nums);
            if(!graph.containsKey(cur))continue;
            
            for(int child: graph.get(cur)){
                if(!path.containsKey(child)){
                    queue.offer(child);
                    path.put(child,cur);
                }
            }
        }
        return result;
    }
    
    private int getCoprimeAncestor(int cur, int parent, int[] nums){
        if(parent == -1)return -1;
        if(memo[parent][nums[cur]] >= 0)return memo[parent][nums[cur]];
        
        int ans = 0;
        if(coprimes[nums[cur]][nums[parent]]){
            ans = parent;
        }else{
            
            if(nums[cur] == nums[parent])
                ans = result[parent];
            else
                ans = getCoprimeAncestor(cur, path.get(parent), nums);
        }
        memo[parent][nums[cur]] = ans;
        return ans;
    }
    
   
    private int gcd(int a, int b){
        if(b == 0)return a;
        return gcd(b, a%b);
    }
    
    
}