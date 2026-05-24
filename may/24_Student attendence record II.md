#### I M A G E

<img width="2861" height="1331" alt="image" src="https://github.com/user-attachments/assets/0d3b9dcb-4d58-49bc-9635-deff06e69b41" />

#### I N T U I T I O N

Build attendance record day by day.

At each day, try placing P, A, or L.

Track absent count because total A must be less than 2.

Track consecutive late count because LLL is not allowed.

P resets late count to 0.

A increases absent count and resets late count.

L increases consecutive late count.

Same (index, absent, late) states repeat, so use 3D DP memoization.

###### m e m o i z a t i o n _ c o d e

```cpp
int MOD = 1e9 + 7;
   int f(int ind,int absent,int late,int n , vector<vector<vector<int>>>&dp){

      if(absent >= 2) return 0;
      if(late >=3) return 0;

      if(ind == n) return 1;

      if(dp[ind][absent][late]!=-1) return dp[ind][absent][late];

      long long p = f(ind+1,absent,0,n,dp);
      long long a = f(ind+1,absent+1,0,n,dp);
      long long l = f(ind+1,absent,late+1,n,dp);

      return dp[ind][absent][late] = (p + a + l)%MOD;
   }

    int checkRecord(int n) {
    
     vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

     return f(0,0,0,n,dp);
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int MOD = 1e9 + 7;

   int checkRecord(int n){
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

    dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = 1;
    dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 1;

    for(int ind= n-1;ind>=0;ind--){

        for(int absent = 0;absent<2;absent++){

            for(int late = 0;late<3;late++){

                long long p = dp[ind+1][absent][0];
                long long a = 0;
             if(absent < 1)  a = dp[ind+1][absent+1][0];
               long long l = 0;
              if(late < 2)  l = dp[ind+1][absent][late+1];

                dp[ind][absent][late] = (p + a + l)%MOD;
            }
        }
    }
    return dp[0][0][0];
   }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int MOD = 1e9+7;
   int  checkRecord(int n){
        vector<vector<int>>front(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        front[0][0] = front[0][1] = front[0][2] = 1;
        front[1][0] = front[1][1] = front[1][2] = 1;

   for(int ind = n-1;ind>=0;ind--){

     for(int absent = 0;absent <2;absent++){

         for(int late =0;late<3;late++){

            long long p = front[absent][0];
            long long a = 0;

            if(absent < 1) a = front[absent+1][0];

            long long l = 0;

            if(late < 2) l = front[absent][late+1];

            curr[absent][late] = (p + a + l)%MOD;
        }
    }
     front = curr;
  }

     return front[0][0];
   }

```
