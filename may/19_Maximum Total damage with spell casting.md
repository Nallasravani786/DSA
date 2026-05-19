#### I M A G E 

<img width="2848" height="1358" alt="image" src="https://github.com/user-attachments/assets/2ce7d2c7-b289-4cd4-a151-7a44af6c5b12" />

#### I N T U I T I O N

Sort the array so same power values come together.

At every index, we have 2 choices: Take the current power group
                                   Skip the current power group
If we take power x, then we cannot take: x-2 , x-1 ,x+1 , x+2

So after taking all x values, skip all values in range: x+1 x+2

Since duplicates can all be taken together, first calculate total sum of same values.

Use DP memoization because same states are computed many times.

#### C O D E
```cpp
long long f(int ind,vector<int>&power,vector<long long>&dp){
        int n = power.size();

        if(ind>=n) return 0;

        if(dp[ind] !=-1) return dp[ind];

        int  j = ind;
        long long sum =0;

        while( j <n && power[j] == power[ind]) {
            sum+=power[ind];
            j++;
        }

        int next = j;

        while(next<n && (power[next]== power[ind]+1  || power[next]== power[ind]+2)){
            next++;
        }

        long long take = sum + f(next,power,dp);
        long long nottake = f(j,power,dp);

        return dp[ind] = max(take,nottake);
    }


    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        vector<long long>dp(n,-1);
        sort(power.begin(),power.end());
         
        return f(0,power,dp);
    }

```
