#### I M A G E
<img width="2880" height="1800" alt="image" src="https://github.com/user-attachments/assets/4d180913-80e5-4db4-a0a7-5ea988db9ba1" />

#### I N T U I T I O N
Treat each word as a node in a graph.

Two words are connected if they differ by exactly one character.

We need the shortest transformation sequence from beginWord to endWord.

Whenever a question asks for the shortest path in an unweighted graph, think BFS.

For each word, try changing every character from 'a' to 'z' to generate neighboring words.

If the generated word exists in wordList, push it into the queue.

Remove visited words from the set to avoid revisiting.

The first time we reach endWord, the current level/steps is the answer.

🔥 One-line Idea  : Treat words as graph nodes and use BFS to find the shortest path from beginWord to endWord.

###### C O D E (BFS)
```cpp
 int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
         unordered_set<string>st(wordList.begin(),wordList.end());

         queue<pair<string,int>>q;

         q.push({beginWord,1});

         st.erase(beginWord);

         while(!q.empty()){
            auto [word , steps] = q.front();
            q.pop();

            if(word == endWord) return steps;

            for(int i=0;i<word.size();i++){

                char original = word[i];

                for(char ch = 'a';ch <= 'z';ch++){

                    word[i] = ch;

                    if(st.find(word) != st.end()) {
                        q.push({word , steps+1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
         }
            return 0;
    }

```
