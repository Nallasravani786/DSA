#### I M A G E
<img width="2764" height="1384" alt="image" src="https://github.com/user-attachments/assets/f7cce08f-3efe-4ac2-8742-5d6dadab9747" />

#### I N T U I T I O N
All edges have weight 1, so BFS is used to find the shortest path.

BFS visits nodes level by level from the source node.

When we move from a node to its neighbor, the distance increases by 1.

The first time we reach a node, we have found its shortest distance.

Store the shortest distance of every node in a distance array.

If a node cannot be reached from the source, its answer is -1.

One-Line Intuition : Since every edge has the same weight, BFS explores nodes in order of increasing distance and naturally gives the shortest path from the source to every node. 🚀


###### C O D E ( BFS )

```cpp
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>>adj(V);
        
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        queue<int>q;
        vector<int>dist(V,1e9);
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(dist[node]+1 < dist[it]){
                    dist[it] = 1+dist[node];
                    q.push(it);
                }
            }
        }
        
        vector<int>ans(V,-1);
        for(int i=0;i<V;i++){
            if(dist[i]!= 1e9) ans[i] = dist[i];
        }
        return ans;
    }
```
