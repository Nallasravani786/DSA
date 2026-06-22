#### I M A G E
<img width="2828" height="1442" alt="image" src="https://github.com/user-attachments/assets/8d3bb0db-64ba-4710-a16e-6e256dfe8c5c" />

#### I N T U I T I O N
Treat each cell as a graph node and move in 4 directions.

The cost of an edge is the absolute height difference between adjacent cells.

A path's effort is the maximum height difference encountered on that path.

We need to find a path from (0,0) to (n-1,m-1) with the minimum possible maximum difference.

Use Dijkstra's algorithm, but instead of storing sum of costs, store the maximum effort seen so far.

For every neighbor, calculate: newEffort = max(currentEffort, abs(height difference));

If this new effort is smaller than the previously known effort for that cell, update it.

The first time we reach the destination with the minimum effort, that effort is the answer.

###### C O D E 
```cpp
 int minimumEffortPath(vector<vector<int>>& heights) {

      priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq;

     int n =  heights.size();
     int m = heights[0].size();

     vector<vector<int>>dist(n,vector<int>(m,1e9));

     dist[0][0] = 0;
     pq.push({0,{0,0}});

     int dr[4] = {-1,1,0,0};
     int dc[4] = {0,0,-1,1};

     while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

       int diff = it.first;
       int row = it.second.first;
       int col = it.second.second;

       if(row == n-1 && col == m-1) return diff; 

       for(int i=0;i<4;i++){
         int nr = row + dr[i];
         int nc = col + dc[i];

         if(nr>=0 && nc>=0 && nr<n && nc<m) {
            int neweffort = max(diff,abs(heights[row][col] - heights[nr][nc]));

            if(neweffort < dist[nr][nc]){
                dist[nr][nc] = neweffort;
                pq.push({neweffort,{nr,nc}});
            }
         } 
       }
     }
     return 0;
    }

```

