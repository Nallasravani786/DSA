#### I M A G E

<img width="2874" height="1426" alt="image" src="https://github.com/user-attachments/assets/4cdd3124-ebdf-466c-b704-f8d5b97d1e84" />

#### I N T U I T I O N
We need to send a signal from source node k to all nodes.

Each edge has a travel time, so we need the minimum time to reach every node.

Since the graph is weighted, use Dijkstra's Algorithm.

Always process the node with the smallest current time using a min-heap (priority queue).

If a shorter path to a neighbor is found, update its distance and push it into the priority queue.

After finding the shortest time to every node:

If any node is unreachable, return -1.

Otherwise, the maximum shortest distance is the answer because the signal reaches all nodes only when the last node receives it.

One-line Intuition :Find the shortest time from the source to every node using Dijkstra. The largest of these shortest times is the total network delay.


###### C O D E
```cpp
 int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                        greater<pair<int,int>>>pq;

        
        vector<vector<pair<int,int>>>adj(n+1);

       for(auto e:times){
        adj[e[0]].push_back({e[1],e[2]});
       }
       vector<int>dist(n+1,1e9);
       dist[k] = 0;
       pq.push({0,k});

       while(!pq.empty()){
         int time = pq.top().first;
         int node = pq.top().second;

         pq.pop();

         if(time > dist[node]) continue;

        for(auto it:adj[node]){
            int adjnode = it.first;
            int edgetime = it.second;

            if(time + edgetime < dist[adjnode]){
                dist[adjnode] = edgetime + time;
                pq.push({dist[adjnode],adjnode});
            }
          }
        }

       for(int i=1;i<=n;i++){
        if(dist[i] == 1e9) return -1;
       }

       int ans = *max_element(dist.begin()+1,dist.end());
       return ans;
    }
```
