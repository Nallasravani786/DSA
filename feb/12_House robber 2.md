#### T A B U L A T I O N
```cpp
int tabulation(vector<int>&arr){
    int n = arr.size();
    vector<int>dp(n,0);
    dp[0] = arr[0];
    for(int ind =1;ind<n;ind++){
        int pick = arr[ind];
        if(ind>1) pick+=dp[ind-2];
        int notpick = dp[ind-1];
        dp[ind] = max(pick,notpick);
    }
    return dp[n-1];
   }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr1;
        vector<int>arr2;
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) arr1.push_back(nums[i]);
            if(i!=n-1) arr2.push_back(nums[i]);
        }
        int ans1 = tabulation(arr1);
        int ans2 = tabulation(arr2);
        return max(ans1,ans2);
    }
```
