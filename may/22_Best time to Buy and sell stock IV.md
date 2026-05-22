#### I M A G E
<img width="2830" height="1326" alt="image" src="https://github.com/user-attachments/assets/7e9f4410-7ee4-4183-a285-445a1d00b558" />

#### I N T U I T I O N

Instead of buy/sell state, we track total transaction operations using trans.

Even transaction number means buy operation and odd transaction number means sell operation.

At every index, either perform current operation or skip the day.

After performing buy/sell, move to next transaction state using trans + 1.

We stop when all 2*k operations are completed or array ends.

Same states repeat many times, so use DP memoization.

dp[ind][trans] stores maximum profit from index ind with current transaction state.

###### m e m o i z a t i o n _ c o d e

```cpp
int f(int ind,int trans,int k,vector<int>&prices,vector<vector<int>>&dp){
       int n = prices.size();

      if(trans == 2*k || ind == n) return 0;

      if(dp[ind][trans]!=-1) return dp[ind][trans];

      int profit =0;

      if(trans % 2 == 0) profit = max(-prices[ind]+f(ind+1,trans+1,k,prices,dp),f(ind+1,trans,k,prices,dp));
      else profit = max(prices[ind]+f(ind+1,trans+1,k,prices,dp),f(ind+1,trans,k,prices,dp));

      return dp[ind][trans] = profit;
  }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>dp(n,vector<int>(2*k,-1));

        return f(0,0,k,prices,dp);
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int maxProfit(int k,vector<int>&prices){
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));

    for(int ind = n-1;ind>=0;ind--){

        for(int trans = 0;trans<2*k;trans++){

            int profit =0;
            if(trans%2 == 0) profit = max(-prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);
            else profit = max(prices[ind]+dp[ind+1][trans+1],dp[ind+1][trans]);

            dp[ind][trans] = profit;
          }
      }
     return dp[0][0];
  }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 int maxProfit(int k, vector<int>&prices){
     int n = prices.size();

     vector<int>front(2*k+1,0),curr(2*k+1,0);

     for(int ind= n-1;ind>=0;ind--){
        for(int trans = 0; trans<2*k;trans++){

            int profit =0;
            if(trans%2 == 0) profit = max(-prices[ind]+front[trans+1],front[trans]);
            else profit = max(prices[ind]+front[trans+1],front[trans]);
            curr[trans] = profit;
        }
        front = curr;
     }
     return front[0];
   }


```
