#### I M A G E

<img width="2837" height="1465" alt="image" src="https://github.com/user-attachments/assets/2d159329-08ab-4417-b065-092e35eca6a2" />

#### I N T U I T I O N

Sort the array so all duplicate values come together.

At every index, we have 2 choices:

Take the current number group or Skip the current number group

If we take a number x, then we cannot take: x-1 , x+1

So after taking all x values, skip all (x+1) values and move to the next valid number.

Treat duplicate numbers as one group because taking all duplicates always gives maximum points.

Use DP memoization because the same indices are solved multiple times.


###### C O D E

```cpp
int f(int ind,vector<int>&nums,vector<int>&dp){
        int n = nums.size();

        if(ind >=n) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int j = ind;
        int sum =0;

        while(j<n && nums[j] == nums[ind]){
            sum += nums[j];
            j++;
        }

        int next = j;

        while(next < n && nums[next] == nums[ind]+1){
            next++;
        }
        int take = sum + f(next,nums,dp);
        int nottake = f(j,nums,dp);

        return dp[ind] = max(take,nottake);
    }


    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();

        vector<int>dp(n,-1);

        sort(nums.begin(),nums.end());

        return f(0,nums,dp);
    }

```
