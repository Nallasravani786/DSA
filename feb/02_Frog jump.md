## I N T U I T I O N (memoization) 
This is a DP + recursion solution to find the minimum energy needed to reach the last index.

f(ind) means: minimum cost to reach index ind from index 0.

From any index ind, you have two choices:

Jump from ind-1 (cost = previous cost + height difference).

Jump from ind-2 (only if ind > 1).

We take the minimum cost of these two jumps, because we want the least energy path.

dp[ind] stores the already computed result so we don’t recompute the same subproblem again.

Base case:
ind == 0 → cost = 0 (already at the start).

T.C: O(n)   S.C:O(n)

##### M E M O I S A T I O N
```cpp
int f(int ind, vector<int>&height,vector<int>&dp){
      if(ind==0) return 0;
      if(dp[ind]!=-1) return dp[ind];
      
      int jump2=INT_MAX;
      int jump1 = f(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
      if(ind>1) jump2 = f(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
      return dp[ind] = min(jump1,jump2);
      
  }
  
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int>dp(n,-1);
        return f(n-1,height,dp);
        
    }
```
## I N T U I T I O N (Tabulation)

**Intuition:**

- Build solution from **0 → n−1**

- At each stair, take the **minimum of coming from 1 step or 2 steps back**

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`

```cpp
int minCost(vector&lt;int&gt;& height) {

    int n = height.size();

    vector&lt;int&gt; dp(n, 0);

    dp\[0\] = 0;

    for (int ind = 1; ind &lt; n; ind++) {

        int jump1 = dp\[ind - 1\] + abs(height\[ind\] - height\[ind - 1\]);

        int jump2 = INT_MAX;

        if (ind &gt; 1)

            jump2 = dp\[ind - 2\] + abs(height\[ind\] - height\[ind - 2\]);

        dp\[ind\] = min(jump1, jump2);

    }

    return dp\[n - 1\];

}
```

## I N T U T I O N (Space optimization)

**Intuition:**

- Only the **previous two states** are needed at any time

- Replace DP array with **two variables**

**Time Complexity:** `O(n)`
**Space Complexity:** `O(1)`

```cpp
int minCost(vector<int>& height) {
      int n = height.size();
      
       int prev1 = 0;
       int prev2=0;
       int curr =0;
       int jump2 = INT_MAX;
       for(int ind =1;ind<n;ind++){
      int jump1 = abs(height[ind]-height[ind-1]) + prev1;
      
      if(ind >1) jump2 = abs(height[ind]-height[ind-2]) + prev2;
         curr=  min(jump1,jump2);
         
         prev2 =prev1;
         prev1 = curr;
       }
       
        return curr;
    }
```


