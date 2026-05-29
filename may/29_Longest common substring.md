#### I M A G E
<img width="2855" height="1362" alt="image" src="https://github.com/user-attachments/assets/071f621f-df39-4de4-8e6e-040592194bf3" />

#### I N T U I T I O N 
We need common substring, so characters must be continuous.

dp[i][j] stores length of common substring ending at (i,j).

If characters match → extend previous substring: 1 + dp[i-1][j-1]

If characters mismatch → continuity breaks, so set 0.

Track maximum value in DP table as the answer.

###### m e m o i z a t i o n _ c o d e

```cpp
 int f(int i,int j,string &s,string &t,vector<vector<int>>&dp,int &maxlen){
     if(i<0 || j<0) return 0;
     
     if(dp[i][j]!=-1) return dp[i][j];
     
     if(s[i]==t[j])  {
     dp[i][j] = 1+ f(i-1,j-1,s,t,dp,maxlen);
     maxlen = max(maxlen,dp[i][j]);
     }
     else  dp[i][j] = 0;
     
     return dp[i][j];
     
 } 
    int longCommSubstr(string& s1, string& s2) {
        
        int n = s1.size();
        int m = s2.size();
        int maxlen = 0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                f(i,j,s1,s2,dp,maxlen);
            }
        }
        
        return maxlen;
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int longCommSubstr(string &s1,string &s2){
         int n = s1.size();
         int m = s2.size();
         int maxlen = 0;
         
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         
         
         for(int i=1;i<=n;i++){
             
             for(int j=1;j<=m;j++){
                 
                 if(s1[i-1] == s2[j-1]) {
                     
                     dp[i][j] = 1+ dp[i-1][j-1];
                     maxlen = max(maxlen,dp[i][j]);
                 }
                 else dp[i][j] = 0;
             }
         }
         
         return maxlen;    
    }
```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 int longCommSubstr(string &s1,string &s2){
        
        int n = s1.size();
        int m = s2.size();
        int maxlen = 0;
        
        vector<int>prev(m+1,0),curr(m+1,0);
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                
                if(s1[i-1] == s2[j-1]) {
                    curr[j] = 1+ prev[j-1];
                    maxlen = max(maxlen,curr[j]);
                }
                else curr[j] = 0;
            }
            prev = curr;
        }
        return maxlen;
    }

```
