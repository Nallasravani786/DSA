#### I M A G E
<img width="2823" height="1289" alt="image" src="https://github.com/user-attachments/assets/2fa857c3-fa0c-4ecd-adb2-c1f2ca0b8a2a" />

#### I N T U I T I O N

We maintain 2 states: can buy or currently holding stock (can sell).

At every day, either perform action or skip the current day.

If buying, either buy now or move to next day without buying.

If selling, either sell now or skip selling.

After selling, one cooldown day is forced, so move to ind + 2.

Same states repeat many times, so use DP memoization.

dp[ind][buy] stores maximum profit from day ind with current buy/sell state.


###### m e m o i z a t i o n _ c o d e
```cpp
int f(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp) {

    int n = prices.size();

    if(ind >= n) return 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];

    int profit = 0;
    if(buy == 1) profit = max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,buy,prices,dp));
    else profit = max(prices[ind]+f(ind+2,1,prices,dp),f(ind+1,buy,prices,dp));

    return dp[ind][buy] = profit;
  }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);

    }

```

###### t a b u l a t i o n _ c o d e
```cpp
int maxProfit(vector<int>&prices){
    int n = prices.size();

    vector<vector<int>>dp(n+2,vector<int>(2,0));

    for(int ind=n-1;ind>=0;ind--){

        for(int buy =0;buy<=1;buy++){

            int profit =0;

            if(buy == 1) profit = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            else profit = max(prices[ind]+dp[ind+2][1],dp[ind+1][0]);

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

    vector<int>front1(2,0),front2(2,0),curr(2,0);

    for(int ind=n-1;ind>=0;ind--){

        for(int buy = 0;buy<=1;buy++){
            int profit =0;

            if(buy == 1) profit = max(-prices[ind]+front1[0],front1[1]);
            else profit = max(prices[ind]+front2[1],front1[0]);

            curr[buy]  = profit;
        }
        front2 = front1;
        front1 = curr;

    }
    return  front1[1];
  }

```
