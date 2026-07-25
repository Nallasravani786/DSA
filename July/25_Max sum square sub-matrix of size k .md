#### I M A G E
<img width="2844" height="1372" alt="image" src="https://github.com/user-attachments/assets/67f8f165-699a-4efd-be29-c0bc2bbf8f8a" />

###### C O D E
```cpp
 int maximumSum(vector<vector<int>>& mat, int k) {
      
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<long long>>pref(n+1,vector<long long>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] -pref[i-1][j-1];
            }
        }
        
        int maxsum = INT_MIN;
        
        for(int i=k;i<=n;i++){
            for(int j=k;j<=m;j++){
               int curr_sum = pref[i][j] - pref[i-k][j]-pref[i][j-k] + pref[i-k][j-k];
                maxsum = max(maxsum,curr_sum);
            }
        }
        
        return maxsum;
    }

```
