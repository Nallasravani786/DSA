## I N T U I T I O N
We want to buy at the lowest price before selling at a higher price later.

mini keeps track of the minimum price seen so far (best day to buy).

For each day i, we assume we sell on day i and compute profit = prices[i] - mini.

maxprof stores the maximum profit found till now.

After checking profit, we update mini so future days can use a better (smaller) buying price.

👉 In short: keep the cheapest buy price so far and try selling every day to get the best profit in one pass.

##### T.C :O(n)  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  S.C : O(1)

```cpp
int maxProfit(vector<int> &prices) {
       int n = prices.size();
       int maxprof =0;
       int mini = prices[0];
       
       for(int i=1;i<n;i++){
           int cost = prices[i]-mini;
           maxprof = max(maxprof,cost);
           mini = min(mini,prices[i]);
       }
       return maxprof;
    }

```
