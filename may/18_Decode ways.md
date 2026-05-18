
#### I M A G E
<img width="2839" height="1436" alt="image" src="https://github.com/user-attachments/assets/ad9d4d0d-d500-4018-b83b-2aa98b781c42" />

#### I N T U I T I O N

At every index, we have two choices: take 1 digit  , take 2 digits (if valid).

Single digit is valid only if it is not '0'.

Two digits are valid only if number is between:  10 to 26

Recursively calculate number of ways for remaining string.

Total ways: ways from single digit + ways from double digit

Use DP/memoization to avoid recalculating same indices repeatedly.

###### C O D E

```cpp
int f(int i, string &s, vector<int>&dp){

    if(i == s.size()) return 1;

    if(s[i] == '0') return 0;

    if(dp[i]!=-1) return dp[i];
    int ways = f(i+1,s,dp);


    if(i+1 < s.size() && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
            ways+= f(i+2,s,dp);
    }
      return dp[i] = ways;

   }


    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n,-1);
        return f(0,s,dp);
    }

```
