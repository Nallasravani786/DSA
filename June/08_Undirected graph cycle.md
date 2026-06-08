#### I M A G E

<img width="2814" height="1400" alt="image" src="https://github.com/user-attachments/assets/9d87f3dc-45cb-495e-86c4-d49e22603287" />

#### I N T U I T I O N
We traverse the graph using DFS or BFS starting from each unvisited node

We keep track of visited nodes so we don’t process same node again

While exploring a node’s neighbors:  If neighbor is not visited → continue traversal ,  If neighbor is visited and not the parent → cycle exists

Parent is used to ignore the edge we came from (since graph is undirected)

If we find a visited node through a different path, it means a loop is formed → cycle detected


###### C O D E (DFS)

```cpp
 bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&vis){
      
      vis[node] = true;
      
      for(int neighbour : adj[node]){
          if(!vis[neighbour]){
            if( dfs(neighbour,node,adj,vis)) return true;
          }
          else if(neighbour != parent) return true;
      }
      return false;
  }

    bool isCycle(int V, vector<vector<int>>& edges) {
      int E = edges.size();
      
      vector<vector<int>>adj(V);
      
      for(auto &e:edges){
          adj[e[0]].push_back(e[1]);
          adj[e[1]].push_back(e[0]);
      }
      vector<bool>visited(V,false);
      
      for(int i=0;i<V;i++){
          if(!visited[i]) {
             if(dfs(i,-1,adj,visited)) return true;
              
          }
      }
      return false;
        
    }

```
###### C O D E(BFS)

```cpp
class Solution {
public:

    bool bfs(int start, vector<vector<int>>& adj, vector<int>& visited) {
        queue<pair<int,int>> q; // {node, parent}
        q.push({start, -1});
        visited[start] = 1;

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {

                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // build adjacency list
        vector<vector<int>> adj(V);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);

        // check all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited))
                    return true;
            }
        }
        return false;
    }
};
```
