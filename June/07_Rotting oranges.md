#### I M A G E
<img width="2804" height="1394" alt="image" src="https://github.com/user-attachments/assets/f7b9507b-b5d5-4cc9-a659-b116b214979a" />

#### I N T U I T I O N 
Think of rotten oranges as infection sources.

Infection spreads to 4 directions every minute.

We use BFS because it spreads level by level (time by time).

Start BFS from all rotten oranges at once (multi-source BFS).

Each BFS level = 1 minute passing.

Fresh oranges get converted to rotten as the infection spreads.

If all fresh oranges become rotten → return time, else return -1.


######  C O D E

```cpp
 int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;

        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 2) {
                    q.push({i,j});
                }

                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty() && fresh>0){
            int size = q.size();

         for(int i=0;i<size;i++){
            auto [r,c] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr>=0 && nr <n && nc>=0 && nc<m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
        }
        minutes++;
       }
        return (fresh == 0) ? minutes : -1;
    }
```
