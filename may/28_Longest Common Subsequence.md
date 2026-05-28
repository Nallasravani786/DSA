#### I M A G E
<img width="2831" height="1357" alt="image" src="https://github.com/user-attachments/assets/93f18ffa-feb2-4f1c-a2ca-3f2f3ead5298" />

#### I N T U I T I O N

Think from the last characters of both strings.

If characters match, they must be part of LCS → take them and move both pointers left.

If characters do not match, one of them cannot belong to the common subsequence.

So try 2 choices:  ignore character from text1 , ignore character from text2

Take the maximum of these two choices. dp[id1][id2] stores the LCS length for prefixes text1[0..id1] and text2[0..id2].

Base case: if any string finishes, no common subsequence is possible → return 0.


###### m e m o i z a t i o n _ c o d e 

```cpp
 int f(int id1,int id2,string &text1, string &text2, vector<vector<int>>&dp){
         if(id1<0 || id2<0) return 0;

         if(dp[id1][id2]!=-1) return dp[id1][id2];

         int ans = 0;

         if(text1[id1] == text2[id2])  ans = 1+f(id1-1,id2-1,text1,text2,dp);

         else ans = max(f(id1-1,id2,text1,text2,dp),f(id1,id2-1,text1,text2,dp));

         return dp[id1][id2] = ans;
   }

    int longestCommonSubsequence(string text1, string text2) {
       int n = text1.size();
       int m = text2.size();

       vector<vector<int>>dp(n,vector<int>(m,-1));

       return f(n-1,m-1,text1,text2,dp);   
    }

```
###### t a b u l a t i o n _ c o d e

```cpp
 int longestCommonSubsequence(string text1 , string text2){
      
         int n = text1.size();
         int m = text2.size();

         vector<vector<int>>dp(n+1,vector<int>(m+1,0));

         for(int id1 = 1;id1<=n;id1++){
               
            for(int id2 = 1;id2<=m;id2++){
              
              if(text1[id1-1] == text2[id2-1])  dp[id1][id2] = 1 + dp[id1-1][id2-1];

              else  dp[id1][id2]  = max(dp[id1-1][id2],dp[id1][id2-1]);

            }   
         }

         return dp[n][m];
   }
```
###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int longestCommonSubsequence(string text1 , string text2){

      int n = text1.size();
      int m = text2.size();

      vector<int>prev(m+1,0),curr(m+1,0);

      for(int id1 = 1;id1 <=n;id1++){

        for(int id2 =1;id2<=m;id2++){

            if(text1[id1-1] == text2[id2-1]) curr[id2] = 1+ prev[id2-1];
            else curr[id2] = max(prev[id2],curr[id2-1]);

        }
          prev = curr;
    }
      return prev[m]; 
}

```
