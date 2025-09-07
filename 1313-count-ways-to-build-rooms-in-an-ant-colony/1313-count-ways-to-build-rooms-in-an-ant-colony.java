class Solution {
    public static final int MOD = (int)1e9 + 7;
    public int waysToBuildRooms(int[] prevRoom) {
        /*
        can view the rooms as a tree with 0 as the root.
        An order of building the rooms is represented by the order in which new nodes of the tree are traversed when going in a special way.
        Always start with the root node of the tree as build always starts with 0.
        From here, can go to any of the root nodes immediate children (i.e. any with prevRoom[i] = 0)
        
        Assume the root node as children c_1 - c_k. 
        If we want to calculate the travsersals/build orders if we first build c_i, observe what can do. 

        Obviously, can treat c_i as new root to it's own subtree and compute it's different traversal orders as a subproblem i.e. dp. 
        However, at any point can also return to start/build diffeernet child paths in c_1 - c_k of original tree.

        Let dp[i] be the ways to build all the rooms in the i-rooted subtree.
        
        Since we can branch and switch between child paths at any time, we can "interlace" different child paths. 

        So each child of i has dp[child[i]] orders for their own subtree, each of which we can combine with the other child orders, to get a product of all child
        orders. Additionally, these child orders can be interlaced in various ways. i.e. child1Tree, child2Tree, child1Tree -> child1Tree, child1Tree, child2Tree or 
        child2Tree, child1Tree, child1Tree are all valid if in tree orderings are valid as both trees should be disjoint. 

        Thus in addition to the combination of orders for dp[i] = product(dp[child[i]]) need to choose ways to interlace.
        know that ith (root) wiill always come first and there will be sz[i]-1 nodes in remaingin tree.
        Therefore sum(sz[child[i]]) for all children of i = sz[i]-1, or there are sz[i]-1 total descendants of ith node.

        Instead of interlacing all at once, we can set up arbitrary indices 1 - (sz[i]-1) where we we choose sz[child] of these indices for the subtree
        rooted at some direct descendant "child" of i to occupy. This gives ((sz[i]-1) choose sz[child]) seleections. 
        Then for the next child, "child2" of i, those indices have already been chosen so only have sz[i]-sz[child1]-1 indices to choose from so there are 
        ((sz[i]-sz[child]-1) choose sz[child2]) selections. This continues for all children until the last where we get 
        sz[child_k] choose sz[child_k] or 1 selection as it must take all not yet selected indices. 

        This means number of interlacings of any set of orderigns of children of tree rooted at i = 
        product((sz[i] - 1 - (sum(child_j) j = 1 to k-1) choose child_k) from k = 1 to s, where s is number of children of i. 
        Let this product = interlace. 

        then dp[i] = product(dp[child] for all children) * interlace.

        this interlace product is also just a multinomial coefficient (sz[i] - 1 choose (sz[child1], sz[child2], ... sz[childk])) = 
        could use the product of binomials for this or could use def = (sz[i]-1)! / (sz[child1]! * sz[child2]! * ...sz[childk]!)

        since am computing answer modulo, would use mod inverse not div, and since sizes are bounded up to n, can just precompute all 
        factorials and mod inv factorials, then compute 
        interlace = (sz[i]-1)! * invFact[sz[child1]] * ... invFact[sz[childk]]

        base case is for leaf nodes with no children, these obviously have one ordering of just themselves. 

        */
        int n = prevRoom.length;
        long[] dp = new long[n];
        Arrays.fill(dp, 1); //since all dp relations are products, fill with multiplicative identity to start with for convenience
        int[] sz = new int[n];
        Arrays.fill(sz, 1); //also all sizes default are 1 as has at least their own node.

        long[] factorial = new long[n];
        long[] invFactorial = new long[n];
        factorial[0] = 1;
        for(int i = 1; i < n; i++) {
            factorial[i] = (factorial[i-1]*i) % MOD;
        }
        invFactorial[n-1] = modExp(factorial[n-1], MOD-2);
        for(int i = n-1; i > 0; i--) {
            invFactorial[i-1] = (invFactorial[i] * i) % MOD; 
        }

        int[] childCnt = new int[n];
        int leaves = n;
        for(int i = 1; i < n; i++) {
            if(++childCnt[prevRoom[i]] == 1) leaves--;
        }

        int[] topoQueue = new int[leaves];
        int queueRight = 0, queueLeft = 0;
        for(int i = 0; i < n; i++) {
            if(childCnt[i] == 0) {
                topoQueue[queueRight++] = i; //leaf nodes are base case with answers = 1 and should be processed first in topological order.
            }
        }
        queueRight = 0;
        
        while(topoQueue[queueLeft] != 0) {
            int curr = topoQueue[queueLeft], parent = prevRoom[curr];
            queueLeft = (queueLeft + 1) % leaves; 

            dp[parent] = (dp[parent] * dp[curr]) % MOD;
            dp[parent] = (dp[parent] * invFactorial[sz[curr]]) % MOD;
            sz[parent] += sz[curr];
            if(--childCnt[parent] == 0) { //if processed all children, then finish dp calc and queue for topo processing
                dp[parent] = (dp[parent] * factorial[sz[parent]-1]) % MOD;
                topoQueue[queueRight] = parent;
                queueRight = (queueRight + 1) % leaves;
            }
        }

        return (int)dp[0];
    }


    private int modExp(long base, int exp) {
        long mult = base, res = 1;
        while(exp > 0) {
            if((exp & 1) == 1) res = (res * mult) % MOD;
            mult = (mult * mult) % MOD;
            exp >>= 1;
        }
        return (int)res;
    }

    
}