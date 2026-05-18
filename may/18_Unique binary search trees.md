#### I M A G E
<img width="2856" height="1330" alt="image" src="https://github.com/user-attachments/assets/573a634c-026c-46db-a0af-f78b658d20bf" />

#### I N T U I T I O N

Try every node as the root of the BST.

Nodes smaller than the root go to the left subtree.

Nodes greater than the root go to the right subtree.

Number of BSTs for one root = (ways to form left subtree) × (ways to form right subtree).

Add the answers for all possible roots.

Same subtree sizes are calculated repeatedly, so use DP/memoization

###### C O D E
```cpp
int f(int n, vector<int>&dp){
        if(n<=1) return 1;

        if(dp[n]!=-1) return dp[n];
        int ans =0;

        for(int root = 1; root<=n;root++){
            int leftroot = root-1;
            int rightroot = n-root;

            int leftways = f(leftroot,dp);
            int rightways = f(rightroot,dp);

            ans+= leftways*rightways;
        }
        return dp[n] = ans;
    }

    int numTrees(int n) {
       vector<int>dp(n+1,-1);
       return f(n,dp); 
    }

```
