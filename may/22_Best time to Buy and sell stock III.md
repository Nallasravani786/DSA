#### I M A G E
<img width="2832" height="1256" alt="image" src="https://github.com/user-attachments/assets/4a7f86af-e12e-4d0e-980e-ba1459990b04" />

#### I N T U I T I O N
We maintain 3 states: current day, buy/sell state, and remaining transactions.

At every day, either perform action or skip the day.

If buy is allowed, either buy stock now or move to next day.

If holding stock, either sell it or skip selling.

Transaction count decreases only when a sell operation happens.

Same states repeat many times, so use 3D DP memoization.

dp[ind][buy][k] stores maximum profit from index ind with current state and k transactions left.


###### m e mo i z a t i o n _ c o d e
```cpp
int f(int ind,int buy,int k ,vector<int>&prices,vector<vector<vector<int>>>&dp){
      int n = prices.size();
       
       if(k==0 || ind == n) return 0;

       if(dp[ind][buy][k]!=-1) return dp[ind][buy][k];

       int profit = 0;

       if(buy == 1) profit = max(-prices[ind]+f(ind+1,0,k,prices,dp),f(ind+1,1,k,prices,dp));

       else profit = max(prices[ind]+f(ind+1,1,k-1,prices,dp),f(ind+1,0,k,prices,dp));

       return dp[ind][buy][k] = profit;

  }
  
    int maxProfit(vector<int>& prices) {
       int n = prices.size();

       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

       return f(0,1,2,prices,dp); 
    }

```
###### t a b u l a t i o n _ c o d e

```cpp
 int maxProfit(vector<int>&prices){
        int n = prices.size();

        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for(int ind = n-1;ind>=0;ind--){
            
            for(int buy = 0;buy<2;buy++){

                for(int k=1;k<3;k++){

                    int profit = 0;

                   if(buy == 1) profit = max(-prices[ind]+dp[ind+1][0][k],dp[ind+1][1][k]);

                   else profit = max(prices[ind]+ dp[ind+1][1][k-1],dp[ind+1][0][k]);

                   dp[ind][buy][k] = profit;
                }

            }
        }

        return dp[0][1][2];
     }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 int maxProfit(vector<int>&prices){

        int n = prices.size();

        vector<vector<int>>front(2,vector<int>(3,0)),curr(2,vector<int>(3,0));

        for(int ind= n-1;ind>=0;ind--){
            
            for(int buy = 0;buy<2;buy++){

                for(int k=1;k<3;k++){

                    int profit = 0;
                    if(buy == 1) profit = max(-prices[ind]+front[0][k],front[1][k]);

                    else profit = max(prices[ind] + front[1][k-1], front[0][k]);

                    curr[buy][k] = profit;
                }
            }
            front = curr;
        }
        return front[1][2];
    }

```
