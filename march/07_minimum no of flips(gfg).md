<img width="2773" height="1286" alt="image" src="https://github.com/user-attachments/assets/171871e4-c554-4469-8428-dc3e2ace46f2" />

### I N T U I T I O N
An alternating binary string can only have two possible patterns: 101010... or 010101....

So we construct both patterns of length n and compare them with the given string s.

For each pattern, we count how many positions are different (those bits must be flipped).

The minimum of the two mismatch counts gives the minimum number of flips needed

###### C O D E 
```cpp
int minFlips(string& s) {
        int n = s.size();
        string p1="",p2 = "";
        for(int i=0;i<n;i++){
           p1+=(i%2 ==1) ? '0' : '1';
           p2+=(i%2 == 1) ? '1': '0';
           
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(p1[i]!=s[i]) cnt1++;
            if(p2[i]!=s[i]) cnt2++;
        }
        return min(cnt1,cnt2);
    }

```

