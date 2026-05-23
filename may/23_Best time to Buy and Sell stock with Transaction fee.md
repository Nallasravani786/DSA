#### I M A G E
<img width="2842" height="1457" alt="image" src="https://github.com/user-attachments/assets/a42c8875-3e1c-4269-a8b9-5eddfe132d74" />

#### I N T U I T I O N

We maintain 2 states: allowed to buy or holding stock to sell.

At every day, either perform action or skip the current day.

Buying decreases profit and selling increases profit.

Transaction fee is charged only during sell operation.

Since same (index, buy) states repeat, use DP memoization.

dp[ind][buy] stores maximum profit from day ind with current buy/sell state.

Start from day 0 with buying allowed.


###### m e m o i z a t i o n _ c o d e

```cpp
int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp,int fee){
    
      int n = prices.size();

      if(ind == n) return 0;

      if(dp[ind][buy]!=-1) return dp[ind][buy];

      int profit = 0;

      if(buy == 1) profit = max(-prices[ind]+f(ind+1,0,prices,dp,fee),f(ind+1,1,prices,dp,fee));

      else profit = max(prices[ind]-fee+f(ind+1,1,prices,dp,fee),f(ind+1,0,prices,dp,fee));

      return dp[ind][buy] = profit;
  }

    int maxProfit(vector<int>& prices, int fee) {
    
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
        
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
 int maxProfit(vector<int>&prices,int fee){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));

        dp[n][0] = dp[n][1] = 0;

        for(int ind = n-1;ind>=0;ind--){

            for(int buy = 0;buy<=1;buy++){

                int profit = 0;
                if(buy == 1) profit = max(-prices[ind]+dp[ind+1][0] , dp[ind+1][1]);
                else profit = max(prices[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
                dp[ind][buy] = profit;  
            }
        }
        return dp[0][1];
    }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int maxProfit(vector<int>&prices,int fee){
          int n = prices.size();
          vector<int>front(2,0),curr(2,0);

          front[0]=front[1] = 0;

          for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                int profit =0;
                if(buy == 1) profit = max(-prices[ind]+front[0],front[1]);
                else profit = max(prices[ind]-fee+front[1],front[0]);

                curr[buy] = profit;
            }
            front = curr;
          }
          return front[1];
          }
```
