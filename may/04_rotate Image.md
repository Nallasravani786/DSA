#### I M A G E
<img width="2831" height="1411" alt="image" src="https://github.com/user-attachments/assets/31ab30ba-9b5e-403d-adac-4ce8861534a4" />

#### I N T U I T I O N
A 90° clockwise rotation can be broken into two simple operations:
→ Transpose + Reverse each row
Transpose step:
Swap matrix[i][j] with matrix[j][i]
👉 This converts rows → columns
After transpose, the matrix is like a mirror along diagonal, but not yet rotated
Reverse each row:
👉 This shifts elements to correct positions for clockwise rotation
Why it works:
Position (i, j) finally moves to (j, n-1-i) — exactly what rotation needs


```cpp
 void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose( swap across diagonal)
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            } 
        }
        // reverse each row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return ;

    }

```

