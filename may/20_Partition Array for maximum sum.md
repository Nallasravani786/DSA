#### I M A G E

<img width="2849" height="1469" alt="image" src="https://github.com/user-attachments/assets/d5ca3f0c-000b-4a85-bc41-209f28aa4fc7" />

#### I N T U I T I O N

At every index, try all partition sizes from 1 to k.

For every partition: find maximum element  , multiply it with partition length.

Add remaining answer from next index.

Take maximum among all partition choices.

DP state:  f(ind) = maximum sum possible starting from index ind.

Use memoization because same indices are solved repeatedly.

###### C O D E 

```cpp
int f(int ind,vector<int>&arr,int k , vector<int>&dp){
    int n = arr.size();

    if(ind == n) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int maxi = INT_MIN;
    int ans  = INT_MIN;
    int len =0;

    for(int j=ind; j< min(ind+k,n);j++){
        len++;

        maxi = max(maxi,arr[j]);

        int sum = (len*maxi) + f(j+1,arr,k,dp);

        ans = max(ans,sum);
    }
    return dp[ind] = ans;
 }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        vector<int>dp(n,-1);
       return f(0,arr,k,dp);

    }

```
