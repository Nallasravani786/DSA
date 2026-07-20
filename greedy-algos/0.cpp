#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int global_max_dist;

int dfs(int curr, int prev, const vector<vector<int>>& adj_list) {
    int max1 = 0, max2 = 0;
    
    for (int nbr : adj_list[curr]) {
        if (nbr == prev) continue;
        
        int branch_len = 1 + dfs(nbr, curr, adj_list);
        if (branch_len > max1) {
            max2 = max1;
            max1 = branch_len;
        } else if (branch_len > max2) {
            max2 = branch_len;
        }
    }
    
    global_max_dist = max(global_max_dist, max1 + max2);
    return max1;
}

int calculateMax(int network_nodes, vector<int> network_from, vector<int> network_to, vector<int> compatibility) {
    global_max_dist = 0;
    vector<vector<int>> adj_list(network_nodes + 1);
    
    int num_edges = network_from.size();
    for (int i = 0; i < num_edges; ++i) {
        int u = network_from[i];
        int v = network_to[i];
        
        if (abs(compatibility[u - 1] - compatibility[v - 1]) <= 1) {
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
    }
    
    vector<bool> visited(network_nodes + 1, false);
    for (int i = 1; i <= network_nodes; ++i) {
        if (!visited[i]) {
            // Re-use standard tree traversal to find components and marks visited nodes
            auto mark_visited = [&](auto& self, int curr, int prev) -> void {
                visited[curr] = true;
                for (int nbr : adj_list[curr]) {
                    if (nbr != prev) {
                        self(self, nbr, curr);
                    }
                }
            };
            mark_visited(mark_visited, i, 0);
            dfs(i, 0, adj_list);
        }
    }
    
    return global_max_dist;
}
