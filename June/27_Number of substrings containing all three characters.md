#### I M A G E

<img width="2840" height="1396" alt="image" src="https://github.com/user-attachments/assets/dd86698b-0131-44a7-99d5-3ebebf287580" />

#### I N T U I T I O N
We need to count substrings containing all three characters: 'a', 'b', and 'c'.

Use a sliding window to maintain the current substring.

Expand the window by moving the right pointer until it contains all 3 characters.

Once the window is valid, every substring obtained by extending the right end is also valid.

So, add n - r to the answer instead of counting each substring individually.

Shrink the window from the left to find the next valid starting position.

Repeat until the entire string is processed.

Key Observation : If the current window contains 'a', 'b', and 'c', then all larger windows ending after r will also contain them. Therefore, add n - r to the answer.

###### C O D E  
```cpp
 int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int>hash;
        int l = 0,cnt = 0;

        for(int r=0;r<n;r++){
            hash[s[r]]++;

            while(hash.size() == 3){
                cnt += (n-r);
                hash[s[l]]--;
                if(hash[s[l]]==0) hash.erase(s[l]);
                l++;
            }  
        }
        return cnt;
    }
```


