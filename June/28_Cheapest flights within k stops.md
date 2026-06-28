#### I M A G E

<img width="2786" height="1446" alt="image" src="https://github.com/user-attachments/assets/3dbd2fb3-2d54-4300-bedf-bcc475838fc2" />

#### I N T U I T I O N
We need to find the minimum cost from src to dst.But there is an extra constraint: we can use at most k stops.

Normal Dijkstra cannot be used directly because it only minimizes cost, not the number of stops.

So, along with each node, we also store the number of stops used.

Use BFS (Queue) because we process paths level by level based on the number of stops.

If the current path uses more than k stops, ignore it.

If reaching a neighboring node with a lower cost, update its cost and push it into the queue with stops + 1.

Continue until the queue becomes empty. The minimum recorded cost to dst is the answer.

Key Idea: Store three things in the queue: (stops, node, cost).
         Always explore paths only if stops ≤ k, and update a node only when a cheaper cost is found.


#### C O D E
```cpp
 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(auto e: flights){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int>dist(n,1e9);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k) continue;

            for(auto iter: adj[node]){
                int adjnode = iter.first;
                int edw = iter.second;

                if(cost + edw < dist[adjnode] && stops <= k){
                    dist[adjnode] = cost + edw;
                    q.push({stops+1,{adjnode,cost + edw}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];

    }
```
