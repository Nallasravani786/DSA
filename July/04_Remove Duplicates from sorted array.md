#### I N T U I T I O N
The first element is always unique, so keep it.

cnt always points to the position where the next unique element should be placed.

Traverse from the second element onward.

If the current element is different from the last unique element (nums[cnt - 1]), copy it to nums[cnt] and increment cnt.

At the end, the first cnt elements are the unique elements in sorted order.

###### C O D E
```cpp
 int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cnt=1;
         for(int i=1;i<n;i++){
            if(nums[i]!=nums[cnt-1]) {
                nums[cnt] = nums[i];
                cnt++;
            }
         }
         return cnt;
    }

```
