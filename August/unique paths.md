###### C O D E ( memoization )
```cpp
int f(int i,int j,vector<vector<int>>&dp,int m,int n){
    if(i == 0 && j == 0) return 1;
    if(i <0 || j<0 || i>=m || j >= n) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int top = f(i-1,j,dp,m,n);
    int left = f(i,j-1,dp,m,n);

    return dp[i][j] = top + left;
   }

   
  int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,m,n);     
    }
```

###### C O D E( tabulation )
```cpp
int uniquePaths(int m,int n){
        vector<vector<int>>dp(m,vector<int>(n,1));

       // there is only 1 way to reach any cell along first row and any cell along first column ( so intialize all to 1 intially)
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               
                int top = dp[i-1][j];
                int left = dp[i][j-1];

                dp[i][j] = top + left;
            }
        }
        return dp[m-1][n-1];
    }

```

###### C O D E ( space optimization )

```cpp
 int uniquePaths(int m,int n){

        vector<int>prev(n,1),curr(n,1);

        for(int i=1;i<m;i++){
           for(int j=1;j<n;j++){

            int top = prev[j];
            int left = curr[j-1];
            curr[j] = top + left;
            
           }
           prev = curr;
        }
        return prev[n-1];
    }

```

