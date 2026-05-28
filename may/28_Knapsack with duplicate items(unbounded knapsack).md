#### I M A G E
<img width="2823" height="1352" alt="image" src="https://github.com/user-attachments/assets/3727da18-4fd5-41ed-bcab-705c6b334e4f" />

#### I N T U I T I O N
Each item has 2 choices → pick or not pick.

Since this is Unbounded Knapsack, an item can be picked multiple times.

If you pick an item, stay at the same index and reduce capacity.

If you do not pick, move to the previous index.

dp[ind][capacity] stores the maximum profit using items 0..ind.

Goal: find the maximum value obtainable within the given capacity.


###### m e m o i z a t i o n _ c o d e

```cpp
 int f(int ind, vector<int>&val,vector<int>&wt,int capacity,vector<vector<int>>&dp){
      
      if(ind ==0) return (capacity/wt[0])*val[0];
      
      
      if(dp[ind][capacity]!=-1) return dp[ind][capacity];
      
      int pick = 0;
      
      if(wt[ind] <= capacity) pick = val[ind] + f(ind,val,wt,capacity-wt[ind],dp);
      
      int notpick = f(ind-1,val,wt,capacity,dp);
      
      return dp[ind][capacity] = max(pick,notpick);
           
  } 
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
       int n = val.size();
       vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
       return f(n-1,val,wt,capacity,dp);
        
    }

```

###### t a b u l a t i o n _ c o d e

```cpp
 int knapSack(vector<int>&val,vector<int>&wt,int capacity){
        
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        
        for(int c = 0; c<=capacity;c++) dp[0][c] = (c/wt[0])*val[0];
        
        for(int ind =1;ind<n;ind++){
            for(int c = 0;c<=capacity;c++){
                
                int pick = 0;
                if(wt[ind] <= c) pick = val[ind] + dp[ind][c-wt[ind]];
                int notpick = dp[ind-1][c];
                
                dp[ind][c] = max(pick,notpick);
                
            }
        }
        return dp[n-1][capacity];
    }
```

###### s p a c e _ o p t i m i z a t i o n _ c o d e

```cpp
 int knapSack(vector<int>&val,vector<int>&wt,int capacity){
        int n = val.size();
        
        vector<int>prev(capacity+1,0),curr(capacity+1,0);
        
        for(int c=0;c<=capacity;c++) prev[c] = (c/wt[0])*val[0];
        
        for(int ind=1;ind<n;ind++){
            
            for(int c=0;c<=capacity;c++){
                
                int pick = 0;
                if(wt[ind]<=c) pick = val[ind] + curr[c-wt[ind]];
                int notpick = prev[c];
                
                curr[c] = max(pick,notpick);
            }
            prev = curr;
        }
        return prev[capacity];
    }


```
