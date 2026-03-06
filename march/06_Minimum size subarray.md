<img width="2826" height="1291" alt="image" src="https://github.com/user-attachments/assets/0f233f06-211c-4c96-ab5b-d9f95e6c7c8b" />

### I N T U I T I O N 
Use a sliding window to maintain a subarray whose sum is at least target.

Expand the window by moving r and keep adding elements to sum.

When sum ≥ target, we already have a valid subarray, so try shrinking from the left (l) to make its length as small as possible.

Update min_len during shrinking and subtract nums[l] while moving l.

This way we always keep the smallest valid window, giving the minimal subarray length in O(n) time


###### C O D E
```cpp
 int minSubArrayLen(int target, vector<int>& nums) {
      
      int n = nums.size();
      int l=0,r=0;
      int min_len =INT_MAX;
      int sum =0;
    for(int r=0;r<n;r++){
        sum+=nums[r];

        while(sum >= target){
            min_len = min(min_len, r-l+1);
            sum -= nums[l];
            l++;
        }

    }
    return (min_len == INT_MAX) ? 0 : min_len;
    } 

```
