## I N T U T I O N ##
The letters array is sorted.

We scan from left to right to find the first letter strictly greater than target.

As soon as we find such a letter, we store it and break (because it’s the smallest possible greater one).

If no letter is greater than target, we return the first letter (wrap-around case).

ans is initialized with letters[0] to handle this wrap-around naturally.

```cpp
 char nextGreatestLetter(vector<char>& letters, char target) {
        int n  = letters.size();
        char ans=letters[0];
        for(int i=0;i<n;i++){
            if(letters[i]-'0'> target-'0' ){
                ans = letters[i];
                break;
                
            }
            
        }
        return ans;
    }
```
