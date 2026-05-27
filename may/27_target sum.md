#### I M A G E
<img width="2790" height="1343" alt="image" src="https://github.com/user-attachments/assets/a70baba4-a7f9-4bd8-aee3-a44ee32fa051" />


#### I N T U I T I O N
Each element has 2 choices: + or -.

Divide array into positive subset S1 and negative subset S2.

Form equation: S1 - S2 = target.

Total sum gives: S1 + S2 = totsum.

Solving both ⇒ S1 = (totsum + target)/2.

Now problem becomes: count subsets with sum = (totsum + target)/2.

Use Pick / Not Pick DP to count valid subsets.

Handle 0 carefully since +0 and -0 give 2 ways.


###### m e m o i z a t i o n _ c o d e
```cpp
 int f(int ind,int tar,vector<int>&nums,vector<vector<int>>&dp){

    if(ind ==0){
        if(tar == 0 && nums[ind] == 0) return 2;
        else if(tar == 0 || nums[ind] == tar) return 1;
        else return 0;
    }
   
   if(dp[ind][tar]!=-1) return dp[ind][tar];

   int pick = 0;
   if(nums[ind]<=tar) pick = f(ind-1,tar-nums[ind],nums,dp);
   int notpick = f(ind-1,tar,nums,dp);
   return dp[ind][tar] = pick + notpick;

 }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for(int x: nums) totsum += x;

        int tar = (totsum + target)/2;
        if((totsum + target)% 2 !=0) return 0;
        if(totsum + target <0) return 0;

        vector<vector<int>>dp(n,vector<int>(tar+1,-1));

        return f(n-1,tar,nums,dp);
        
    }

```

###### tabulation code and space optimization code same as ques:
