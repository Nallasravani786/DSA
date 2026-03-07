<img width="2792" height="1046" alt="image" src="https://github.com/user-attachments/assets/29b3e841-bbbb-4fb0-9fc5-3fa8c9d5972d" />

### I N T U I T I O N 
We want to find the number of ways to get sum x using n dice, where each die has m faces.

For each die, we can choose any value from 1 to m, so we try all possibilities and reduce the remaining sum (sum - m).

The recursion continues until all dice are used; if the remaining sum becomes 0, it is a valid way.

DP (memoization) stores results for (dice, sum) so we don’t recompute the same states.

This converts the exponential recursion into a more efficient dynamic programming solution


######  C O D E (MEMOIZATION)
```cpp
int solve(int faces, int dice, int sum,vector<vector<int>>&dp){
      if(dice==0){
          if(sum ==0) return 1;
          return 0;
      }
      if(sum<0) return 0;
      
      if(dp[dice][sum]!=-1) return dp[dice][sum];
      
      int ways =0 ;
      for(int m=1;m<=faces;m++){
          ways+=solve(faces,dice-1,sum-m,dp);
      }
      return dp[dice][sum] = ways;
  }
  
  
    int noOfWays(int m, int n, int x) {
       vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
       return solve(m,n,x,dp);
        
    }

```


###### C O D E (TABULATION)

```cpp
int noOfWays(int m, int n, int x) {
      vector<vector<int>>dp(n+1,vector<int>(x+1,0));
      dp[0][0] =1;
      
      for(int dice = 1;dice <=n; dice++){
          
          for(int sum = 1; sum<=x;sum++){
              
              for(int k = 1; k<=m && sum-k >=0 ; k++){
                  dp[dice][sum]+=dp[dice-1][sum-k];
              }
          }
      }
      return dp[n][x];
    }

```

###### C O D E (SPACE OPTIMIZATION)

```cpp
int noOfWays(int m, int n, int x) {
      vector<int>dp(x+1,0);
      dp[0] =1;
      for(int dice = 1; dice<=n;dice++){
          
          for(int sum = x; sum >=1;sum--){
              dp[sum]=0;
              
              for(int k =1;k<=m && sum-k >=0; k++){
                  dp[sum]+=dp[sum-k];
              }
          }
          dp[0] =0;
      }
      return dp[x];
    }

```





