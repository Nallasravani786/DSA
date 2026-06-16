#### I M A G E 
<img width="2854" height="1384" alt="image" src="https://github.com/user-attachments/assets/ffe64d74-6fba-415b-a36b-a73366573bfc" />

#### I N T U I T I O N

We need to check whether the directed graph contains a cycle.

Use DFS to traverse the graph.

Maintain a vis[] array to track nodes that have already been visited.

Maintain a pathVis[] array to track nodes that are part of the current DFS path.

While exploring a node's neighbors, if we reach a node that is already in the current DFS path (pathVis[node] == 1), then a cycle exists.

This means we have found a back edge that leads to an ancestor in the current DFS traversal, which forms a cycle.

After finishing DFS for a node, remove it from the current path by setting pathVis[node] = 0.


###### C O D E (DFS)
```cpp
 bool dfscheck(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis){
      vis[node] = 1;
      pathvis[node] = 1;
      for(auto it: adj[node]){
          
          if(!vis[it]){
              if(dfscheck(it,adj,vis,pathvis) == true) return true;
          }
          else if(pathvis[it]) return true;
      }
      
      pathvis[node] = 0;
      return false;
  }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
       vector<int>vis(V,0);
       vector<int>pathvis(V,0);
       
       vector<vector<int>>adj(V);
       
       for(auto e: edges){
           adj[e[0]].push_back(e[1]);
       }
       
       for(int i=0;i<V;i++){
           if(!vis[i]){
               if(dfscheck(i,adj,vis,pathvis) == true) return true;
           }
       }
       return false;
        
    }
```

