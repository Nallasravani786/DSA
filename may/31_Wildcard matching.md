#### I M A G E
<img width="2804" height="1319" alt="Screenshot 2026-05-31 135434" src="https://github.com/user-attachments/assets/a0d22ee7-17b8-4fca-a29f-d45df8757d51" />

#### I N T U I T I O N
We compare the string and pattern from the end.

If characters match or pattern has '?', move both pointers.

If pattern has '*', we have 2 choices:
'*' matches empty → move pattern pointer.
'*' matches one/more characters → move string pointer.

Since the same subproblems repeat, use DP/memoization on (i,j) to avoid recomputation

###### m e m o i z a t i o n _ c o d e

```cpp
 bool f(int i,int j,string &s,string &p, vector<vector<int>>&dp){
    if(i<0 && j<0) return true;
    if(i<0 && j>=0) return false;
    if(j<0 && i>=0) {
        for(int k=0;k<=i;k++) 
         {
            if(p[k] != '*') return false;
         }
             return true;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(p[i] == s[j] || p[i] == '?') return dp[i][j] = f(i-1,j-1,s,p,dp);

    if(p[i] == '*') return dp[i][j] = f(i,j-1,s,p,dp) || f(i-1,j,s,p,dp);

    else return dp[i][j] = false;
 }


    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
```

###### t a b u l a t i o n _ c o d e
```cpp
  bool isMatch(string s , string p){
      int n = p.size();
      int m = s.size();

      vector<vector<int>>dp(n+1,vector<int>(m+1,0));

      dp[0][0] = true;
      for(int j=1;j<=m;j++) dp[0][j] = false;
      for(int i=1;i<=n;i++) {
                 int flg = true;
            for(int k =0;k<i;k++){
                if(p[k]!='*') { flg = false; 
                break;}
            }
            dp[i][0] = flg;
      }

      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(p[i-1] == s[j-1] || p[i-1] == '?') dp[i][j] = dp[i-1][j-1];
            else if(p[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else dp[i][j] = false;
        }
      }
        return dp[n][m];
  }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 bool isMatch(string s, string p){
    int n = p.size();
    int m = s.size();

    vector<int>prev(m+1,0),curr(m+1,0);
    prev[0] = curr[0] = true;
    for(int j=1;j<=m;j++) prev[j] = false;
   

    for(int i=1;i<=n;i++){

         int flg = true;
        for(int k=0;k<i;k++){
            if(p[k]!='*') {
                flg = false;
                break;
            } 
        }
        curr[0] = flg;

        for(int j=1;j<=m;j++){

            if(p[i-1] == s[j-1] || p[i-1] == '?') curr[j] = prev[j-1];
            else if(p[i-1] == '*') curr[j] = curr[j-1] || prev[j];
            else curr[j] = false;
        }
        prev = curr;
    }
   return  prev[m];
 }


```
