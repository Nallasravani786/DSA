#### I M A G E

<img width="2845" height="1339" alt="image" src="https://github.com/user-attachments/assets/309c01be-b085-44b0-8cb6-5032ad57b87e" />

#### I N T U I T I O N
To reach a cell, robot can come only from top or left.

If a cell contains an obstacle, that path becomes invalid, so return 0.

Base case: reaching (0,0) means one valid path is found.

For every cell, total paths = paths from top + paths from left.

If indices go outside grid, it is an invalid path, so return 0.

Same (i,j) states repeat many times, so use DP memoization.

dp[i][j] stores number of valid paths to reach cell (i,j).


###### m e m o i z a t i o n _ c o d e
```cpp
 int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
    
    //base cases
    if(i<0 || j<0) return 0;
    if(obstacleGrid[i][j] == 1) return 0;
    if(i == 0 && j == 0) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int  ways = f(i-1,j,dp,obstacleGrid) + f(i,j-1,dp,obstacleGrid);

    return dp[i][j] = ways;
  }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       int m = obstacleGrid.size();
       int n = obstacleGrid[0].size();

       vector<vector<int>>dp(m,vector<int>(n,-1));
       return f(m-1,n-1,dp,obstacleGrid);
    }

```
###### t a b u l a t i o n _ c o d e
```cpp
 int uniquePathsWithObstacles(vector<vector<int>>&obstacleGrid){

      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();

      vector<vector<int>>dp(m,vector<int>(n,0));

     for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){

            if(obstacleGrid[i][j] == 1) dp[i][j] = 0;

            else if(i == 0 &&  j==0) dp[i][j] = 1;

            else {
                  int up =0,left =0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
     }
      return dp[m-1][n-1];
   }
```

###### s p a c e _ o p t i m i z a t i o n _ c o d e
```cpp
int uniquePathsWithObstacles(vector<vector<int>>&obstacleGrid){

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    
    vector<int>prev(n,0),curr(n,0);

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){

            if(obstacleGrid[i][j] == 1) curr[j] = 0;
            else if(i==0 && j == 0) curr[j] = 1;

            else {
                int up = 0,left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = curr[j-1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

```
