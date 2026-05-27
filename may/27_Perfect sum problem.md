#### I M A G E
<img width="2831" height="1429" alt="image" src="https://github.com/user-attachments/assets/c39da9fb-4ca0-4229-8679-8cc48d199a40" />

#### I N T U I T I O N
At each index, we have 2 choices → pick or not pick the element.

If we pick, reduce target by current element.

If we don’t pick, target remains same.

We need to count all valid ways, not just check true/false.

Base case handles target = 0, element match, and especially zero elements carefully.

DP stores number of subsets for (index, target) to avoid recomputation.

###### m e m o i z a t i o n _ c o d e
```cpp
int f(int ind,vector<int>&arr,int target,vector<vector<int>>&dp){
       
       if(ind == 0){
           if(target ==0 && arr[ind] == 0) return 2;
           else if(target == 0 || arr[ind] == target) return 1;
          else return 0;
       }
       
       if(dp[ind][target]!=-1) return dp[ind][target];
       
       int pick= 0;
       if(arr[ind]<=target) pick = f(ind-1,arr,target-arr[ind],dp);
       int notpick = f(ind-1,arr,target,dp);
       
       return dp[ind][target] = pick + notpick;
   }

    int perfectSum(vector<int>& arr, int target) {
       int n = arr.size();
       vector<vector<int>>dp(n,vector<int>(target+1,-1));
       return f(n-1,arr,target,dp);
        
    }
```
###### t a b u l a t i o n _ c o d e
```cpp
int perfectSum(vector<int>&arr,int target){
       int n = arr.size();
       vector<vector<int>>dp(n,vector<int>(target+1,0));
       
       for(int tar =0;tar<=target;tar++){
         if(tar==0 && arr[0] == 0)  dp[0][tar] = 2;
         else if(tar == 0 || arr[0] == tar) dp[0][tar]= 1;
         else dp[0][tar] = 0;
       }
       
       for(int ind =1;ind<n;ind++){
           
           for(int tar = 0;tar<=target;tar++){
               
               int pick = 0;
               if(arr[ind]<=tar) pick = dp[ind-1][tar-arr[ind]];
               int notpick = dp[ind-1][tar];
               
               dp[ind][tar] = pick + notpick;
           }
       }
       return dp[n-1][target]; 
   }

```
###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int perfectSum(vector<int>&arr , int target){
        int n = arr.size();
        vector<int>prev(target+1,0),curr(target+1,0);
        
        for(int tar=0; tar<=target;tar++){
            if(tar ==0 && arr[0] == 0) prev[tar] = 2;
            else if(tar==0  || arr[0] == tar) prev[tar] = 1;
            else prev[tar] = 0;
        }
        
        for(int ind = 1;ind<n;ind++){
            for(int tar =0;tar<=target;tar++){
                
                int pick = 0;
                if(arr[ind] <=tar) pick = prev[tar-arr[ind]];
                int notpick = prev[tar];
                
                curr[tar] = pick + notpick;
                
            }
            prev = curr;
        }
        return prev[target]; 
    }


```
