#### I M A G E
<img width="2848" height="1441" alt="image" src="https://github.com/user-attachments/assets/a3dfabbf-d9b6-485b-a84e-95c8ec2d835d" />

#### I N T U I T I O N
Sort the array so consecutive values come together.

Every element has 2 choices: use as it is or increase by 1.

Maintain:  dp[x] = longest consecutive sequence ending at value x.

If using current value normally:

extend sequence ending at x-1.

If modifying current value to x+1:

extend sequence ending at x.

Store maximum sequence length for every value.

Final answer is maximum value in DP/hashmap.

######   C O D E

```cpp
int maxSelectedElements(vector<int>& nums) {
    
    int n = nums.size();
    
    sort(nums.begin(),nums.end());
    
    unordered_map<int,int>dp;

    int ans = 1;

    for(int x:nums){

        int normal = dp[x-1] +1;

        int modiefied = dp[x]+1;

        dp[x]  = max(dp[x], normal);

        dp[x+1] = max(dp[x+1],modiefied);

         ans = max(ans, max(dp[x],dp[x+1]));
         
       }
    return ans;
    }

```
