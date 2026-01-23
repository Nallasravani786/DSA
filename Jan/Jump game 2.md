Simple intuition:

Think of this like level-by-level jumping (similar to BFS).

[l, r] represents the range of indices we can reach using the current number of jumps.

From all positions in this range, we find how far we can reach next (far).

We then move to this new range and increase the jump count.

When the range reaches or passes the last index, we’ve found the minimum number of jumps needed.
```cpp
int jump(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=0,jumps=0;
        while(r<n-1){
            int far = 0;
            for(int i =l;i<=r;i++){
              far = max( far, i+nums[i]);
            }
            l = r+1;
            r = far;
            jumps++;


        }
        return jumps;
    }
```

