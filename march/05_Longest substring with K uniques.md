### I N T U I T I O N 
This code finds the longest substring with exactly k distinct characters using the sliding window technique.

First, it checks if the string even has at least k unique characters; otherwise, return -1.

Then it expands the window (r) and keeps adding characters to a hashmap.

If distinct characters exceed k, it shrinks the window from the left (l) until only k remain.

At every valid step, it updates the maximum length.

So basically: expand to include characters, shrink if too many distinct, and track the longest valid window.

###### C O D E 

```cpp
int longestKSubstr(string &s, int k) {
     int n = s.length();
        //int cnt =0;
        int maxlen =0;
        unordered_map<char,int>hash,hash1;
        for(auto & c: s) hash1[c]++;
        int l=0,r=0;
        
       if(hash1.size()>=k) {   for(int r=0;r<n;r++){
            hash[s[r]]++;
            
            while(hash.size()> k){
                hash[s[l]]--;
               if(hash[s[l]]==0) hash.erase(s[l]);
               l++;
            }
            maxlen = max(maxlen, r-l+1);
            
        }   }
        else return -1;
        return maxlen;
    }

```
