#### I N T U I T I O N
A sorted array has 0 places where nums[i] > nums[i+1].

A sorted and rotated array has exactly 1 such place (the rotation point).

Since the array is circular, you must also compare the last element with the first using: nums[(i + 1) % n]

If there is more than one such "drop", the array cannot be sorted and rotated.


###### C O D E
```cpp
 bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > nums[(i+1)% n]) cnt++;
        }
        return cnt<=1;
    }

```
