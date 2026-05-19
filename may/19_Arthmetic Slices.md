
#### I M A G E

<img width="2845" height="1400" alt="image" src="https://github.com/user-attachments/assets/f28fa9e6-5811-49e0-8916-4575bbb3d2f3" />

#### I N T U I T I O N

Arithmetic subarray means consecutive differences must remain same.

Start checking from index 2 because minimum size needed is 3.

If current difference equals previous difference:

arithmetic sequence continues

new arithmetic subarrays are formed.

curr stores:

number of arithmetic subarrays ending at current index.

ans stores: total arithmetic subarrays till now.

If difference breaks: arithmetic chain stops

reset curr = 0.

###### C O D E

```cpp
 int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        if(n < 3) return 0;

        int curr =0,ans =0;

        for(int i = 2;i<n;i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                curr += 1;
                ans += curr;
            }
            else curr =0;
        }
        return ans;
    }

```
