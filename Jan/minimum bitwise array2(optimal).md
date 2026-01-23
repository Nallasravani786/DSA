## I N T U I T I O N ##

We want to find a smaller number whose OR with the next number gives the current value.

Look for the first 0 bit in the number (from right), because changing bits there can alter the OR result.

Flip the bit just before that position using XOR to get the smallest possible candidate.

If no such bit change is possible (or the number is 2), return -1.

```cpp
vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]==2) 
            {
                ans.push_back(-1);
                continue;
            }
              bool found = false;
            for(int j=0;j<32;j++){
                if( (nums[i] & (1 << j) ) !=0 ){ //set back(to find first zero from last)
                    continue;
                }
                int prev = j-1;
                ans.push_back( nums[i] ^ (1<<(j-1)));  // XOR
                found = true;
                break;
            }
            if(!found) ans.push_back(-1);
        }
        return ans;
    }
```
