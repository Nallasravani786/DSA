#### I M A G E
<img width="2852" height="1414" alt="image" src="https://github.com/user-attachments/assets/bba412b6-45da-47b3-837f-a8bcb28b0f18" />

#### I N T U I T I O N
Each cell containing 0 is a starting point

We want the minimum distance from every 1 to nearest 0

Instead of checking each 1 individually, we start from all 0s together

Use Multi-source BFS (level order traversal) to expand outward

Each BFS level increases distance by 1

First time we reach a cell → it is the shortest distance

###### C O D E (BFS)

```cpp
 vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 0){ 
                q.push({i,j});
                dist[i][j] = 0;
                }
            }
        }

        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};

        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();
            for(int i=0;i<4;i++){

                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >=0 && nc >=0 && nr < m && nc < n){
                    if(dist[nr][nc] == -1) {
                        
                        dist[nr][nc] = dist[r][c] +1;
                        q.push({nr,nc});}
                }
            }
        }
        return dist;
    }
```
