#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Fast DSU to find available slots searching backward
static unordered_map<int, int> parent;

static int get_parent(int x) {
    if (!parent.count(x)) return x;
    return parent[x] = get_parent(parent[x]);
}

int maxTasksScheduled(int N, vector<int> tasks, vector<int> deadline, int cooldown) {
    parent.clear();

    // Group tasks into pairs: {deadline, task_id}
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; i++) {
        items[i] = {deadline[i], tasks[i]};
    }

    // Sort descending by deadline to place items at their latest possible valid slot
    sort(items.rbegin(), items.rend());

    unordered_map<int, int> next_allowed;
    int count = 0;

    for (int i = 0; i < N; i++) {
        int d = items[i].first;
        int id = items[i].second;

        // Determine max position this task can take
        int max_pos = d;
        if (next_allowed.count(id)) {
            max_pos = min(max_pos, next_allowed[id]);
        }

        // Find available slot <= max_pos using DSU
        int slot = get_parent(max_pos);

        if (slot >= 1) {
            count++;
            // Union current slot with slot - 1
            parent[slot] = get_parent(slot - 1);
            // Update upper bound for this task ID considering cooldown
            next_allowed[id] = slot - cooldown - 1;
        }
    }

    return count;
}
