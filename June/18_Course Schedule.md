#### I M A G E
<img width="2846" height="1396" alt="image" src="https://github.com/user-attachments/assets/0d416d49-47af-4436-9df9-61cf886024b8" />

#### I N T U I T I O N

Each prerequisite represents a dependency between courses.

If bi must be taken before ai, create an edge bi → ai.

The problem is asking whether it is possible to complete all courses.

If the graph contains a cycle, the courses involved in the cycle depend on each other and can never be completed.

Use Topological Sort (Kahn's Algorithm) to process courses whose prerequisites are already satisfied.

Start with all courses having indegree 0 (no prerequisites).

As a course is completed, reduce the indegree of its dependent courses.

If all courses can be processed, then no cycle exists and all courses can be finished.

If some courses remain unprocessed, a cycle exists, so it is impossible to finish all courses.

Interview One-Liner  : The idea is to perform a topological sort and check whether all courses can be processed. If the number of processed courses equals the total number of courses, all courses can be completed; otherwise, a cycle exists. 🚀


#### C O D E ( kahn's algo )

```cpp
 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indeg(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto j: adj[i]){
                indeg[j]++;
            }
        }
    
       queue<int>q;
       vector<int>topo;

       for(int i=0;i<numCourses;i++){
        if(indeg[i] == 0) q.push(i);
       }

       while(!q.empty()){
         
         int node = q.front();
         q.pop();
         topo.push_back(node);

         for(auto it: adj[node]){
            indeg[it]--;
            if(indeg[it] == 0) q.push(it);
         }
       }

      if(topo.size() == numCourses) return true;
      return false;
    }

```

