## M E M O I Z A T I O N

```cpp
int memo(int ind,vector<int>&arr,vector<int>&dp){
    if(ind ==0) return arr[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];

    int pick = arr[ind]+memo(ind-2,arr,dp);
    int notpick = 0+ memo(ind-1,arr,dp);
    return dp[ind] = max(pick,notpick);
}




    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return memo(n-1,nums,dp);
    }
```
