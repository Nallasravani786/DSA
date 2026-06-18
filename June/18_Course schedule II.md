#### I M A G E
<img width="2846" height="1354" alt="image" src="https://github.com/user-attachments/assets/5bae4ad2-5c36-4cc8-aac2-ed8774baf982" />

#### I N T U I T I O N
Each prerequisite represents a dependency between courses.

If bi must be taken before ai, create an edge bi → ai.

The goal is not just to check if all courses can be completed, but also to return a valid order of taking the courses.

Use Topological Sort (Kahn's Algorithm) to process courses whose prerequisites are already satisfied.

Start with all courses having indegree 0 because they can be taken first.

Whenever a course is processed, add it to the answer and reduce the indegree of its dependent courses.

If a dependent course's indegree becomes 0, it is now ready to be taken, so add it to the queue.

The order in which courses are processed forms a valid course schedule.

If all courses are included in the topological order, return the order; otherwise, a cycle exists, so return an empty array.

Interview One-Liner  : I use Kahn's Topological Sort to build a valid course order. If all courses are processed, the topological order is the answer; otherwise, a cycle exists and no valid ordering is possible. 🚀

#### C O D E ( kahn's algo )
```cpp
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int>indeg(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(auto j:adj[i]){
                indeg[j]++;
            }
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int>topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }

        }
      if(topo.size() == numCourses)  return topo;
      return {};
    }

```

