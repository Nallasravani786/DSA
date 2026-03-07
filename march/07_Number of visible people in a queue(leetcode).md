<img width="2803" height="1251" alt="image" src="https://github.com/user-attachments/assets/37f47d87-6444-475a-aa41-0ac6f157c8ba" />

####     I N T U I T I O N

We traverse the queue from right to left and use a monotonic stack to track people to the right.

If the current person is taller than people in the stack, they can see them, so we count them and pop them (since shorter people won't block the view).

After popping all shorter people, if the stack is not empty, the current person can still see one more taller person (who blocks further view).

We store this count in ans[i] and then push the current height into the stack for future comparisons.

###### C O D E 

```cpp
 vector<int> canSeePersonsCount(vector<int>& heights) {
      int n = heights.size();
     vector<int>ans(n,0);
     stack<int>st;
      for(int i=n-1;i>=0;i--){
        int cnt =0;

        while(!st.empty() && heights[i] > st.top()){
            cnt++;
            st.pop();
        }

        if(!st.empty()) cnt++;

        ans[i] = cnt ;
        st.push(heights[i]);
      } 
      return ans; 
    }
```
