#### I M A G E 
<img width="2845" height="1357" alt="image" src="https://github.com/user-attachments/assets/a5e9e52b-d3d5-4115-8321-bdf28adf5f2c" />

#### I N T U I T I O N 
To reach step n, you can come from (n-1) or (n-2)

So total ways = ways(n-1) + ways(n-2)

Use recursion to break problem into smaller subproblems

Use dp[] to store already computed results (avoid recomputation)

Each value of n is calculated only once → makes it efficient

👉 One line:
“Store results of subproblems so recursion doesn’t repeat work” 🚀

###### m e m o i z a t i o n
```cpp
int f(int n, vector<int>&dp){
    if(n<=2) return n;

    if(dp[n]!=-1) return dp[n];
    return dp[n] = f(n-1,dp) + f(n-2,dp);
  }


    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }

```

###### t a b u l a t i o n 
```cpp
int climbStairs(int n) {
    if(n <= 2) return n;

    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

```

###### s p a c e_o p t i m i z a t i o n

```cpp
int climbStairs(int n) {
    if(n <= 2) return n;

    int prev2 = 1; // dp[i-2]
    int prev1 = 2; // dp[i-1]

    for(int i = 3; i <= n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

```

