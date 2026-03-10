<img width="2788" height="1281" alt="image" src="https://github.com/user-attachments/assets/43431332-65a3-412b-a5fb-4e577dd47fd6" />

### I N T U I T I O N 
We find the Next Smaller Element (NSE) for every index using a monotonic increasing stack.

nse[i] tells the first index to the right where value becomes smaller than arr[i].

This means from i to nse[i]-1, arr[i] remains the minimum element.

So the number of valid subarrays starting at i is nse[i] - i.

Add this for all i to get the total count of subarrays where arr[i] stays the minimum until a smaller element appears.

###### C O D E 
```cpp
int countSubarrays(vector<int> &arr) {
       int n = arr.size();
       stack<int>st;
       vector<int>nse(n,n);
       
       for(int i=0;i<n;i++){
           
           while(!st.empty() && arr[st.top()]>arr[i]){
              nse[st.top()] = i;
              st.pop();
           }
           st.push(i);
       }
       
       int ans =0;
       
       for(int i=0;i<n;i++){
           ans+= nse[i]-i;
       }
        return ans;
    }

```
