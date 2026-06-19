#### I M A G E
<img width="2782" height="1262" alt="image" src="https://github.com/user-attachments/assets/a8f03af9-86cf-4e51-b277-1ace73408865" />

#### I N T U I T I O N 

Compare adjacent words.

Find the first differing character.

If a != b, then a must come before b in the alien alphabet.

Build a graph of character ordering constraints.

Run Kahn's Topological Sort.

If all characters are included in the topo order, return it; otherwise return "" (cycle/invalid order). 🚀


###### C O D E 

```cpp
class Solution {
public:
    string findOrder(vector<string> &words) {

        unordered_set<char> chars;

        // Collect all unique characters
        for(auto &word : words){
            for(char ch : word){
                chars.insert(ch);
            }
        }
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indeg;

        for(char ch : chars){
            indeg[ch] = 0;
        }

        // Build graph
        for(int i = 0; i < words.size() - 1; i++){

            string s1 = words[i];
            string s2 = words[i + 1];

            int len = min(s1.size(), s2.size());
            bool found = false;

            for(int j = 0; j < len; j++){

                if(s1[j] != s2[j]){

                    adj[s1[j]].push_back(s2[j]);
                    indeg[s2[j]]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: ["abc","ab"]
            if(!found && s1.size() > s2.size()){
                return "";
            }
        }

        queue<char> q;

        for(auto &it : indeg){
            if(it.second == 0){
                q.push(it.first);
            }
        }

        string topo = "";

        while(!q.empty()){

            char node = q.front();
            q.pop();

            topo += node;

            for(char neigh : adj[node]){

                indeg[neigh]--;

                if(indeg[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        // Cycle check
        if(topo.size() != chars.size()){
            return "";
        }

        return topo;
    }
};

```



















