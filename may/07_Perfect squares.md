#### I M A G E
<img width="2839" height="1393" alt="image" src="https://github.com/user-attachments/assets/2c401a1f-293b-49b0-a684-6839e1a67285" />

#### I N T U I T I O N

For every number n, try all possible perfect squares (1, 4, 9, ...)

Pick one square and solve the remaining value:

👉 n - square

Add 1 because current square is used

Take the minimum among all choices

Use dp[] to store answers and avoid repeated calculations 🚀

###### m e m o i z a t i o n
```cpp
int f(int n, vector<int>&dp){
     if(n ==0) return 0;

     if(dp[n]!=-1) return dp[n];
     int ans = INT_MAX;

      for(int i=1;i*i<=n;i++){
        int sq = i*i;
        ans = min(ans,1+f(n-sq,dp));
      }
      return dp[n] = ans;
  }



    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }


```

###### t a b u l a t i o n 

```cpp
int numSquares(int n){
      vector<int>dp(n+1,0);
      dp[0] = 0;

      for(int k = 1; k <=n;k++){
        int ans = INT_MAX;
         
       for(int i =1;i*i<=k;i++){
        int sq = i*i;
        ans = min(ans,1+dp[k-sq]);
         }
         dp[k] = ans;
      }
      return dp[n];
   }

```
###### No further space optimization code in available
