####   I M A G E

<img width="2867" height="1422" alt="image" src="https://github.com/user-attachments/assets/98a20579-bea7-4923-9c25-7895083a153c" />

#### I N T U I T I O N

We maintain 2 states: can buy or can sell.

At every day, either perform action or skip the day.

Buying decreases profit, selling increases profit.

Same states repeat again, so use DP memoization.

dp[ind][buy] stores maximum profit from index ind with current state.

Start from day 0 with buying allowed.

###### m e m o i z a t i o n _ c o d e

```cpp
int f(int buy,int ind,vector<int>&prices,vector<vector<int>>&dp){
        int n = prices.size();

        if(ind ==n) return 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];

        int profit = 0;

        if(buy == 1) profit = max(-prices[ind] + f(0,ind+1,prices,dp),f(1,ind+1,prices,dp));

        else profit =  max(prices[ind]+f(1,ind+1,prices,dp),f(0,ind+1,prices,dp));

        return dp[ind][buy] = profit;
    }


    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        return f(1,0,prices,dp);
    }


```
###### t a b u l a t i o n _ c o d e

```cpp
int maxProfit(vector<int>&prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;

        for(int ind= n-1;ind>=0;ind--){

            for(int buy =0;buy<2;buy++){

                int profit = 0;
                if(buy == 1) profit = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                
                else profit = max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int maxProfit(vector<int>&prices){
        int n = prices.size();
        vector<int>front(2,0),curr(2,0);
        front[0] = front[1] = 0;

        for(int ind=n-1;ind>=0;ind--){

            for(int buy = 0;buy<2;buy++){
                int profit = 0;
                if(buy == 1) profit = max(-prices[ind]+front[0],front[1]);

                else profit = max(prices[ind]+front[1],front[0]);

                curr[buy] = profit;
            }
            front = curr;
        }
        return front[1];
     }

```
