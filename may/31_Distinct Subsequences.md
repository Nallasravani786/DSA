#### I M A G E
<img width="2844" height="1376" alt="image" src="https://github.com/user-attachments/assets/64246e5b-c651-40e5-8d22-d2194fb1e163" />

#### I N T U I T I O N
We need to find how many ways t can be formed from s using subsequences.

At each character of s, we make a choice: take it or skip it.

If s[i] == t[j], we have 2 options:
→ take it to match t[j]
→ skip it and look for another match later.

If s[i] != t[j], we cannot use it, so we only skip it.

Core idea: Try all take/skip choices and count the total valid ways to build t from s.


###### m e m o i z a t i o n _ c o d e

```cpp
 int f(int i,int j,string &s,string &t,vector<vector<int>>&dp){

    if(j<0) return 1;
    if(i<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == t[j]) dp[i][j] = f(i-1,j-1,s,t,dp) + f(i-1,j,s,t,dp);
    else dp[i][j] = f(i-1,j,s,t,dp);
    return dp[i][j];
   }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(n-1,m-1,s,t,dp);
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
 int numDistinct(string s,string t){
    const int MOD = 1e9 + 7;
    int n = s.size();
    int m = t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int j=0;j<=m;j++) dp[0][j] = 0;
    for(int i=0;i<=n;i++) dp[i][0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s[i-1]==t[j-1]) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][m];
 }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e
```cpp
 int numDistinct(string s,string t){
    const int MOD = 1e9 + 7;
    int n = s.size();
    int m = t.size();

    vector<int>prev(m+1,0),curr(m+1,0);
    prev[0] = 1,curr[0] = 1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s[i-1] == t[j-1]) curr[j] = (prev[j-1] + prev[j])%MOD;
            else curr[j] = prev[j];
       }
       prev = curr;
    }
    return prev[m];
   }
```
###### only one array tho space optimization code : curr place lo prev pedithe chaalu
