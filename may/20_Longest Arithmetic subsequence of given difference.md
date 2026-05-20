#### I M A G  E
<img width="2839" height="1333" alt="image" src="https://github.com/user-attachments/assets/49548625-7ddb-4a8e-9afb-38861c8cee17" />

#### I N T U I T I O N

We need longest subsequence having same fixed difference.

For every current number x, previous needed number is: x - difference.

If that previous number already exists in a subsequence,

we can extend that subsequence.

Use hashmap: mp[x] = longest subsequence ending at x.

Formula: mp[x] = 1 + mp[x-difference]

If previous value not present, start new subsequence with length 1.

Final answer is maximum value in hashmap.

###### C O D E
```cpp
 int longestSubsequence(vector<int>& arr, int difference) {
        
        int n = arr.size();

        unordered_map<int,int>mp;

        int maxi = 1;
        for(int x: arr){

             mp[x] = 1+ mp[x-difference]

             maxi = max(mp[x],maxi);
            
        }
        return maxi;
    }

```
