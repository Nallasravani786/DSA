#### I M A G E
<img width="2836" height="1356" alt="image" src="https://github.com/user-attachments/assets/27d89059-f34c-40b7-8f64-01989af9c0e5" />

#### I N T U I T I O N
At each element, we have 2 choices: pick it or skip it.

We can pick the current element only if it is greater than the previously picked element.

If we pick it → add 1 to the LIS length and move forward.
If we skip it → simply move to the next element.

For every position, compute both pick and not pick choices and take the maximum.

Core Idea: Try including or excluding each element and find the maximum length of a strictly increasing subsequence.


###### m e m o i z a t i o n _ c o d e

```cpp
 int f(int ind,int prev_ind,vector<int>&nums,vector<vector<int>>&dp){
    
    int n = nums.size();
    if(ind == n) return 0;

    if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

    int notpick = 0 + f(ind+1,prev_ind,nums,dp);

    int pick  = 0;
    if(prev_ind == -1 || nums[ind] > nums[prev_ind]) pick = 1+f(ind+1,ind,nums,dp);

    return dp[ind][prev_ind+1] = max(pick,notpick);

  }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
int lengthOfLIS(vector<int>& nums){
     
     int n = nums.size();
     vector<vector<int>>dp(n+1,vector<int>(n+1,0));

     for(int ind = n-1;ind>=0;ind--){

        for(int prev_ind = ind-1;prev_ind>=-1;prev_ind--){

           int notpick = 0 + dp[ind+1][prev_ind+1];
            
            int pick = 0;
           if(prev_ind == -1 || nums[ind] > nums[prev_ind]) pick = 1+dp[ind+1][ind+1];

           dp[ind][prev_ind+1] = max(pick,notpick);
        }
     }
     return dp[0][0];
 }
```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int lengthOfLIS(vector<int>&nums){
      
      int n = nums.size();
      vector<int>after(n+1,0),curr(n+1,0);

      for(int ind = n-1;ind>=0;ind--){

        for(int prev_ind = ind-1;prev_ind >=-1;prev_ind--){

            int notpick = 0+after[prev_ind+1];

            int pick = 0;

            if(prev_ind == -1 || nums[ind] > nums[prev_ind]) pick = 1+after[ind+1];

            curr[prev_ind+1] = max(pick,notpick);
        }
        after = curr;
      }
      return after[0];
   }

```
