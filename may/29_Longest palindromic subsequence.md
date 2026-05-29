#### I M A G E
<img width="2847" height="1376" alt="image" src="https://github.com/user-attachments/assets/adf58d68-22e8-4a83-91b1-363bfe43cd30" />

#### I N T U I T I O N
Palindrome looks same from left and right.

If we reverse the string, palindrome characters will still appear in the same relative order.

So the problem becomes finding the Longest Common Subsequence between the original string and its reverse.

When characters match, include them in the answer and move both pointers.

When characters do not match, try skipping one character from either string and take the maximum result.

###### m e m o i z a t i o n _ c o d e
```cpp
int f(int i,int j,string &s, string &t,vector<vector<int>>&dp){

    if(i<0 || j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i] == t[j]) dp[i][j] = 1+ f(i-1,j-1,s,t,dp);

    else dp[i][j] = max(f(i,j-1,s,t,dp),f(i-1,j,s,t,dp));

    return dp[i][j]; 
  }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        int m = t.size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return f(n-1,m-1,s,t,dp);
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int longestPalindromeSubseq(string s){
    string t = s;
    reverse(t.begin(),t.end());
    int n = s.size();
    int m = t.size();
    

    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    // ee base cases okkati zero lenth unte atch inka em avvadhu so dp value 0
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int j=0;j<=m;j++) dp[0][j] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
   }

```
###### s p a c e _ o p t i m i z a t i o n _ c o d e
```cpp
 int longestPalindromeSubseq(string s){

     string t = s;
     reverse(t.begin(),t.end());

     int n = s.size();
     int m = t.size();

     vector<int>prev(m+1,0),curr(m+1,0);

     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){

            if(s[i-1]==t[j-1]) curr[j] = 1+ prev[j-1];
            else curr[j] = max(curr[j-1],prev[j]);

        }
        prev = curr;
     }
     return prev[m];
  }

```

