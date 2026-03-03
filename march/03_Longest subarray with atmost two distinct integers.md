### I N T U I T I O N

Expand the Window: You use a right pointer (r) to include new elements into your "basket" (the hash map).

Check Constraints: If the number of distinct elements in the map exceeds 2, the window is invalid.

Shrink the Window: You move the left pointer (l) forward, removing elements until only 2 distinct types remain.

Capture the Max: Throughout the process, you keep track of the largest window size (r - l + 1) encountered

###### C O D E

```cpp
int totalElements(vector<int> &arr) {
       int n = arr.size();
       
       unordered_map<int,int>hash;
       int l=0;
       int maxlen =0;
       
       for(int r=0;r<n;r++){
           hash[arr[r]]++;
           
           while(hash.size() > 2){
               hash[arr[l]]--;
               
               if(hash[arr[l]]==0){
                   hash.erase(arr[l]);
               }
               l++;
           }
           maxlen = max(maxlen, r-l+1);
       }
       return maxlen;
        
    }


```
