#### I M A G E
<img width="2807" height="1275" alt="image" src="https://github.com/user-attachments/assets/5ff01e2b-b87a-4dce-a39c-adc7adae7aab" />

#### I N T U I T I O N
For every element, you have 2 choices: pick it or not pick it.

If after choosing elements the remaining sum becomes 0, a valid subset is found.

At index 0, answer is true only if arr[0] == sum.

Recursive idea:

take current element → solve for (ind-1, sum-arr[ind])
skip current element → solve for (ind-1, sum)
If either choice returns true, then subset exists.

Same (ind, sum) states repeat many times, so use memoization.

dp[ind][sum] stores whether a subset using indices 0..ind can make the required sum.

###### m e m o i z a t i o n _ c o d e
```cpp
bool f(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp){
       
      if(sum == 0) return true;
      if(ind == 0)  return sum == arr[ind];
      
      
      if(dp[ind][sum]!=-1) return dp[ind][sum];
      
       bool pick = false;
      
      if(arr[ind]<=sum) pick = f(ind-1,sum-arr[ind],arr,dp);
      bool notpick = f(ind-1,sum,arr,dp);
      
      return dp[ind][sum] = pick || notpick;
   }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp); 
    }

```
###### t a b u l a t i o n _ c o d e
```cpp
bool isSubsetSum(vector<int>&arr,int sum){
     
     int n = arr.size();
     vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
     
   if(arr[0]<=sum) dp[0][arr[0]] = true;
    for(int i=0;i<n;i++) dp[i][0] = true;
     
     
     for(int ind =1;ind <n;ind++){
         
         for(int tar = 1;tar<=sum;tar++){
             
             bool pick = false;
             if(arr[ind] <= tar) pick = dp[ind-1][tar-arr[ind]] ;
             bool notpick = dp[ind-1][tar];
             
             dp[ind][tar] = pick || notpick;   
     }
 }
      return dp[n-1][sum];
 }

```
###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 bool isSubsetSum(vector<int>&arr,int sum){
        int n = arr.size();
        
        vector<bool>prev(sum+1,0),curr(sum+1,0);
        
        prev[0] = curr[0] = true;
        if(arr[0] <=sum) prev[arr[0]] = true;
        
        for(int ind=1;ind<n;ind++){
            
            for(int tar = 1;tar<=sum;tar++){
                
                bool pick = false;
                if(arr[ind]<=tar) pick = prev[tar-arr[ind]];
                
                bool notpick = prev[tar];
                curr[tar] = pick|| notpick;
            }
            prev = curr;
        }
        return prev[sum];
         
        }

```

