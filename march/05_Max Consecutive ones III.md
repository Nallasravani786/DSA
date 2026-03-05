
<img width="2838" height="1253" alt="image" src="https://github.com/user-attachments/assets/1732f7b9-8bb2-4a61-94e6-03906adad73b" />

### I N T U I T I O N 
We want to find the longest subarray that contains only 1s.

Since we are allowed to flip at most k zeros, 

our goal is to find the largest "window" that contains no more than k zeros.

Expand: Move the right pointer r to include a new number.

The Constraint: If the number of 0s in your current window $[l, r]$ exceeds k,

the window is "broken."Shrink: Move the left pointer l forward until 

you have tossed out enough zeros to make the window valid again (i.e., zeros $\le k$).

Track: The largest window size you ever managed to maintain is your answer.

### W A Y 1
###### C O D E 

```cpp
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0,max_freq=0,maxi=0;
        unordered_map<int,int>hash;

        for(int r=0;r<n;r++){
            hash[nums[r]]++;
           if(nums[r]==1) max_freq = max(max_freq,hash[nums[r]]);


            while((r-l+1 - max_freq) > k){
                hash[nums[l]]--;
               l++;
            }
            maxi = max(maxi,r-l+1);
        }

    return maxi;
    }
```



### W A Y 2
###### C O D E

```cpp
int longestOnes(vector<int>& nums, int k) {
    int l = 0, r = 0, zeros = 0, maxi = 0;
    
    for (r = 0; r < nums.size(); r++) {
        if (nums[r] == 0) zeros++; // Track zeros directly
        
        while (zeros > k) { // If too many zeros, shrink from left
            if (nums[l] == 0) zeros--;
            l++;
        }
        
        maxi = max(maxi, r - l + 1);
    }
    return maxi;
}
```
