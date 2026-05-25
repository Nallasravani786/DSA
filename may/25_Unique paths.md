#### I M A G E

<img width="2642" height="1362" alt="image" src="https://github.com/user-attachments/assets/9e9f2ea5-fdcf-4311-9ebf-2f37035b741a" />

#### I N T U I T I O N
To reach a cell, robot can come only from top or left.

So, total paths for current cell = paths from top + paths from left.

Base case: reaching (0,0) means one valid path is found.

If indices go outside grid, it is an invalid path, so return 0.

Same cells are computed multiple times, so use DP memoization.

dp[i][j] stores number of unique paths to reach cell (i,j).

###### m e m o i z a t i o n _ c o d e

```cpp
int f(int i,int j,vector<vector<int>>&dp){
    
    //base case
    if(i == 0 && j == 0)   return 1;
    if( i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int ways = f(i-1,j,dp)+ f(i,j-1,dp);

    return dp[i][j] = ways;
 }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp);
    }
```

###### t a b u l a t i o n _ c o d e
```cpp
 int uniquePaths(int m , int n){
    vector<vector<int>>dp(m,vector<int>(n,0));

    for(int i=0;i<m;i++) dp[i][0] = 1;
    for(int j=0;j<n;j++) dp[0][j] =1;

    for(int i=1;i<m;i++){

        for(int j=1;j<n;j++){

            int ways = dp[i][j-1] + dp[i-1][j];

            dp[i][j] = ways;
        }
    }
    return dp[m-1][n-1];
 }

```
###### s p a c e _ o p t i m i z a t i o n _ c o d e 
```cpp
int uniquePaths(int m , int n){

    vector<int>curr(n,1),prev(n,1);

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){

            curr[j] = curr[j-1] + prev[j];
        }
        prev = curr;
    }
    return prev[n-1];
  }
```
