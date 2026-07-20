#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

// Structured state to track path exploration precisely
struct State {
    int r, c, safety, len;
    
    // Custom operator for the max-heap priority queue
    // Prioritizes HIGHEST safety strength, then FEWEST blocks visited
    bool operator<(const State& other) const {
        if (safety != other.safety) {
            return safety < other.safety;
        }
        return len > other.len;
    }
};

vector<int> findOptimalPair(int n, int m, vector<vector<int>> blockedPositions) {
    // 1. Multi-source BFS initialization for clearance distances
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;
    
    for (const auto& pos : blockedPositions) {
        int r = pos[0] - 1;
        int c = pos[1] - 1;
        if (r >= 0 && r < n && c >= 0 && c < m) {
            dist[r][c] = 0;
            q.push({r, c});
        }
    }
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    // Compute Manhattan clearance from every restricted block efficiently
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == 1e9) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    // Immediate early exit if start or end is strictly blocked
    if (dist[0][0] == 0 || dist[n - 1][m - 1] == 0) {
        return {-1, -1};
    }
    
    // 2. Dijkstra optimization matrix trackers
    vector<vector<int>> max_safety(n, vector<int>(m, -1));
    vector<vector<int>> min_len(n, vector<int>(m, 1e9));
    
    priority_queue<State> pq;
    max_safety[0][0] = dist[0][0];
    min_len[0][0] = 1;
    pq.push({0, 0, dist[0][0], 1});
    
    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();
        
        int r = curr.r;
        int c = curr.c;
        int s = curr.safety;
        int l = curr.len;
        
        // Skip stale states if a more optimal path has already processed this block
        if (s < max_safety[r][c] || (s == max_safety[r][c] && l > min_len[r][c])) {
            continue;
        }
        
        // Due to the priority total ordering, the first time the destination is popped,
        // it is guaranteed to be the global optimal route.
        if (r == n - 1 && c == m - 1) {
            return {s, l};
        }
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // Ensure we do not step onto any completely restricted block (dist > 0)
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] > 0) {
                int ns = min(s, dist[nr][nc]);
                int nl = l + 1;
                
                // Relaxation checks
                if (ns > max_safety[nr][nc]) {
                    max_safety[nr][nc] = ns;
                    min_len[nr][nc] = nl;
                    pq.push({nr, nc, ns, nl});
                } else if (ns == max_safety[nr][nc] && nl < min_len[nr][nc]) {
                    min_len[nr][nc] = nl;
                    pq.push({nr, nc, ns, nl});
                }
            }
        }
    }
    
    return {-1, -1};
}
