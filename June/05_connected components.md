#### I M A G E 
<img width="2844" height="1372" alt="image" src="https://github.com/user-attachments/assets/1cb055f2-25e8-4864-aea8-c5b3b0b71c13" />

#### I N T U I T I O N

The graph is first converted from edge list → adjacency list for easy traversal.

A vis[] array keeps track of already visited nodes.

For every unvisited node, we assume it starts a new connected component.

We run BFS from that node to visit all nodes reachable from it.

BFS collects all nodes of that component in a list.

Each BFS result is stored in the final answer → gives all connected components of the graph.


###### C O D E

```cpp
vector<int>bfs(vector<vector<int>>&adj,vector<int>&vis,int stnode){
       vis[stnode] = 1;
       vector<int>ans;
       queue<int>q;
       
       q.push(stnode);
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           
           ans.push_back(node);
           
           for(auto it:adj[node]){
               if(!vis[it]){
                   vis[it] = 1;
                   q.push(it);
               }
           }
       }
       return ans;
   }
 
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
       
        vector<vector<int>>adj(V);
        
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<vector<int>>ans;
        
        vector<int>vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans.push_back(bfs(adj,vis,i));
            }
        }
        return ans;
    }


```

