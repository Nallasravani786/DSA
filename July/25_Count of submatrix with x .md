#### I M A G E

<img width="2830" height="1312" alt="image" src="https://github.com/user-attachments/assets/87047a11-e247-4aaf-825f-de686664cf19" />

###### C O D E
```cpp
int countSquare(vector<vector<int>>& mat, int x) {
       
       int n = mat.size();
       int m = mat[0].size();
       
       vector<vector<long long>>pref(n+1,vector<long long>(m+1,0));
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               pref[i][j] = mat[i-1][j-1] + pref[i-1][j] + pref[i][j-1] -pref[i-1][j-1];
           }
       }
       
       int cnt = 0;
       
       int max_k = min(n,m);
       
       for(int k=1;k<=max_k;k++){
           
           for(int i=k;i<=n;i++){
               for(int j=k;j<=m;j++){
                   
                   long long curr_sum = pref[i][j] - pref[i-k][j]-pref[i][j-k]+pref[i-k][j-k];
                   if(curr_sum == x) cnt++;
               }
           }
       }
       return cnt;
        
    }

```
