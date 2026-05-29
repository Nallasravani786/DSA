#### I M A G E
<img width="2846" height="1336" alt="image" src="https://github.com/user-attachments/assets/aa41166a-0c9d-458a-9609-d9b9d5c108a5" />

#### I N T U I T I O N
We can only delete characters, not rearrange them.

So keep the Longest Common Subsequence (LCS) between both strings unchanged.

All other characters must be deleted. 
Deletions from word1 = n − LCS
Deletions from word2 = m − LCS

Therefore, Minimum deletions = (n − LCS) + (m − LCS) = n + m − 2*LCS.

###### m e m o i z a t i o n _ c o d e
```cpp
 int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == t[j]) dp[i][j] = 1+ f(i-1,j-1,s,t,dp);

    else dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));

    return dp[i][j];
  }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return n+m - 2*f(n-1,m-1,word1,word2,dp);
    }

```
###### t a b u l a t i o n _ c o d e

```cpp
int minDistance(string word1 , string word2){
     int n = word1.size();
     int m = word2.size();

     vector<vector<int>>dp(n+1,vector<int>(m+1,0));

     for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(word1[i-1] == word2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
     }
     return n+m-2*dp[n][m];
 }
```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 int minDistance(string word1, string word2){
     int n = word1.size();
     int m = word2.size();

     vector<int>prev(m+1,0),curr(m+1,0);

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(word1[i-1] == word2[j-1]) curr[j] = 1+ prev[j-1];
            else curr[j] = max(prev[j],curr[j-1]);
        }
        prev = curr;
     }
     return n+m-2*prev[m];
  }

```
