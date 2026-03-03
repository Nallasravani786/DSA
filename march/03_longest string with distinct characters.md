
### I N T U I T I O N 
Expand and Count: The right pointer (r) moves forward, adding the current character to your frequency hash.

Identify the Conflict: If the count of the character at s[r] becomes greater than 1, you have a duplicate in your current window.

Shrink to Resolve: You move the left pointer (l) forward, decrementing counts in the hash until you've removed the earlier occurrence of that duplicate character.

Update Global Max: Once the window is "unique" again, you calculate its length ($r - l + 1$) and update maxlen.


###### C O D E 

```cpp
int longestUniqueSubstr(string &s) {
       int n = s.size();
       unordered_map<char,int>hash;
       int l=0,r=0,maxlen =0;
       for(int r=0;r<n;r++){
           hash[s[r]]++;
       
           while(hash[s[r]]>1){
               hash[s[l]]--;
               l++;
           }
               maxlen = max(maxlen, r-l+1);
       }
       return maxlen;
    
    }


```
