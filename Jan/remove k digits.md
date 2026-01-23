## I N T U I T I O N ##
We want the smallest possible number after removing k digits.

Maintain a stack-like string and remove previous digits that are bigger than the current digit.

If removals are still left, delete digits from the end (largest impact).

Remove leading zeros; if nothing remains, return "0".

```cpp
string removeKdig(string &s, int k) {
        string st;
        int n = s.size();
        if(k>=n) return "0";
        for(int i=0;i<n;i++){
            
            while(!st.empty() && k>0 && st.back() > s[i]){
                st.pop_back();
                k--;
            }
            st.push_back(s[i]);
        }
        
        while(k>0 && !st.empty()){
           st.pop_back();
           k--;
        }
        
        int id=0;
       while( id<st.size()  && st[id] =='0') id++;
        string res = st.substr(id);
        return res.empty() ? "0" : res;
    }
```
