## I N T U T I O N 
This is a DP + recursion (memoization) solution to find the minimum energy needed to reach the last index.

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
