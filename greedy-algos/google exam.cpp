//Q1 - 
long long minMaxConvoyLoad(int n, int k, long long escort, int maxCrates, vector<long long> weights) {
    long long low = 0, high = escort;
    for (long long w : weights) {
        low = max(low, w + escort);
        high += w;
    }
    
    long long ans = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        int trucks = 1, cnt = 0;
        long long sum = 0;
        
        for (long long w : weights) {
            if (sum + w + escort <= mid && cnt < maxCrates) {
                sum += w;
                cnt++;
            } else {
                trucks++;
                sum = w;
                cnt = 1;
            }
        }
        
        if (trucks <= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

//========================================================================================================//
//========================================================================================================//


/// Q2 - max xor pair value
struct Node {
    int child[2] = {0};
};

long long maxXorPairValue(int n, vector<long long> a) {
    vector<Node> trie;
    trie.reserve(n * 31);
    trie.push_back(Node()); // Root at index 0

    auto insert = [&](long long num) {
        int curr = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!trie[curr].child[bit]) {
                trie[curr].child[bit] = trie.size();
                trie.push_back(Node());
            }
            curr = trie[curr].child[bit];
        }
    };

    auto query = [&](long long num) {
        int curr = 0;
        long long res = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (trie[curr].child[1 - bit]) {
                res |= (1LL << i);
                curr = trie[curr].child[1 - bit];
            } else if (trie[curr].child[bit]) {
                curr = trie[curr].child[bit];
            } else {
                break;
            }
        }
        return res;
    };

    long long max_xor = 0;
    insert(a[0]);
    for (int i = 1; i < n; i++) {
        max_xor = max(max_xor, query(a[i]));
        insert(a[i]);
    }

    return max_xor;
}
