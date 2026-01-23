                                    ** Intuition**
              We work backwards, keeping track of the leftmost position (goal) from which the last index can be reached.
            
            Initially, the goal is the last index itself.
            
            If from index i we can jump to or beyond the current goal, then index i becomes the new goal.
            
            If we can finally move the goal back to index 0, it means the start can reach the end, so we return true.

```cpp
bool canJump(vector<int>& nums) {
       int n = nums.size();
       int goal = n-1;
       for(int i=n-2;i>=0;i--){
        if(i+nums[i] >= goal){
            goal =i;
        }
       }
     if(goal ==0) return true;
     return false;
    }
