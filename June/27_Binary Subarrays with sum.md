#### I M A G E
<img width="2834" height="1344" alt="image" src="https://github.com/user-attachments/assets/e60f6e45-73a4-4bb1-9a9f-23991e49d716" />

#### I N T U I T I O N
We need to count subarrays whose sum is exactly equal to goal.

Since the array contains only 0s and 1s, we can use the Sliding Window technique.

However, Sliding Window cannot directly count subarrays with an exact sum because there can be multiple valid starting positions due to zeros.

So, we use a simple trick : (Subarrays with sum = goal) = Subarrays with sum ≤ goal - Subarrays with sum ≤ goal - 1

###### C O D E
```cpp
int atmost(int goal,vector<int>&nums){
    if(goal <0) return 0;

    int l = 0;
    int sum =0;
    int cnt = 0;

    for(int r=0;r<nums.size();r++){
        sum+=nums[r];

        while(sum >goal){
            sum-=nums[l];
            l++;
        }
        cnt+=(r-l+1);
    }
    return cnt;
 }


    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(); 
        return atmost(goal,nums)-atmost(goal-1,nums);
    }
```
