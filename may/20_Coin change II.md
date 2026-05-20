#### I M A G E

<img width="2835" height="1377" alt="image" src="https://github.com/user-attachments/assets/416d553e-ceaf-4ef2-8f07-8f2ac4c242dd" />

#### I N T U I T I O N
At every coin, we have 2 choices: take the coin or do not take the coin.

If we take: reduce amount, stay at same index because coin can be used unlimited times.

If we do not take: move to previous coin.

We need total number of ways, so add both possibilities.

Base case: if only one coin remains, check whether amount can be formed completely.

DP is used because same (index, amount) states repeat many times.

###### C O D E ( m e m o i z a t i o n )

```cpp
int f(int ind,vector<vector<int>>&dp,vector<int>&coins,int amount){

     if(ind == 0) {
         if(amount % coins[0] == 0) return 1;
         else return 0;
     }

     if(dp[ind][amount]!=-1) return dp[ind][amount];
      
     int take = 0;
     if(coins[ind] <=amount) take = f(ind,dp,coins,amount-coins[ind]);
     int nottake = f(ind-1,dp,coins,amount);

     return dp[ind][amount] = take + nottake;
   }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));

        int ans = f(n-1,dp,coins,amount);
       
        return ans;
    }

```
