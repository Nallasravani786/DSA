
<img width="2825" height="1316" alt="image" src="https://github.com/user-attachments/assets/6dab1308-5c13-45c1-9e1e-d1d30c040c1e" />

### I N T U I T I O N
The string should contain only one continuous block of 1s.

If we ever see the pattern 0 followed by 1, it means a new segment of 1s has started.

That means there are multiple segments of 1s, which is not allowed.

So while scanning the string, if s[i-1] == '0' and s[i] == '1', return false.

If this pattern never appears, the string has at most one segment of 1s, so return true


###### C O D E 
```cpp
bool checkOnesSegment(string s) {
        int n = s.size();
        for(int i=1;i<n;i++){
            if(s[i-1] == '0' && s[i]=='1') return false;
        }
        return true;
    }

```
