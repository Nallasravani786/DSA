
<img width="2795" height="1236" alt="Screenshot 2026-03-05 172027" src="https://github.com/user-attachments/assets/d9fe7bf5-4cf1-443c-a921-c960a11b6683" />





### I N T U I T I O N
Use a sliding window where we keep the product of elements in the current window.

Expand the window by moving r and multiply the new element to prod.

If the product becomes ≥ k, shrink the window from the left (l) and divide those elements from the product until prod < k.

For every valid r, all subarrays ending at r from l to r have product < k, so we add (r - l + 1) to the answer.

This efficiently counts all valid subarrays in O(n) time.



###### C O D E 
```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int n = nums.size();
      int l =0, r=0,prod =1,ans =0;
      for(int r=0;r<n;r++){
        prod*=nums[r];
        while(prod >=k && l<=r ) {
           prod/=nums[l];
           l++;
        }
             ans += r-l+1; 
      }  
      return ans;
    }

```
