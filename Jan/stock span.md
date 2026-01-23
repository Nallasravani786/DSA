Intuition:
We need the number of consecutive days (including today) with price ≤ today’s price.

Use a stack to keep indices of higher prices on the left (monotonic decreasing).

Pop all previous prices that are ≤ current price since they don’t block the span.

Span is i+1 if stack is empty, else i - st.top().

```cpp
 vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        
        stack <int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            
            while(!st.empty()  && arr[st.top()] <= arr[i] ){
                st.pop();
            }
            
            ans[i]  = st.empty() ? i+1 : i - st.top();
            st.push(i);
            
        }
        return ans;
        
    }
```
