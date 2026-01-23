## I N T U I T I O N ## 
For each number, we try to reverse-engineer it as a bitwise OR of two consecutive numbers x and x+1.

We brute-force all x smaller than the number and check if (x | (x+1)) matches it.

The first valid x is the smallest answer, so we stop early.

If no such x exists, we return -1 for that position.

```cpp

vector<int> minBitwiseArray(vector<int>& nums) {
      int n = nums.size();
      vector<int>ans;
      for(int i=0;i<n;i++){
         bool found = false;
        for(int x =0; x<nums[i];x++){

            if((x | (x+1)) == nums[i]) 
             {  found = true;
                ans.push_back(x);
                break;
             }
        }
      if(!found) ans.push_back(-1);
    }
      return ans;
     
    }
```
