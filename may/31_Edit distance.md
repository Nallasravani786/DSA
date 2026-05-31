#### I M A G E
<img width="2865" height="1381" alt="image" src="https://github.com/user-attachments/assets/b0c75a2e-3c4d-43b3-b2e3-56e64439eace" />

#### I N T U I T I O N
We are trying to convert string s into string t with minimum operations.

At each step, we compare characters from the end:

If they match, we move both pointers back.
If they don’t match, we try all 3 possibilities: delete a character from s, insert a character from t, or replace a character in s.

Each operation reduces the problem size, and we pick the one that gives the minimum total cost. This is why the problem naturally fits a DP on indices (i, j) representing prefixes of both strings.


###### m e m o i z a t i o n _ c o d e
```cpp
int f(int i, int j,string &s,string &t,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == t[j]) dp[i][j] = f(i-1,j-1,s,t,dp);

    else dp[i][j] = 1+min(min(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp)),f(i-1,j-1,s,t,dp));

    return dp[i][j];
  }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(n-1,m-1,word1,word2,dp);
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int minDistance(string word1 , string word2){
    int n = word1.size();
    int m = word2.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=0;i<=n;i++) dp[i][0] = i;
    for(int j=0;j<=m;j++) dp[0][j] = j;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];

            else dp[i][j] = 1+ min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
        }
    }
    return dp[n][m];
  }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e
```cpp
int minDistance(string word1 , string word2){
       
       int n = word1.size();
       int m = word2.size();

       vector<int>prev(m+1,0),curr(m+1,0);

       for(int j=0;j<=m;j++) prev[j] = j;

       for(int i=1;i<=n;i++){
               curr[0] = i;
        for(int j=1;j<=m;j++){

            if(word1[i-1] == word2[j-1]) curr[j] = prev[j-1];
            else curr[j] = 1+ min({prev[j],prev[j-1],curr[j-1]});

       }
       prev = curr;
         }
      return prev[m];
   }

```
