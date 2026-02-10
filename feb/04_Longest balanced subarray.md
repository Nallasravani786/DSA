## I N T U I T I O N 
Subarray Exploration: We use a double loop. The outer loop i sets the start of the window, and the inner loop j expands it.

Tracking Distinctness: As we move j, we keep adding numbers to two unordered_set containers. Sets automatically handle "distinctness" because they don't store duplicates.

The Balance Check: Every time we add a number, we check if distinctEvens.size() == distinctOdds.size(). If they are equal, the current subarray from i to j is "balanced."

Result: We keep track of the largest window size we've seen so far and return it at the end


```cpp
int longestBalanced(vector<int>& nums) {
      int n = nums.size();
      int maxlen =0;
      for(int i=0;i<n;i++){
        unordered_set<int>distincteven;
        unordered_set<int>distinctodd;
        for(int j=i;j<n;j++){
            if(nums[j]%2 ==0) distincteven.insert(nums[j]);
            else distinctodd.insert(nums[j]);
        
    if(distincteven.size()== distinctodd.size()){
        maxlen = max(maxlen, j-i+1);
           }
         }  
      }
      return maxlen;
    }

```
