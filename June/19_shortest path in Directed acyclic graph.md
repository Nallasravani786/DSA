#### I M A G E
<img width="2836" height="1426" alt="image" src="https://github.com/user-attachments/assets/d35a8380-3b1c-4ac4-b7e6-e07a641a3586" />

#### I N T U I T I O N

Since the graph is a DAG, we first find its Topological Order.

In Topological Order, a node is always processed before its dependent nodes.

Start with dist[0] = 0 and all other distances as infinity.

Process nodes in Topological Order and relax all outgoing edges.

If a shorter path to a neighbor is found, update its distance.

Because the graph has no cycles, each edge is relaxed only once.

Nodes that are never reached from the source are marked as -1.

Interview One-Liner : Find the Topological Order, then process nodes in that order and relax their outgoing edges to compute the shortest distance from the source to every node. 🚀

###### C O D E
```cpp
 void toposort(int node,vector<vector<pair<int,int>>>&adj,vector<int>&vis,stack<int>&st){
      
      vis[node] = 1;
      
      for(auto it: adj[node]){
           int v = it.first;
          if(!vis[v]){
              toposort(v,adj,vis,st);
          }
      }
      
      st.push(node);
  }
  
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V);
      
        for(auto e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                toposort(i,adj,vis,st);
            }
        }
        vector<int>dist(V,1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto it: adj[node]){
                int v = it.first;
                int wt = it.second;
                
                if(dist[node] + wt < dist[v]){
                    dist[v] = wt + dist[node];
                }
            }
            
        }
        
        for(int i=0;i<V;i++){
         if(dist[i] == 1e9)
             dist[i] = -1;
     }
        return dist;
        
    }

```


