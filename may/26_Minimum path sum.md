#### I M A G E
<img width="2839" height="1338" alt="image" src="https://github.com/user-attachments/assets/910b5fe8-f483-47e4-afdd-0ebddb319b2a" />

#### I N T U I T I O N

To reach a cell (i,j), you can come only from top (i-1,j) or left (i,j-1).

Current cell cost must always be included in the path sum.

So, minimum cost for current cell = grid[i][j] + min(top path, left path).

Base case: at (0,0), minimum sum is simply grid[0][0].

If indices go outside grid, treat it as an invalid path by returning a very large value (1e9).

Same states repeat many times, so use DP memoization.

dp[i][j] stores the minimum path sum to reach cell (i,j)

###### m e m o i z a t i o n _ c o d e
```cpp
int f(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    if(i==0 && j==0) return grid[0][0];

    if(i<0 || j<0) return 1e9;

    if(dp[i][j]!=-1) return dp[i][j];

    int up = grid[i][j] + f(i-1,j,grid,dp);
    int left = grid[i][j] + f(i,j-1,grid,dp);

    return dp[i][j] = min(up,left);
 }


    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));


        return f(m-1,n-1,grid,dp);  
    }


```

###### t a b u l a t i o n _ c o d e
```cpp
int minPathSum(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>dp(m,vector<int>(n,0));

    dp[0][0] = grid[0][0];

    for(int i=1;i<m;i++) dp[i][0] = grid[i][0] + dp[i-1][0];
    for(int j=1;j<n;j++) dp[0][j] = grid[0][j] + dp[0][j-1];

    for(int i=1;i<m;i++){

        for(int j =1;j<n;j++){

            int up = grid[i][j] + dp[i-1][j];
            int left = grid[i][j] + dp[i][j-1];
            dp[i][j] = min(up,left);
        }
    }
    return dp[m-1][n-1];
 }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e
```cpp
int minPathSum(vector<vector<int>>&grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int>prev(n,0),curr(n,0);

   curr[0] = grid[0][0];
   for(int j=1;j<n;j++) curr[j] = grid[0][j] + curr[j-1];

   prev = curr;

   for(int i=1;i<m;i++){

      curr[0] = grid[i][0] + prev[0];

    for(int j=1;j<n;j++){

        int up = grid[i][j] + prev[j];
        int left = grid[i][j] + curr[j-1];
        curr[j] = min(up,left);
        }
    prev = curr;
   }
   return prev[n-1];
}
```
