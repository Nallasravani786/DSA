#### I M A G E
<img width="2826" height="1444" alt="image" src="https://github.com/user-attachments/assets/20788ec9-bcc7-4ff2-babf-bef107b57157" />

#### I N T U I T I O N
The matrix isConnected[i][j] tells whether city i and city j are directly connected.

We convert the matrix into an adjacency list so that graph traversal becomes easier.

Each province is simply a connected component in the graph.

We maintain a vis[] array to keep track of cities that have already been explored.

For every unvisited city, we start a BFS and visit all cities reachable from it.

One BFS call covers exactly one entire province.

Therefore, every time we start BFS from an unvisited city, we increment the province count.

The final answer is the number of times BFS was started.

One-line idea  👉 Count the number of connected components in the graph using BFS, where each connected component represents one province.

```cpp
void bfs(vector<vector<int>>&adj,vector<int>&vis,int stnode){
    vis[stnode] = 1;
    queue<int>q;
    q.push(stnode);

    while(!q.empty()){
        int node = q.front();
        q.pop();
       

        for(int a:adj[node]){
            if(!vis[a]){
                vis[a] = 1;
                q.push(a);
            }
        }
    }
    
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(i!=j && isConnected[i][j] == 1) {
                adj[i].push_back(j);
            }
          }
       }

       int provinces = 0;
      
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                bfs(adj,vis,i);
                provinces++;
            }
        }

        return provinces;
    }

```
