#### I M A G E
<img width="2842" height="1366" alt="image" src="https://github.com/user-attachments/assets/81d01495-0143-41e7-bce9-243f8b67cd86" />

#### I N T U I T I O N

We need minimum insertions to make the string a palindrome.

Instead of thinking about insertions, find the Longest Palindromic Subsequence (LPS) already present.

Characters in LPS can stay unchanged.

Remaining characters must be inserted to make the string palindrome.

So, Minimum Insertions = String Length − LPS

To find LPS, use the trick: LPS = LCS(string, reversed string).

###### m e m o i z a t i o n _ c o d e
```cpp
int f(int i,int j,string &s, string &t,vector<vector<int>>&dp){

    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == t[j]) dp[i][j] = 1+f(i-1,j-1,s,t,dp);
    else dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    return dp[i][j];
  }

    int minInsertions(string s) {
       string t = s;
       reverse(t.begin(),t.end());
       int n = s.size();
       int m = t.size();

       vector<vector<int>>dp(n,vector<int>(m,-1));

      int lps= f(n-1,m-1,s,t,dp);  // longest palindromic subsequence
      return n-lps;
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int minInsertions(string s){
    string t = s;
    reverse(t.begin(),t.end());
    int n = s.size();
    int m = t.size();

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];

            else dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
        }
    }
    return n-dp[n][m];
  }

```
###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int minInsertions(string s){

    string t = s;
    reverse(t.begin(),t.end());

    int n = t.size();
    vector<int>prev(n+1,0),curr(n+1,0);

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++){

                if(s[i-1]==t[j-1]) curr[j] = 1+prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);

            }
            prev = curr;
        }
        return n-prev[n];
  }

```
