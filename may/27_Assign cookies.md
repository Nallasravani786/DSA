#### I M A G E
<img width="2799" height="1357" alt="image" src="https://github.com/user-attachments/assets/6a9f5f37-0a49-4612-87cc-2564f2f195a6" />

#### I N T U I T I O N
Sort both children greed values and cookie sizes.

Try to satisfy the least greedy child first.

Give the smallest possible cookie that can satisfy that child.

If cookie size ≥ child greed → child becomes satisfied, move to next child.

Otherwise, try a bigger cookie.

Greedy works because using a bigger cookie on a smaller greed child may waste cookies needed for others

###### C O D E
```cpp
 int findContentChildren(vector<int>& g, vector<int>& s) {
       int n = s.size();
       int m = g.size();

       sort(g.begin(),g.end());
       sort(s.begin(),s.end());

       int cnt = 0;

       for(int i=0;i<n;i++){
        if(g[cnt] <= s[i]){
            cnt++;
            if(cnt == g.size()) break; }
         }
       return cnt; 
    }

```
