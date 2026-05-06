#### I M A G E
<img width="2843" height="1419" alt="image" src="https://github.com/user-attachments/assets/0982ee5b-4793-4f39-a90f-4c8ca60a237c" />

#### I N T U I T I O N
To reach a step, you can come from either:

previous step (i-1)

two steps before (i-2)

For every step, choose the path with minimum cost

dp[i] stores:

👉 minimum cost to reach step i

Transition:

👉 current cost + minimum of previous two costs

Final answer:

👉 minimum of last two steps, because top can be reached from either of them 🚀

###### m e m o i z a t i o n
```cpp
  int f(int ind,vector<int>&dp,vector<int>&cost){
    if(ind==0 || ind ==1) return cost[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int one = cost[ind] + f(ind-1,dp,cost);
    int two = cost[ind] +f(ind-2,dp,cost);
    return dp[ind] = min(one,two);
  }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(f(n-1,dp,cost),f(n-2,dp,cost));
    }

```
###### t a b u l a t i o n
```cpp
int minCostClimbingStairs(vector<int>&cost){
            int n = cost.size();
            vector<int>dp(n,0);
            if(n==1) return cost[0];
            dp[0] = cost[0];
            dp[1] = cost[1];

            for(int ind =2;ind<n;ind++){
            int one = cost[ind]+ dp[ind-1];
            int two = cost[ind] + dp[ind-2];
            dp[ind] = min(one,two);
            
            }
            return min(dp[n-1],dp[n-2]);

    }

```

###### s p a c  e _ o p t i m i z a t i o n

```cpp
int minCostClimbingStairs(vector<int>&cost){
    int n = cost.size();
    int prev2 =cost[0], prev1 = cost[1];

    for(int ind =2;ind<n;ind++){
      int curr = cost[ind] + min(prev2,prev1);
      prev2 = prev1;
      prev1 = curr;
    }
    return min(prev1,prev2);
}
```

