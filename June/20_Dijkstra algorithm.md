#### I M A G E
<img width="2854" height="1404" alt="image" src="https://github.com/user-attachments/assets/a9d7b1d3-9597-4eea-8113-4fed507e5da1" />

#### I N T U I T I O N
We need to find the shortest distance from a source node to all other nodes in a weighted graph.

Start from the source node and maintain a dist[] array that stores the minimum distance found so far.

Use a min priority queue to always pick the node with the smallest current distance.

From the selected node, check all its adjacent nodes and try to find a shorter path (relaxation).

If a shorter path is found, update the distance and push the updated value into the priority queue.

Continue this process until all possible shortest distances are finalized.

Main idea:  Always process the node with the smallest known distance first and keep improving the shortest paths of its neighbors.

time complexity : ElogV

###### C O D E ( using priority queue )
```cpp
 vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        priority_queue<
             pair<int,int>,
             vector<pair<int,int>>,
             greater<pair<int,int>>
             >pq;
        
       vector<vector<pair<int,int>>>adj(V);
       
       for(auto e: edges){
           
           adj[e[0]].push_back({e[1],e[2]});
           adj[e[1]].push_back({e[0],e[2]});
       }
        
        vector<int>dist(V,1e9);
        
        dist[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            
            pq.pop();
            
            for(auto it:adj[node]){
               int adjnode = it.first;
               int edgewt = it.second;
               
               if(dis + edgewt < dist[adjnode]){
                   dist[adjnode] = dis + edgewt;
                   pq.push({dist[adjnode],adjnode});
               }
            }
        }
        return dist;
    }

```
###### C O D E ( using set )
```cpp
 vector<int> dijkstra(int V,vector<vector<int>>&edges,int src){
        
        set<pair<int,int>>st;
        
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        
        st.insert({0,src});
        
        vector<int>dist(V,1e9);
        
        dist[src] = 0;
        
       while(!st.empty()){
           auto it = *(st.begin());
           int dis = it.first;
           int node = it.second;
           
           st.erase(it);
           
           for(auto i : adj[node]){
               int edgewt = i.second;
               int adjnode = i.first;
               
               if(edgewt + dis < dist[adjnode]){
                   
                   
                   if(dist[adjnode]!= 1e9) {
                       st.erase({dist[adjnode],adjnode});
                   }
                   dist[adjnode] = edgewt + dis;
                   st.insert({dist[adjnode],adjnode});
                   
               }
           }
        }
           return dist;
    }
```
