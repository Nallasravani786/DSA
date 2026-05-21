#### I M A G E

<img width="2854" height="1441" alt="image" src="https://github.com/user-attachments/assets/028649c6-ae96-45fa-9b7a-97138bded06e" />

#### I N T U I T I O N
First check whether the total sum is even or odd because equal partition is possible only for even sums.

Convert the problem into finding a subset whose sum is equal to totalSum / 2.

For every element, we have two choices: either take it or skip it.

Use DP to avoid recalculating the same (index, target) states again and again.

If we can successfully form the target sum, then the remaining elements automatically form the second equal subset.

###### m e m o i z a t i o n _ c o d e

```cpp
bool f(int ind,vector<vector<int>>&dp,vector<int>&nums,int target){
    int n = nums.size();

    if(target == 0) return true;
    if(ind == 0) return target == nums[ind];
    if(dp[ind][target]!=-1) return dp[ind][target];

    bool pick = false;

    if(nums[ind] <= target) pick = f(ind-1,dp,nums,target-nums[ind]);

    bool notpick  = f(ind-1,dp,nums,target);

    return dp[ind][target] = pick || notpick;
    
  }

    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int totsum = 0;

        for(int c:nums) totsum += c;

        if(totsum%2 !=0) return false;

        int target = totsum/2;

        vector<vector<int>>dp(n,vector<int>(target+1,-1));

        return f(n-1,dp,nums,target);
        
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
 bool canPartition(vector<int>&nums){
        int n = nums.size();
        int totsum = 0;

        for(int c:nums) totsum +=c;

        if(totsum%2 !=0) return false;

        int target = totsum/2;

        vector<vector<bool>>dp(n,vector<bool>(target+1,0));

        for(int i=0;i<n;i++) dp[i][0] = true;

        if(nums[0] <= target) dp[0][nums[0]] = true;



        for(int ind =1;ind<n;ind++){

            for(int tar=1;tar<=target;tar++){

               bool pick = false;

               if(nums[ind]<=tar) pick = dp[ind-1][tar-nums[ind]];

               bool notpick = dp[ind-1][tar];

               dp[ind][tar] = pick || notpick;

            }

        }
        return dp[n-1][target];
    }

```
###### s p a c e_o p t i m i z a t i o n _ c o d e

```cpp
bool canPartition(vector<int>&nums){
        int n = nums.size();
        int totsum = 0;
        for(int c: nums) totsum += c;

         if(totsum%2 !=0) return false;

         int target = totsum/2;

         vector<bool>prev(target+1,0),curr(target+1,0);

         prev[0] = true;

         if(nums[0]<=target) prev[nums[0]] = true;

         for(int ind=1;ind<n;ind++){
                
               curr[0] = true;

            for(int tar =1;tar<=target;tar++){

                bool pick = false;
                if(nums[ind] <= tar) pick = prev[tar-nums[ind]];
                bool notpick = prev[tar];

                curr[tar] = pick || notpick;
            }
            prev = curr;
         }
         return prev[target];
    }



```

