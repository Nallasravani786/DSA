### I N T U I T I O N 

This code counts special positions in a binary matrix.

First, it counts how many 1s are present in each row and each column.

Then it scans the matrix again.

A cell is counted only if it is 1 and it is the only 1 in its row and column.

Using precomputed row and column counts makes it efficient — only O(m × n) time.

So instead of checking the entire row and column every time, we use counting to verify in constant time.

###### C O D E 


```cpp
int numSpecial(vector<vector<int>>& mat) {
       int m = mat.size();
       int n = mat[0].size();
       vector<int>row_cnt(m,0);
       vector<int>col_cnt(n,0);

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1) {
                row_cnt[i]++;
                col_cnt[j]++;
            }
        }
       }


       int ans =0;
       for(int i=0;i<m;i++){
         for(int j=0;j<n;j++){
            if(mat[i][j] ==1 && row_cnt[i]==1 && col_cnt[j]==1) ans++;
         }
       }
       return ans;
    }

```
