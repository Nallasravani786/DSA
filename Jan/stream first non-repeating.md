## I N T U T I O N ##
Intuition (Stream First Non-Repeating Character)

We read characters one by one, like a live stream.

Keep a frequency count to know how many times each character appears.

Keep a queue to maintain the order of characters as they arrive.

When a character’s frequency becomes more than 1, it cannot be non-repeating, so remove it from the front of the queue.

At any moment, the front of the queue is the first non-repeating character; if the queue is empty, output #.

```cpp
class Solution {
public:
    string firstNonRepeating(string &s) {
        unordered_map<char, int> freq;
        queue<char> q;
        string ans = "";

        for (char ch : s) {
            // step 1: update frequency
            freq[ch]++;

            // step 2: push into queue
            q.push(ch);

            // step 3: remove repeating characters from front
            while (!q.empty() && freq[q.front()] > 1) {
                q.pop();
            }

            // step 4: decide answer
            if (q.empty())
                ans += '#';
            else
                ans += q.front();
        }
        return ans;
    }
};


```
