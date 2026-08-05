#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

int maxTasksScheduled(int N, vector<int> tasks, vector<int> deadline, int cooldown) {
    // Structure for task information
    struct T {
        int id, d;
    };

    vector<T> vec(N);
    for (int i = 0; i < N; i++) {
        vec[i] = {tasks[i], deadline[i]};
    }

    // Sort by deadline ascending
    sort(vec.begin(), vec.end(), [](const T &a, const T &b) {
        return a.d < b.d;
    });

    // Min-heap to pick the task with the smallest deadline among ready tasks
    // pair: {deadline, index_in_vec}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    unordered_map<int, int> last_used;

    int ans = 0;
    int idx = 0;
    int cur_time = 1;

    while (idx < N || !pq.empty()) {
        // Add all tasks that can potentially be scheduled from cur_time onwards
        while (idx < N && vec[idx].d < cur_time) {
            idx++; // Skip tasks whose deadlines are already past
        }

        while (idx < N) {
            pq.push({vec[idx].d, idx});
            idx++;
        }

        if (pq.empty()) break;

        // Try to schedule the task with the tightest deadline
        vector<pair<int, int>> temp;
        bool scheduled = false;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int d = top.first;
            int task_id = vec[top.second].id;

            // Check if cooldown constraint is satisfied at cur_time
            if (!last_used.count(task_id) || cur_time >= last_used[task_id] + cooldown + 1) {
                ans++;
                last_used[task_id] = cur_time;
                cur_time++;
                scheduled = true;
                break;
            } else {
                // Cannot run right now due to cooldown, hold it back
                temp.push_back(top);
            }
        }

        // Put unexecuted tasks back into heap
        for (auto &p : temp) {
            pq.push(p);
        }

        // If no task could be scheduled at cur_time, jump to the next viable time
        if (!scheduled) {
            cur_time++;
        }
    }

    return ans;
}
