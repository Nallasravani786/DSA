## I N T U T I O N ##

First, sort the array so that close values come next to each other.

We want to pick k elements whose max − min is as small as possible.

In a sorted array, for any group of k elements starting at index i,
the minimum is nums[i] and the maximum is nums[i+k-1].

Slide this window of size k across the array and compute the difference.

Keep updating the smallest difference — that’s the answer.

```cpp
 int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;

        sort(nums.begin(),nums.end());

        for(int i=0;i+k-1<n;i++){
            ans = min(ans, nums[i+k-1]-nums[i]);
        }
        return ans;
    }
```
