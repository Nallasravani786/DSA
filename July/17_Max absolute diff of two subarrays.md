###### C O D E

```cpp
 int maxDiffSubArrays(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>leftmax(n);
        int curr = arr[0];
        leftmax[0] = arr[0];
        for(int i=1;i<n;i++){
            curr = max(arr[i],curr+arr[i]);
            leftmax[i] = max(leftmax[i-1],curr);
        }
        
        
        vector<int>leftmin(n);
        leftmin[0] = arr[0];
        curr = arr[0];
        for(int i=1;i<n;i++){
            curr = min(arr[i],curr+arr[i]);
            leftmin[i] = min(leftmin[i-1],curr);
        }
        
        vector<int>rightmax(n);
        rightmax[n-1] = arr[n-1];
        curr = arr[n-1];
        for(int i=n-2;i>=0;i--){
            curr = max(arr[i],curr+arr[i]);
            rightmax[i] = max(rightmax[i+1],curr);
        }
        
        vector<int>rightmin(n);
        rightmin[n-1] = arr[n-1];
        curr = arr[n-1];
        for(int i=n-2;i>=0;i--){
            curr = min(curr+arr[i],arr[i]);
            rightmin[i] = min(rightmin[i+1],curr);
        }
        int ans = INT_MIN;
        
        for(int i=0;i<n-1;i++){
            int case1 = abs(rightmax[i+1]-leftmin[i]);
            int case2 = abs(leftmax[i]-rightmin[i+1]);
            ans = max({case1,case2,ans});
            
        }
        return ans; 
    }
```
