#### I M A G E
<img width="2830" height="1398" alt="image" src="https://github.com/user-attachments/assets/20379ea0-37ae-4b6e-9ef0-b293b05ecf28" />

#### I N T U I T I O N
A node is safe if every path starting from it eventually ends at a terminal node.

Terminal nodes are always safe.

Reverse the graph so that we can propagate safety backwards.

Nodes whose outgoing edges are all safe will eventually become safe.

Use Kahn's Algorithm on the reversed graph starting from terminal nodes.

All nodes processed by BFS are eventual safe nodes.

Interview One-Liner : I reverse the graph and start BFS from terminal nodes. Using Kahn's Algorithm, I propagate safety backwards, and every node that gets processed is an eventual safe node. 🚀

#### C O D E ( kahn's )
```cpp
 vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size(); 
        vector<vector<int>>reversedgraph(n);
        

        for(int i=0;i<n;i++){
            for(auto j: graph[i]){
                reversedgraph[j].push_back(i);
            }
        }

        vector<int>indeg(n);
        for(int i=0;i<n;i++){
            for(auto j : reversedgraph[i]){
                indeg[j]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:reversedgraph[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }

```
