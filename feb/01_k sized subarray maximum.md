## I N T U T I O N
First, compute the maximum of the first window of size k and store it.

Now start sliding the window one step to the right (i moves out, j comes in).

Case 1: If the new element arr[j] is greater than current max, update maxi directly.

Case 2: If the element leaving the window (arr[i-1]) was the max, then the max might be lost → recompute max for the current window.

Case 3: Otherwise, the current max is still valid → do nothing.

After each slide, store the current maxi in the answer.

```cpp
vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        int n =arr.size();
        vector<int>ans;
        
        int maxi = arr[0];
        
        for(int i=1;i<k;i++){
            maxi = max(maxi,arr[i]);
        }
        ans.push_back(maxi);
        int i=1;
        int j = k;
        
        while(j<n){
            if(arr[j]>maxi) maxi = arr[j];
            
            else if(arr[i-1] == maxi){
                maxi = arr[i];
                for(int x=i;x<=j;x++){
                    maxi = max(maxi,arr[x]);
                }
            }
            ans.push_back(maxi);
            i++;
            j++;
        }
        return ans;
        
    }
```
