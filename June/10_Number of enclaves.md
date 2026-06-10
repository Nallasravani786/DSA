#### I M A G E
<img width="2880" height="1800" alt="Screenshot 2026-06-10 071313" src="https://github.com/user-attachments/assets/47bdf965-375d-4b5e-bba5-bb3d4e595263" />

#### I N T U I T I O N
We are given a grid of 0 (water) and 1 (land)

We need to find land cells that cannot reach the boundary

Instead of finding enclaves directly, we find boundary-connected land first

Start DFS/BFS from all border cells having 1

Mark all connected land as visited (safe land)

Finally, count all unvisited 1’s → these are enclaves

###### C O D E (BFS)
```cpp
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

void bfs(int r,int c , vector<vector<int>>&grid,vector<vector<int>>&vis){

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>>q;

    q.push({r,c});
    vis[r][c] = 1;

    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nr = x + dr[i];
            int nc = y + dc[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n) {
                if(grid[nr][nc] == 1 && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }
}

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(i == 0 || j == 0 || i == m-1 || j == n-1){
                if(grid[i][j] == 1 && !vis[i][j])  bfs(i,j,grid,vis);
               }
            }
        }

        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
```

