#### I M A G E
<img width="2861" height="1508" alt="image" src="https://github.com/user-attachments/assets/e78b8e1a-ad6b-4be7-8068-b90d2b0e4ea3" />

#### I N T U I T I O N

We need to combine both strings into the shortest possible string.

If a character is common in both strings, use it only once.

So, first find the LCS (Longest Common Subsequence), which is the common part.

Then build the answer by keeping common characters once and adding the remaining characters from both strings.

Idea: SCS = merge of both strings using LCS to avoid duplicates.

###### c o d e
```cpp
string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int j=0;j<=m;j++) dp[0][j] = 0;

        for(int i=1;i<=n;i++){

            for(int j=1;j<=m;j++){

                if(str1[i-1] == str2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
        int i=n,j=m;
        string ans = "";
        while(i>0 && j>0) {
            if(str1[i-1] == str2[j-1]) {
                ans += str1[i-1];
                i--; j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                ans += str1[i-1];
                i--;
            }
            else {
                ans += str2[j-1];
        j--;
            }
        }

        while(i>0) {
            ans += str1[i-1];
            i--;
        }
        while(j>0) {
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }

```
