###### C O D E
```cpp
 int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int no_del = arr[0];
        int one_del = arr[0];
        int ans = arr[0];
        
        for(int i=1;i<n;i++){ 
            one_del = max(no_del,one_del+arr[i]);
            no_del = max(arr[i],no_del+arr[i]);
            ans = max({one_del,no_del,ans});
        }
        return ans;
    }

```
