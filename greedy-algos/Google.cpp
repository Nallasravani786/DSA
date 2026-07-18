#include <bits/stdc++.h>
using namespace std;

string minFlagBroadcastCode(int n, string s, int k, long long f) {
    // nxt[i][c] stores the next occurrence of character c at or after index i
    vector<vector<int>> nxt(n + 1, vector<int>(26, -1));
    // cnt[i][c] stores the count of character c from index i to n-1
    vector<vector<int>> cnt(n + 1, vector<int>(26, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nxt[i][c] = nxt[i + 1][c];
            cnt[i][c] = cnt[i + 1][c];
        }
        int cur = s[i] - 'a';
        nxt[i][cur] = i;
        cnt[i][cur]++;
    }

    string res = "";
    long long sum = 0;
    int idx = 0;

    for (int i = 0; i < k; i++) {
        int rem = k - 1 - i;
        
        for (int c = 0; c < 26; c++) {
            int p = nxt[idx][c];
            if (p == -1 || n - 1 - p < rem) continue;

            // Compute maximum possible sum from suffix p + 1
            long long max_suf = 0;
            int take_rem = rem;
            for (int r = 25; r >= 0 && take_rem > 0; r--) {
                int take = min(take_rem, cnt[p + 1][r]);
                max_suf += 1LL * take * (r + 1);
                take_rem -= take;
            }

            // Valid choice if total potential sum >= f
            if (sum + (c + 1) + max_suf >= f) {
                res += (char)('a' + c);
                sum += (c + 1);
                idx = p + 1;
                break;
            }
        }
    }
    return res;
}
