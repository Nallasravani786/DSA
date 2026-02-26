#### I N T U I T I O N
Two strings are isomorphic if:

Every character in s1 can be replaced to get s2

The order remains same

One character maps to only one character

No two different characters map to the same character

###### C O D E
```cpp
 bool areIsomorphic(string &s1, string &s2) {
        if(s1.length()!=s2.length()) return false;
        int m1[256] = {0}, m2[256] = {0};
        for(int i=0;i<s1.length();i++){
            if(m1[s1[i]] != m2[s2[i]]) return false;
            
            m1[s1[i]]=i+1;
            m2[s2[i]]=i+1;
        }
        return true;
        
    }

```
