### I M A G E

<img width="2022" height="1219" alt="image" src="https://github.com/user-attachments/assets/4e877252-dbe9-482e-8fef-67d92f1af585" />

### I N T U I T I O N 

<img width="1349" height="1069" alt="image" src="https://github.com/user-attachments/assets/3e018d47-73e2-4dde-94d3-dbe9a00b48cb" />

### Logic: Contribution Technique (O(N))
- **Core Concept:** Instead of iterating over subarrays, iterate over elements to find their 'range of minimum-ness'.
- **Range Determination:**
  - `left_distance[i]`: Distance to the previous element strictly smaller than `arr[i]`.
  - `right_distance[i]`: Distance to the next element smaller than (or equal to, to avoid duplicates) `arr[i]`.
- **Contribution Formula:** Total contribution of `arr[i]` to the sum is `arr[i] * left_distance[i] * right_distance[i]`.
- **Implementation:** Use a Monotonic Stack to efficiently find these distances in linear time.
- **Modulo:** Remember to take modulo $10^9 + 7$ as the total sum can exceed integer limits.

```cpp
  class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        long long MOD = 1e9 + 7;
        vector<int> left(n), right(n);
        stack<int> s;

        // 1. Previous Smaller Element (Left)
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            left[i] = s.empty() ? i + 1 : i - s.top();
            s.push(i);
        }

        while (!s.empty()) s.pop(); // Clear stack

        // 2. Next Smaller Element (Right)
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) s.pop();
            right[i] = s.empty() ? n - i : s.top() - i;
            s.push(i);
        }

        // 3. Calculate Total Sum
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }

        return (int)ans;
    }
};

```
