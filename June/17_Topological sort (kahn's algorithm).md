#### I M A G E
<img width="2842" height="1428" alt="image" src="https://github.com/user-attachments/assets/3f10b33e-5b7b-4b98-b780-054a01b35df5" />

#### I N T U I T I O N

Topological Sort is used to arrange the nodes of a DAG such that every node appears after its prerequisites.

A node with indegree 0 has no incoming edges, which means it has no pending prerequisites.

First, add all nodes with indegree 0 into the queue.

Remove a node from the queue and add it to the answer.

For every neighbor of that node, decrease its indegree by 1 because one prerequisite has been completed.

If a neighbor's indegree becomes 0, push it into the queue.
Continue this process until the queue becomes empty.

The order in which nodes are removed from the queue forms the Topological Order.

Interview One-Liner  : Process nodes with indegree 0 first, remove their effect on neighbors, and keep adding newly eligible nodes to obtain a valid topological ordering. 🚀

#### C O D E ( extended BFS )

```cpp
vector<int>topoSort(int V , vector<vector<int>>&edges){
       
       vector<vector<int>>adj(V);
       
       for(auto e:edges){
           adj[e[0]].push_back(e[1]);
       }
       
       vector<int>indeg(V,0);
       
       for(int i=0;i<V;i++){
          for(auto it: adj[i]){
              indeg[it]++;
          }
       }
       
       queue<int>q;
       
       for(int i=0;i<V;i++){
           if(indeg[i] == 0){
               q.push(i);
           }
       }
       
       vector<int>topo;
       
       while(!q.empty()){
           int node = q.front();
           q.pop();
           topo.push_back(node);
           
           
           for(auto it : adj[node]){
               indeg[it]--;
               if(indeg[it] == 0) q.push(it);
           }
       }
       return topo;
   }

```
