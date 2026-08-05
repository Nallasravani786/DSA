vector<int> findShortestPathsWithConstraints(int n, int m, vector<vector<int>>& ed, int x, int src) {

    int mx = max(n, x);
    for (auto &e : ed)
        mx = max(mx, max(e[0], e[1]));

    vector<vector<pair<int,int>>> g(mx + 1);

    for (auto &e : ed) {
        int u = e[0], v = e[1];
        int c = (u == x || v == x) ? 0 : 1;

        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }

    vector<int> d(mx + 1, -1);
    deque<int> q;

    d[src] = 0;
    q.push_back(src);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (auto &it : g[u]) {
            int v = it.first;
            int w = it.second;

            if (d[v] == -1 || d[v] > d[u] + w) {
                d[v] = d[u] + w;

                if (w == 0)
                    q.push_front(v);
                else
                    q.push_back(v);
            }
        }
    }

    vector<int> res(n);
    bool z = (src == 0);

    for (int i = 0; i < n; i++) {
        int id = z ? i : i + 1;
        res[i] = (id <= mx) ? d[id] : -1;
    }

    return res;
}
