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

###### C O D E ( t a b u l a t i o n )

```cpp
int change(int amount,vector<int>&coins){
            int n = coins.size();
            vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));

           for(int amt =0; amt<=amount; amt++){
            if(amt%coins[0] == 0) dp[0][amt] =1;
            else dp[0][amt] = 0;
           }

           for(int ind =1;ind<n;ind++){

            for(int am=0;am<=amount;am++){
               unsigned long long take = 0;
                if(coins[ind] <= am) take = dp[ind][am-coins[ind]];
               unsigned long long nottake = dp[ind-1][am];
               dp[ind][am] = take + nottake;

            }
           }
           return (int)dp[n-1][amount];
        }


```
