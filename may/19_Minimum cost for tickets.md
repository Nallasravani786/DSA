#### I M A G E

<img width="2830" height="1364" alt="image" src="https://github.com/user-attachments/assets/f2397251-f588-43bc-adcb-3127ce3c6f09" />

#### I N T U I T I O N 

At every travel day, we have 3 choices:

buy 1-day, 7-day, or 30-day pass.

After buying a pass,

skip all days already covered by that pass.

Recursively calculate minimum cost for remaining uncovered days.

Take minimum among all 3 choices.

Use DP because same travel-day index repeats many times.

###### C O D E

```cpp
 int f(int ind,vector<int>&days,vector<int>&costs,vector<int>&dp){
    int n = days.size();

    if(ind>=n) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int one = costs[0] + f(ind+1,days,costs,dp);

    int i = ind;

    while(i< n && days[i] < days[ind]+7){
        i++;
    }
    int seven = costs[1] + f(i,days,costs,dp);

    i = ind;
     
    while(i < n && days[i] < days[ind]+30){
        i++;
    }

    int thirty = costs[2] + f(i,days,costs,dp);

    return dp[ind] = min({one,seven,thirty}); 
 }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
     int n = days.size();

     vector<int>dp(n,-1);

     return f(0,days,costs,dp);
    }

```
