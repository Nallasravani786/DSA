#### I M A G E

<img width="2833" height="1367" alt="image" src="https://github.com/user-attachments/assets/62f52cea-94cb-441b-900a-be51b215dc97" />

#### I N T U I T I O N

From every cell, we can move only to down or diagonal down-right.

At every position, choose the minimum path among both possible moves.

DP state:  dp[i][j] = minimum path sum starting from (i,j).

Last row becomes base case because no further moves are possible.

Since current row depends on next row, solve from bottom to top.

Final answer will be present at dp[0][0].

###### memization code gives TLE
###### C O D E(tabulation code)

```cpp
int minimumTotal(vector<vector<int>>&triangle){
            int n = triangle.size();

            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];

            for(int i=n-2;i>=0;i--){
                for(int j=0;j<=i;j++){

                    int down = triangle[i][j] + dp[i+1][j];
                    int diagonal = triangle[i][j] + dp[i+1][j+1];
                    dp[i][j] = min(down,diagonal);
                }

            }
            return dp[0][0];
        }

```

###### C O D E(space optimization)

```cpp
 int minimumTotal(vector<vector<int>>&triangles){
        int n = triangles.size();

        vector<int>front(n+1,0);

        for(int j=0;j<n;j++) front[j] = triangles[n-1][j];

        for(int i=n-2;i>=0;i--){
             vector<int>curr(i+1,0);

            for(int j=0;j<=i;j++){

                int down = triangles[i][j]+front[j];
                int diag = triangles[i][j]+front[j+1];
                curr[j] = min(down,diag);
            }
            front = curr;
        }
        return front[0];
       }

```
