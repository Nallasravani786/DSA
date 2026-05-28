#### I M A G E
<img width="2821" height="1393" alt="image" src="https://github.com/user-attachments/assets/5443bbbd-c326-43c8-91c1-ba0d81f2459e" />


#### I N T U I T I O N
Rod length n ni different piece lengths (1…n) ga cut cheyyachu.

For every piece length, you have 2 choices → take the cut or not take it.

If you take a piece, add its price and stay at same index (same cut length can be used again).

If you not take, move to smaller piece lengths.

dp[ind][len] = maximum profit obtainable for rod length len using cuts 0..ind.

Idea: try all possible cuts and choose the maximum revenue.

This is basically Unbounded Knapsack because one cut length can be used multiple times.

###### m e m o i z a t i o n _ c o d e

```cpp
int f(int ind,int len,vector<int>&prices,vector<vector<int>>&dp){
      if(ind == 0) {
          return len*prices[0];
      }
      
      if(dp[ind][len]!=-1) return dp[ind][len];
      
      int nottake = f(ind-1,len,prices,dp);
      
      int take = INT_MIN;
      int rod_len = ind+1;
      
      if(rod_len <= len) take = prices[ind] + f(ind,len-rod_len,prices,dp);
      
      return dp[ind][len] = max(take,nottake);
      
  }
    int cutRod(vector<int> &price) {
        int n = price.size();
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);  
    }

```

###### t a b u l a t i o n _ c o d e
```cpp
 int cutRod(vector<int>&price){
       int n = price.size();
       vector<vector<int>>dp(n,vector<int>(n+1,0));
       
       for(int l=0;l<=n;l++) dp[0][l] = l*price[0];
       
       for(int ind =1;ind<n;ind++){
           
           for(int len = 0;len<=n;len++){
             
             int take = INT_MIN;
             int rod_len = ind+1;
             
             if(rod_len <= len) take = price[ind]+dp[ind][len-rod_len];
             int nottake = dp[ind-1][len];
             dp[ind][len] = max(take,nottake);
           }
       }
       return dp[n-1][n];
   }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e
```cpp
int cutRod(vector<int>&price){
       int n = price.size();
       vector<int>prev(n+1,0),curr(n+1,0);
       
       for(int l=0;l<=n;l++) prev[l] = l*price[0];
       
       for(int ind =1;ind<n;ind++){
           
           for(int len = 0;len<=n;len++){
               
               int take = INT_MIN;
               int rod_len = ind+1;
               if(rod_len <= len) take = price[ind] + curr[len-rod_len];
               int nottake = prev[len];
               curr[len] = max(take,nottake);
               
           }
           prev = curr;
       }
       return prev[n];
   }

```
