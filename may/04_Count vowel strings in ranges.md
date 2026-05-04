#### I M A G E 
<img width="2851" height="1438" alt="image" src="https://github.com/user-attachments/assets/6dc3095e-25bb-4ec4-81c7-18f0d7558ce9" />

#### I N T U I T I O N 
First, convert each word into 1 or 0 → 1 if it starts & ends with a vowel, else 0.
Then build a prefix sum array where each index stores total valid words till that point.
Now, instead of looping for every query, you directly compute the count using:
pref[r] - pref[l-1]
So each query becomes O(1) instead of O(n).

👉 In short:
Precompute once → reuse results → avoid repeated work

```cpp
int isend(string &s){
    int n = s.size();
    
    if((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0]=='u') &&
    (s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1]=='u')) return 1;
    return 0; 
  }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>pref(n,0);
        pref[0] = isend(words[0]);
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + isend(words[i]);
        }
        vector<int>ans;
        for(auto &q: queries){
            int l = q[0];
            int r = q[1];
            
            if(l == 0) ans.push_back(pref[r]);
            else ans.push_back(pref[r] - pref[l-1]);
        }
        return ans;

    }
```
