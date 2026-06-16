#### I M A G E
<img width="2840" height="1356" alt="image" src="https://github.com/user-attachments/assets/c6dbd5ba-8944-4f52-b698-e896ec29ba7a" />

#### I N T U I T I O N
Topological Sort is used only for a Directed Acyclic Graph (DAG).

The goal is to arrange nodes such that for every directed edge u → v, node u appears before node v in the ordering.

Using DFS, first visit all neighbors of a node before processing the node itself.

Once all descendants of a node are visited, push that node into a stack.

This means the node is added only after all nodes dependent on it are processed.

After DFS is completed, the stack contains nodes in reverse topological order.

Pop all elements from the stack to get the final topological ordering.

###### C O D E
```cpp
 void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
       
       vis[node] = 1;
       for(auto it:adj[node]){
           if(!vis[it]) dfs(it,vis,st,adj);
       }
       st.push(node);
  }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<int>vis(V,0);
        
        vector<vector<int>>adj(V);
        
        for(auto e: edges){
            adj[e[0]].push_back(e[1]);
        }
       
        stack<int>st;
       
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        } 
          
        vector<int>ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }

```
