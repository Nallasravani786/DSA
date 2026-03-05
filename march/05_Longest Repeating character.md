<img width="2821" height="1425" alt="image" src="https://github.com/user-attachments/assets/311570df-6d6f-457c-8b12-02cf69323562" />

### I N T U I T I O N 
Use a sliding window to keep a substring where we can convert at most k characters to make all characters the same.

Track the frequency of characters in the window and maintain max_freq = count of the most frequent character.

The number of replacements needed is window size − max_freq (change all other characters to the most frequent one).

If this value exceeds k, shrink the window from the left.

Keep updating the maximum valid window length, which is the answer.


###### C O D E 

```cpp
int characterReplacement(string s, int k) {
     int n = s.length();
     unordered_map<char,int>hash;
     int l=0,r=0,max_freq=0,maxi =0;
     for(int r=0;r<n;r++){
        hash[s[r]]++;
        max_freq =max(max_freq,hash[s[r]]);


        while((r-l+1 - max_freq)>k){
            hash[s[l]]--;
            l++;
        }
        maxi = max(maxi,r-l+1);
     }  
     return maxi; 
    }

```
