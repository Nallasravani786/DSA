#### I M A G E
<img width="2838" height="1340" alt="image" src="https://github.com/user-attachments/assets/18b99ba6-9090-42ce-a624-27643ba9002e" />

#### I N T U I T I O N
We need to count subarrays having exactly k odd numbers.

Counting exactly k directly using Sliding Window is difficult.

So, first count subarrays with at most k odd numbers.

Then count subarrays with at most k-1 odd numbers.

Their difference gives the subarrays with exactly k odd numbers.

###### C O D E
```cpp
int atmost(vector<int>&nums,int k){
    int odd = 0,l=0;
         int ans = 0;
        
         for(int r=0;r<nums.size();r++){
            if(nums[r] % 2 !=0) odd++;
            
             while(odd >k){
                if(nums[l]%2 !=0) odd--;
                l++;
             }
             ans += (r-l+1);
         }
         return ans;
  }

    int numberOfSubarrays(vector<int>& nums, int k) {

        return atmost(nums,k)-atmost(nums,k-1);
    }
```
