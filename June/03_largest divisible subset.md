#### I M A G E
<img width="2852" height="1443" alt="image" src="https://github.com/user-attachments/assets/a60b594c-0a4d-4c83-b896-99a95d25cf4b" />

#### I N T U I T I O N 
First, sort the array. After sorting, smaller numbers come first, so checking divisibility becomes easier.


Think of it like LIS, but instead of checking increasing order (a < b), we check divisibility.

dp[i] stores the length of the largest divisible subset ending at index i.

For every current number nums[ind], check all previous numbers.

If nums[ind] % nums[prev] == 0, it means current number can be attached to the subset ending at prev.

If 1 + dp[prev] > dp[ind], we found a better/larger subset, so update dp[ind].

Use hash[] to store the previous index used to build the subset, because we need the actual subset, not just the length.

Keep track of the maximum subset length and the ending index using maxi and lastIndex.

After DP is finished, start from lastIndex and follow hash[] backward to reconstruct the subset.

Since reconstruction happens from end to start, reverse the answer at the end.

Simple connection:  This problem is basically LIS pattern + divisibility condition.

###### C O D E
```cpp
vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
       
       vector<int>dp(n,1);
       
       vector<int>hash(n);

       sort(nums.begin(),nums.end());
       
       for(int i=0;i<n;i++) hash[i] = i;
       
       int maxi = 0;
       
       int lastindex = 0;
       
       for(int ind=0;ind<n;ind++){
           
            for(int prev = 0;prev<ind;prev++){
                
                if(nums[ind] % nums[prev] == 0 && 1+dp[prev] > dp[ind]) {
                    dp[ind] = 1+dp[prev];
                    hash[ind] = prev;
                }
            }
            if(dp[ind] > maxi){
                maxi = dp[ind];
                lastindex = ind;
              }
            }
            
       vector<int>ans;
       
       ans.push_back(nums[lastindex]);
       
       while(hash[lastindex] != lastindex){
           lastindex = hash[lastindex];
           ans.push_back(nums[lastindex]);
           
       }
       reverse(ans.begin(),ans.end());
       
       return ans;
        
    }

```
