<img width="2824" height="1300" alt="image" src="https://github.com/user-attachments/assets/63c6392c-fc20-4cb1-8eef-339c423553eb" />

### I N T U I T I O N 

We use a sliding window to find the smallest substring of s that contains all characters of p.

pfreq stores required frequencies of characters in p, and sfreq tracks frequencies inside the current window.

Expand the window (r) and increase cnt whenever we add a needed character (not exceeding required frequency).

When cnt == m, the window contains all characters of p, so we try shrinking from the left (l) to make it the minimum window.

During shrinking, if removing a character makes the window invalid, decrease cnt and stop shrinking.

Track the smallest valid window length and starting index to return the answer


###### C O D E 

```cpp
string minWindow(string &s, string &p) {
        int n = s.size();
        int m = p.size();
        if(m>n) return "";
        unordered_map<char,int>pfreq,sfreq;
        for(auto &c: p) pfreq[c]++;
        int l =0,r=0;
        int cnt =0;
        int st_idx = -1;
        int min_len = INT_MAX;
        while(r<n){
            sfreq[s[r]]++;
            
            if(pfreq[s[r]]!=0 && sfreq[s[r]]<=pfreq[s[r]]){
                cnt++;
            }
            
            while(cnt ==m){
                if(r-l+1 < min_len) {
                    min_len = r-l+1;
                    st_idx = l;
                }
                sfreq[s[l]]--;
                
                if(pfreq[s[l]]!=0 && sfreq[s[l]]<pfreq[s[l]]) cnt--;
                l++;
            }
            r++;
            
        }
        if(st_idx == -1) return "";
        return s.substr(st_idx,min_len);
    }

```
