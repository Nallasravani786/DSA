#### I M A G E
<img width="2866" height="1476" alt="image" src="https://github.com/user-attachments/assets/72afdeb7-f153-47c2-be53-116b857e7344" />

#### I N T U I T I O N

An island is a group of land cells ('1') connected horizontally or vertically.

Traverse the entire grid. Whenever an unvisited land cell is found, treat it as the start of a new island and increment the island count.

Run BFS/DFS from that cell to visit all connected land cells belonging to the same island.

Mark all visited land cells so that the same island is not counted again.

After traversing the whole grid, the count represents the total number of islands.

**Space Optimization**: Instead of using a separate visited array, we can mark visited land cells by changing '1' to '0' in the grid itself, eliminating the need for extra space.**
Interview One-Liner

Whenever I find an unvisited land cell, I count it as a new island and use BFS/DFS to visit all connected land cells, ensuring each island is counted exactly once. 🚀


#### C O D E (BFS)

```cpp
 int dr[4] = {1,-1,0,0};
 int dc[4] = {0,0,1,-1};

 void bfs(int r, int c, vector<vector<char>>&grid,vector<vector<int>>&vis){

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int,int>>q;

    q.push({r,c});

    vis[r][c] = 1;

    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr>=0 && nr < m && nc >=0 && nc < n){
                if(grid[nr][nc] == '1' && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    q.push({nr,nc});
                }
            }
        }
    }

 }

    int numIslands(vector<vector<char>>& grid) {
       int m = grid.size();
       int n = grid[0].size();

       vector<vector<int>>vis(m,vector<int>(n,0));

       int cnt = 0;

       for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++){
            if(grid[i][j] == '1' && !vis[i][j]) {
                cnt++;
                bfs(i,j,grid,vis);
            }
        }
       } 
       return cnt;
    }

```


#### C O D E (DFS)

```cpp
 void dfs(int r,int c , vector<vector<char>>&grid){
        int m = grid.size();
        int n = grid[0].size();

        if( r < 0 || c <0 || r>=m || c>=n || grid[r][c] == '0') return ;
            
        grid[r][c] = '0';
        
        dfs(r-1,c,grid);
        dfs(r+1,c,grid);
        dfs(r,c-1,grid);
        dfs(r,c+1,grid);
    }

   int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == '1') {
                    cnt++;
                    dfs(i,j,grid);
                }
            }
        }
   return cnt;
   }

```
