#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> findOptimalPair(int n, int m, vector<vector<int>> blockedPositions) {
    // 1-based to 0-based coordinates mapping
    // safety grid stores clearance distance from any blocked cell
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    queue<pair<int, int>> q;
    
    for (auto& pos : blockedPositions) {
        int r = pos[0] - 1;
        int c = pos[1] - 1;
        if (r >= 0 && r < n && c >= 0 && c < m) {
            dist[r][c] = 0;
            q.push({r, c});
        }
    }
    
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    // Multi-source BFS to calculate Manhattan distances efficiently
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == 1e9) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }
    
    // Check if start or end is blocked
    if (dist[0][0] == 0 || dist[n - 1][m - 1] == 0) return {-1, -1};
    
    // max_safety[r][c] stores max possible safety value to reach (r, c)
    // min_len[r][c] stores min path length for that max safety
    vector<vector<int>> max_safety(n, vector<int>(m, -1));
    vector<vector<int>> min_len(n, vector<int>(m, 1e9));
    
    // Dijkstra priority queue element: {safety_strength, -path_length, r, c}
    priority_queue<vector<int>> pq;
    
    max_safety[0][0] = dist[0][0];
    min_len[0][0] = 1;
    pq.push({dist[0][0], -1, 0, 0});
    
    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        int s = curr[0];
        int l = -curr[1];
        int r = curr[2];
        int c = curr[3];
        
        if (s < max_safety[r][c] || (s == max_safety[r][c] && l > min_len[r][c])) continue;
        if (r == n - 1 && c == m - 1) break;
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] > 0) {
                int ns = min(s, dist[nr][nc]);
                int nl = l + 1;
                
                if (ns > max_safety[nr][nc]) {
                    max_safety[nr][nc] = ns;
                    min_len[nr][nc] = nl;
                    pq.push({ns, -nl, nr, nc});
                } else if (ns == max_safety[nr][nc] && nl < min_len[nr][nc]) {
                    min_len[nr][nc] = nl;
                    pq.push({ns, -nl, nr, nc});
                }
            }
        }
    }
    
    if (max_safety[n - 1][m - 1] == -1) return {-1, -1};
    return {max_safety[n - 1][m - 1], min_len[n - 1][m - 1]};
}
