#### I M A G E
<img width="2834" height="1166" alt="image" src="https://github.com/user-attachments/assets/1c2fb044-8907-4d91-9d25-3ab3b595e61a" />

#### I N T U I T I O N
Divide array into 2 subsets with minimum sum difference.

Let one subset sum be s1, then other subset sum = totsum - s1.

Difference formula: abs((totsum-s1)-s1).

Find all possible subset sums using pick / notpick DP.

Check every possible s1 till totsum/2.

Choose the s1 giving the minimum difference.


###### m e m o i z a t i o n _ c o d e
```cpp
 bool f(int ind,vector<int>&arr,vector<vector<int>>&dp,int tar){
      if(tar == 0) return true;
      if(ind == 0) return arr[ind] == tar;
      
      if(dp[ind][tar]!=-1) return dp[ind][tar];
      
      bool pick = false;
      if(arr[ind] <= tar) pick = f(ind-1,arr,dp,tar-arr[ind]);
      
      bool notpick = f(ind-1,arr,dp,tar);
      
      return dp[ind][tar] = pick || notpick;
      
  }
  
    int minDifference(vector<int>& arr) {
       int n = arr.size();
       int totsum =0;
       for(int i=0;i<n;i++) totsum+=arr[i];
       vector<vector<int>>dp(n,vector<int>(totsum+1,-1));
       
       for(int s=0;s<=totsum;s++) f(n-1,arr,dp,s);
       
       int mini = 1e9;
       for(int s1 =0;s1<=totsum/2;s1++){
           if(f(n-1,arr,dp,s1)) mini = min(mini,abs((totsum-s1)-s1));
       } 
       return mini;
    }
```

###### t a b u l a t i o n _ c o d e
```cpp
 int minDifference(vector<int>&arr){
        int n = arr.size();
        int totsum = 0;
        for(int i=0;i<n;i++) totsum += arr[i];
        vector<vector<bool>>dp(n+1,vector<bool>(totsum+1,0));
        
       for(int i=0;i<n;i++) dp[i][0] = true;
       if(arr[0] <= totsum) dp[0][arr[0]] = true;
       
       for(int ind =1;ind<n;ind++){
           
          for(int tar =1;tar<=totsum;tar++){
              
              
              bool pick = false;
              if(arr[ind] <= tar) pick = dp[ind-1][tar-arr[ind]];
            
              bool notpick = dp[ind-1][tar];
              
              
              dp[ind][tar] = pick || notpick;
          }
       }
       
       int mini  = 1e9;
       for(int s1 = 0;s1<=totsum/2;s1++){
           if(dp[n-1][s1] == true) mini = min(mini,abs((totsum-s1)-s1));
       }
       return mini; 
    }

```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
int minDifference(vector<int>&arr){
        
        int n = arr.size();
        int totsum = 0;
        for(int i=0;i<n;i++) totsum += arr[i];
        vector<bool>prev(totsum+1,0),curr(totsum+1,0);
        
        prev[0] = curr[0] = true;
        
        if(arr[0]<=totsum) prev[arr[0]] = true;
        
        for(int ind =1;ind<n;ind++){
            for(int tar =1; tar<=totsum;tar++){
                
               bool pick = false;
               if(arr[ind]<=tar) pick = prev[tar-arr[ind]];
               
               bool notpick = prev[tar];
               
               curr[tar] = pick || notpick;
                
            }
            prev = curr;
        }
        
        int mini = 1e9;
        for(int s1 = 0;s1<=totsum/2;s1++){
            if(prev[s1] == true) mini = min(mini,abs((totsum-s1)-s1));
        }
        return mini;
    }


```
