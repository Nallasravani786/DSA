#### I M A G E
<img width="2824" height="1428" alt="image" src="https://github.com/user-attachments/assets/6b40a692-a3c0-4f9a-9e2f-11ec0ba919bf" />

#### I N T U I T I O N
We need to find the minimum number of steps to reach the destination from the source in a grid.

Since every move (up, down, left, right) has the same cost = 1, we use BFS.

Start BFS from the source cell and store the distance of each cell from the source.

For every cell, explore its 4 possible directions.

If a neighboring cell is valid, open (1), and we found a shorter distance, update its distance and push it into the queue.

The first time we reach the destination during BFS, that distance is the shortest path length.

If the queue becomes empty and the destination is not reached, return -1 (no path exists).


#### C O D E 
```cpp
 int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) {
       
       if(mat[src[0]][src[1]] == 0) return -1;
       if(mat[dest[0]][dest[1]] == 0) return -1;
       if(src[0] == dest[0] && src[1] == dest[1]) return 0;
       
       queue<pair<int,pair<int,int>>>q;
       
       int n = mat.size();
       int m = mat[0].size();
       
       vector<vector<int>>dist(n,vector<int>(m,1e9));
        
      dist[src[0]][src[1]] = 0;
      
      q.push({0,{src[0],src[1]}});
      
      int dr[4] = {-1,1,0,0};
      int dc[4] = {0,0,1,-1};
      
      while(!q.empty()){
         auto it = q.front();
         q.pop();
         int dis = it.first;
         int r = it.second.first;
         int c = it.second.second;
         
         for(int i=0;i<4;i++){
             int nr = r + dr[i];
             int nc = c + dc[i];
             
             if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc] == 1 && dis + 1 < dist[nr][nc]){
                 
                 dist[nr][nc] = 1+ dis;
                 if(nr == dest[0] && nc == dest[1]) return 1+dis;
                 q.push({dist[nr][nc],{nr,nc}});
             }
         }
      }
        
      return -1;
    }
```
