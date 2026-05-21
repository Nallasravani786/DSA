#### I M A G E
<img width="2850" height="1505" alt="image" src="https://github.com/user-attachments/assets/d00bffcb-a66e-41f0-8606-5179844c3860" />

#### I N T U I T I O N
Treat digits 0 to 9 as graph nodes.

From every digit, knight can move only to some fixed digits.

At every step:  try all possible knight moves.

DP state: f(digit, len) = number of valid numbers starting from digit with remaining length len.

Base case: if len == 1, current digit itself forms one valid number.

Transition: move to all neighboring digits and add answers.

Use memoization because same (digit, len) states repeat many times.

Final answer: start from every digit 0 to 9 and add all possibilities.


###### C O D E

```cpp
 int mod = 1e9 + 7;

     int f(int digit,int len,vector<vector<int>>&dp,vector<vector<int>>&moves){

        if(len == 1) return 1;

        if(dp[digit][len]!=-1)  return dp[digit][len];

        long long ans = 0;
        for(auto nextdig : moves[digit]){

            ans = (ans + f(nextdig,len-1,dp,moves))%mod;
                        }
            return dp[digit][len] = ans;

            }

    int knightDialer(int n) {
        
        vector<vector<int>>dp(10,vector<int>(n+1,-1));

        vector<vector<int>>moves = {
            {4,6},{6,8},{7,9},{4,8},{0,3,9},{},{0,1,7},{2,6},{1,3},{2,4}
        };

       long long val = 0;

       for(int i=0;i<=9;i++){

        val =(val + f(i,n,dp,moves))%mod;
       }
       return val;
    }


```
