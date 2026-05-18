#### I M A G E
<img width="2841" height="1320" alt="image" src="https://github.com/user-attachments/assets/ea35a9a7-2a59-4811-8fdf-1ed3651e7bad" />

#### I N T U I T I O N

At every coin, we have two choices: pick the coin ,do not pick the coin.

If we pick: amount decreases

we stay at same index because coins can be used unlimited times.

If we do not pick:  move to previous coin.

We try both choices and take the minimum number of coins.

Base case:  when only one coin remains,

check whether remaining amount can be formed exactly.

Same (index, amount) states repeat many times,

so use DP/memoization

######   m e m o i z a t i o n  _ c o d e

```cpp
int f(int ind,vector<int>&coins,int amount , vector<vector<int>>&dp){

        if(ind ==0 ) {
            if(amount % coins[0] == 0) return (int)amount/coins[ind];
            else return 1e9;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];

       int pick =1e9;
       if(coins[ind] <= amount)  pick = 1 + f(ind,coins,amount-coins[ind],dp);

       int notpick = 0+ f(ind-1,coins,amount,dp);

       return dp[ind][amount] = min(pick,notpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
       vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
        int ans = f(n-1,coins,amount,dp);

        if(ans>=1e9) return -1;
        return ans;
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int coinChange(vector<int>&coins , int amount){
        int n = coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,0));

        for(int amt = 0 ; amt<= amount; amt++){
            if(amt % coins[0] == 0)  dp[0][amt] = (int) amt/coins[0];
            else dp[0][amt] = 1e9;
        }
        for(int ind =1;ind<n;ind++){
            
            for(int am= 0; am<=amount;am++){
                int pick = 1e9;
                if(coins[ind] <= am) pick = 1+ dp[ind][am-coins[ind]];
                int notpick = dp[ind-1][am];
                dp[ind][am] = min(pick,notpick);
            }
        }
            int ans = dp[n-1][amount];

            if(ans >= 1e9) return -1;
            return ans;
    }

```

###### s p a c e_o p t i m i z a t i o n _ c o d e

```cpp
 int coinChange(vector<int>&coins , int amount){

            int n = coins.size();
            vector<int>prev(amount+1,0);

            for(int amt =0;amt<=amount;amt++){
                if(amt % coins[0] ==0) prev[amt] = (int) amt/coins[0] ;
                else prev[amt] = 1e9;
            }

            for(int ind=1;ind<n;ind++){
                vector<int>curr(amount+1,0);
                
                for(int am=0;am<=amount;am++){
                    int pick = 1e9;
                    if(coins[ind]<=am) pick = 1+ curr[am-coins[ind]];
                    int notpick = prev[am];
                    curr[am] = min(pick,notpick);
                }
            }
             int ans = prev[amount];
             if(ans >= 1e9) return -1;
             return ans;
        }

```
