#### I M A G E
<img width="2834" height="1362" alt="image" src="https://github.com/user-attachments/assets/6a1d3b94-de8d-4581-8701-da9fb0b506ea" />

#### I N T U I T I O N
A bipartite graph can be divided into two groups such that no two adjacent nodes belong to the same group.

Think of the two groups as two colors: 0 and 1.

Start from any node and assign it a color.

Assign the opposite color to all of its neighbors.

While traversing the graph, if an adjacent node already has the same color as the current node, a conflict occurs and the graph is not bipartite.

Since the graph may be disconnected, run BFS/DFS from every uncolored node.

Interview One-Liner   :  The idea is to color the graph using two colors such that every edge connects nodes of different colors. If this is possible, the graph is bipartite; otherwise, it is not. 🚀

###### C O D E (BFS) 

```cpp
 bool bfs(int start,int col,vector<vector<int>>&graph,vector<int>&color){

      color[start] = col;
      queue<int>q;
      q.push(start);
      
      while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto adj:graph[node]){

            if(color[adj] == -1){
                color[adj] = !color[node];
                q.push(adj);
            }
            else if(color[adj] == color[node]) return false;
        }
      } 
      return true;
  }


    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,0,graph,color)) return false;
            }
        }
        return true;
    }

```
###### C O D E (DFS)

```cpp
 bool dfs(int node,int col,vector<vector<int>>&graph,vector<int>&color){
      
      color[node] = col;


      for(auto adj:graph[node]){

        if(color[adj] == -1){
            
            if(!dfs(adj,!col,graph,color)) return false;
        }
        else if(color[adj] == color[node]) return false;
      }

     return true;
  }

   bool isBipartite(vector<vector<int>>&graph){
    int n = graph.size();
    vector<int>color(n,-1);

    for(int i=0;i<n;i++){
        if(color[i] == -1){
            if(!dfs(i,0,graph,color)) return false;
        }
     }
    return true;
   }

```
