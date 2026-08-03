int* rotationFun(int x, int arr[], int m, int n, int r) {
    int *res = new int[x];
    
    // Copy array to 2D matrix
    vector<vector<int>> g(m, vector<int>(n));
    int p = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            g[i][j] = arr[p++];
        }
    }

    int numRings = min(m, n) / 2;

    for(int ring = 0; ring < numRings; ring++) {
        int r1 = ring, c1 = ring;
        int r2 = m - 1 - ring, c2 = n - 1 - ring;

        // Collect ring coordinates in clockwise order
        vector<pair<int,int>> pos;
        
        // Top edge
        for(int j = c1; j <= c2; j++) pos.push_back({r1, j});
        // Right edge
        for(int i = r1 + 1; i <= r2 - 1; i++) pos.push_back({i, c2});
        // Bottom edge
        if(r1 < r2) {
            for(int j = c2; j >= c1; j--) pos.push_back({r2, j});
        }
        // Left edge
        if(c1 < c2) {
            for(int i = r2 - 1; i >= r1 + 1; i--) pos.push_back({i, c1});
        }

        int len = pos.size();
        if(len == 0) continue;

        // Store original ring values
        vector<int> vals(len);
        for(int k = 0; k < len; k++) {
            vals[k] = g[pos[k].first][pos[k].second];
        }

        // Shift values anti-clockwise by r steps
        int shift = r % len;
        for(int k = 0; k < len; k++) {
            auto [row, col] = pos[k];
            g[row][col] = vals[(k + shift) % len];
        }
    }

    // Flatten grid back to 1D
    p = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            res[p++] = g[i][j];
        }
    }

    return res;
}
