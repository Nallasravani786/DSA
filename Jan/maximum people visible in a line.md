Intuition:
For each index, find how far it can extend left and right while remaining the maximum.

Use a monotonic decreasing stack to stop at the nearest greater element on both sides.

res1[i] gives left span, res2[i] gives right span.

Total length is res1[i] + res2[i] − 1; return the maximum of these.

```cpp
int maxPeople(vector<int> &arr) {
       int n = arr.size();
       vector<int>res1(n);
       vector<int>res2(n);
       stack<int>st;
       stack<int>st2;
       for(int i=0;i<n;i++){
           
           while(!st.empty() && arr[st.top()]<arr[i]){
               st.pop();
           }
           
           res1[i]= st.empty() ? (i+1) : i- st.top();
           st.push(i);
       }
        
         for(int i=n-1;i>=0;i--){
           
           while(!st2.empty() && arr[st2.top()]<arr[i]){
               st2.pop();
           }
           
           res2[i]= st2.empty() ? (n-i) : st2.top()-i;
           st2.push(i);
       }
        
        vector<int>ans(n);
        int maxi =0;
        for(int i=0;i<n;i++)
        { ans[i] = res1[i] +res2[i] -1;
          maxi = max(maxi,ans[i]);}
        
       return maxi;
    }
```
